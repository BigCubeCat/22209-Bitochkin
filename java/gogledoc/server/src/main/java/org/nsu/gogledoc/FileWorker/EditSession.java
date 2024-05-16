package org.nsu.gogledoc.FileWorker;

import org.nsu.gogledoc.Cmd.Cmd;
import org.nsu.gogledoc.Cmd.CmdType;
import org.nsu.gogledoc.Logger.ServerLoggerFinder;
import org.nsu.gogledoc.Utils.CodeUtil;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.EnumSet;
import java.util.Queue;
import java.nio.file.Files;

public class EditSession {
    private final System.Logger logger = ServerLoggerFinder.getLogger("session", this.getClass().getModule());
    private UserFile userFile;
    private Queue<String> users;
    private FileChannel fileChannel;

    private void createFile() {
        try {
            Files.createFile(this.userFile.getFilePath());
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public EditSession(UserFile userFile) {
        this.userFile = userFile;
        createFile();
        try {
            fileChannel = FileChannel.open(
                    this.userFile.getFilePath(),
                    EnumSet.of(
                            StandardOpenOption.CREATE,
                            StandardOpenOption.WRITE,
                            StandardOpenOption.READ
                    )
            );
        } catch (IOException ioException) {
            logger.log(System.Logger.Level.ERROR, ioException.toString());
        }
    }

    public void ExecuteCmd(Cmd cmd) throws IOException {
        switch (cmd.eType) {
            case CmdType.INSERT -> insert(cmd.content, cmd.cursor);
            case CmdType.DELETE -> delete(cmd.cursor);
            case CmdType.REPLACE -> replace(cmd.content, cmd.cursor, cmd.end);
            default -> logger.log(System.Logger.Level.ERROR, "invalid cmd type: " + cmd.toString());
        }
    }

    private int normalizePosition(int position) throws IOException {
        if (position > fileChannel.size()) {
            return (int) fileChannel.size();
        } else if (position < 0) {
            return 0;
        }
        return position;
    }

    public void insertEnd(String text) throws IOException {
        fileChannel.write(CodeUtil.bufferFromString(text), fileChannel.size());
    }

    public void insert(String text, int position) throws IOException {
        position = normalizePosition(position);
        fileChannel.position(position);
        ByteBuffer endBuff = ByteBuffer.allocate((int) (fileChannel.size() - position));
        fileChannel.read(endBuff);
        fileChannel.truncate(position);
        insertEnd(text);
        insertEnd(CodeUtil.stringFromHeapByteBuffer(endBuff));
    }

    public void replace(String text, int position, int end) throws IOException {
        position = normalizePosition(position);
        fileChannel.position(end);
        ByteBuffer endBuff = ByteBuffer.allocate((int) (fileChannel.size() - end));
        fileChannel.read(endBuff);
        fileChannel.position(position);
        fileChannel.truncate(position);
        insertEnd(text);
        insertEnd(CodeUtil.stringFromHeapByteBuffer(endBuff));

    }

    public void delete(int position) throws IOException {
        fileChannel.truncate(position);
    }
}
