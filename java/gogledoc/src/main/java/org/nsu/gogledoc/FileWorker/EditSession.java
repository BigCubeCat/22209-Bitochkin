package org.nsu.gogledoc.FileWorker;

import org.nsu.gogledoc.Cmd.Cmd;
import org.nsu.gogledoc.Cmd.CmdType;
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
    private UserFile userFile;
    private Queue<String> users;
    private FileChannel fileChannel;

    private void createFile(Path path) {
        try {
            Files.createFile(this.userFile.getFilePath());
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public EditSession(UserFile userFile) {
        this.userFile = userFile;
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
            System.out.println(ioException);
            // TODO: logger
        }
    }

    public void ExecuteCmd(Cmd cmd) throws IOException {
        System.out.println(cmd.eType);
        if (cmd.eType == CmdType.INSERT) {
            // TODO: log and history
            insert(cmd.content, cmd.cursor);
        } else if (cmd.eType == CmdType.DELETE) {
            delete(cmd.cursor);
        }
    }

    private void insertEnd(String text) throws IOException {
        fileChannel.write(CodeUtil.bufferFromString(text), fileChannel.size());
    }

    public void insert(String text, int position) throws IOException {
        if (position > fileChannel.size()) {
            position = (int) fileChannel.size();
        }
        fileChannel.position(position);
        int endSize = (int) (fileChannel.size() - position);
        System.out.println("endSize = " + endSize);
        ByteBuffer end = (ByteBuffer) ByteBuffer.allocate((int)(fileChannel.size() - position));
        System.out.println(fileChannel.read(end));
        System.out.println("end = " + end);
        System.out.println("end = " + CodeUtil.stringFromHeapByteBuffer(end));
        fileChannel.truncate(position);
        insertEnd(text);
        insertEnd(CodeUtil.stringFromHeapByteBuffer(end));
    }

    public void delete(int position) throws IOException {
        fileChannel.truncate(position);
    }
}
