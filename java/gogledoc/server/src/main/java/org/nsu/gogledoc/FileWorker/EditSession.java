package org.nsu.gogledoc.FileWorker;

import org.nsu.gogledoc.Cmd.Cmd;
import org.nsu.gogledoc.Cmd.CmdResponse;
import org.nsu.gogledoc.Cmd.CmdType;
import org.nsu.gogledoc.Logger.ServerLoggerFinder;
import org.nsu.gogledoc.Utils.CodeUtil;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.file.StandardOpenOption;
import java.util.EnumSet;
import java.util.Queue;
import java.nio.file.Files;

public class EditSession {
    private final System.Logger logger = ServerLoggerFinder.getLogger(
            "session",
            this.getClass().getModule()
    );

    private CursorController cursorController = new CursorController();
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

    public CmdResponse ExecuteCmd(Cmd cmd) throws IOException {
        switch (cmd.eType) {
            case CmdType.JUMP -> jumpCursor(cmd);
            case CmdType.INSERT -> insert(cmd);
            case CmdType.DELETE -> delete(cmd);
            case CmdType.REPLACE -> replace(cmd);
            default -> logger.log(System.Logger.Level.ERROR, "invalid cmd type: " + cmd.toString());
        }
        // Создаем Response
        CmdResponse response = new CmdResponse();
        response.state = cursorController.toResponseString();
        logger.log(System.Logger.Level.DEBUG, response.state);
        return response;
    }

    private int normalizePosition(int position) throws IOException {
        if (position > fileChannel.size()) {
            return (int) fileChannel.size();
        } else if (position < 0) {
            return 0;
        }
        return position;
    }

    public void jumpCursor(Cmd cmd) throws IOException {
        cursorController.setUserPos(cmd.user, normalizePosition(cmd.position));
    }

    public void insertEnd(String text) throws IOException {
        fileChannel.write(CodeUtil.bufferFromString(text), fileChannel.size());
    }

    public void insert(Cmd cmd) throws IOException {
        int position = normalizePosition(cursorController.getUserPos(cmd.user));
        fileChannel.position(position);
        ByteBuffer endBuff = ByteBuffer.allocate((int) (fileChannel.size() - position));
        fileChannel.read(endBuff);
        fileChannel.truncate(position);
        insertEnd(cmd.content);
        insertEnd(CodeUtil.stringFromHeapByteBuffer(endBuff));
    }

    public void replace(Cmd cmd) throws IOException {
        int position = normalizePosition(cursorController.getUserPos(cmd.user));
        fileChannel.position(cmd.position);
        ByteBuffer endBuff = ByteBuffer.allocate((int) (fileChannel.size() - cmd.position));
        fileChannel.read(endBuff);
        fileChannel.position(position);
        fileChannel.truncate(position);
        insertEnd(cmd.content);
        insertEnd(CodeUtil.stringFromHeapByteBuffer(endBuff));
    }

    public void delete(Cmd cmd) throws IOException {
        int position = cursorController.getUserPos(cmd.user);
        if (position > 0) {
            fileChannel.truncate(position);
            logger.log(System.Logger.Level.INFO, "truncate");
        } else {
            logger.log(System.Logger.Level.ERROR, "no cursor in delete");
        }
    }
}
