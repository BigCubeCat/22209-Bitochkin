package org.nsu.gogledoc.FileWorker;

import org.nsu.gogledoc.Cmd.Cmd;
import org.nsu.gogledoc.Logger.ServerLoggerFinder;
import org.nsu.gogledoc.Utils.CodeUtil;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.file.Path;
import java.nio.file.Paths;

public class UserFile {
    private final System.Logger logger = ServerLoggerFinder.getLogger(
            "UserFile",
            this.getClass().getModule()
    );

    private final String filePath;
    private String fileContent;
    public int unixtime;
    private FileChannel chan;

    public UserFile(String filePath) {
        this.filePath = filePath;
    }

    public void open(Path path, java.util.Set<? extends java.nio.file.OpenOption> es) throws IOException {
        chan = FileChannel.open(path, es);
    }

    public Path getFilePath() {
        return Paths.get(filePath);
    }

    public int normalizePosition(int position) throws IOException {
        if (position > chan.size()) {
            return (int) chan.size();
        } else if (position < 0) {
            return 0;
        }
        return position;
    }

    public void insertEnd(String text) throws IOException {
        chan.write(CodeUtil.bufferFromString(text), chan.size());
    }

    public void replace(Cmd cmd, int serverPosition) throws IOException {
        serverPosition = normalizePosition(serverPosition);
        if (serverPosition != cmd.begin) {
            cmd.begin -= serverPosition;
            cmd.end -= serverPosition;
        }
        cmd.begin = normalizePosition(cmd.begin);
        cmd.end = normalizePosition(cmd.end);
        logger.log(System.Logger.Level.WARNING, "repplacing: " + cmd.begin + "-" + cmd.end + ": " + cmd.content);
        chan.position(cmd.end);
        ByteBuffer endBuff = ByteBuffer.allocate((int) (chan.size() - cmd.end));
        chan.read(endBuff);
        chan.truncate(cmd.begin);
        insertEnd(cmd.content);
        insertEnd(CodeUtil.stringFromHeapByteBuffer(endBuff));
    }

    private ByteBuffer dumpFileContent() throws IOException {
        logger.log(System.Logger.Level.DEBUG, "reading the file");
        ByteBuffer buffer = ByteBuffer.allocate((int) chan.size());
        chan.position(0);
        chan.read(buffer);
        logger.log(System.Logger.Level.DEBUG, "file has been read");
        return buffer;
    }

    public UserFileMem dump(Cmd cmd) throws IOException {
        logger.log(System.Logger.Level.DEBUG, "dumping");
        UserFileMem mem = new UserFileMem();
        mem.unixtime = cmd.unixtime;
        mem.content = CodeUtil.stringFromHeapByteBuffer(dumpFileContent());
        return mem;
    }
}
