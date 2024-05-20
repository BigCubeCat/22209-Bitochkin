package org.nsu.gogledoc.FileWorker;

import org.nsu.gogledoc.Cmd.Cmd;
import org.nsu.gogledoc.Cmd.CmdResponse;
import org.nsu.gogledoc.Cmd.CmdType;
import org.nsu.gogledoc.Logger.ServerLoggerFinder;

import java.io.IOException;
import java.nio.file.StandardOpenOption;
import java.util.EnumSet;
import java.nio.file.Files;

public class EditSession {
    private final System.Logger logger = ServerLoggerFinder.getLogger(
            "session",
            this.getClass().getModule()
    );

    private CursorController cursorController = new CursorController();
    private UserFile userFile;
    private EditHistory history = new EditHistory(10); // TODO specify size

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
            userFile.open(
                    this.userFile.getFilePath(),
                    EnumSet.of(StandardOpenOption.CREATE, StandardOpenOption.WRITE, StandardOpenOption.READ)
            );
        } catch (IOException ioException) {
            logger.log(System.Logger.Level.ERROR, ioException.toString());
        }
    }

    public CmdResponse ExecuteCmd(Cmd cmd) throws IOException {
        switch (cmd.eType) {
            case CmdType.JUMP -> jumpCursor(cmd);
            case CmdType.INSERT -> userFile.insert(cmd, cursorController.getUserPos(cmd.user));
            case CmdType.DELETE -> userFile.delete(cmd, cursorController.getUserPos(cmd.user));
            case CmdType.REPLACE -> userFile.replace(cmd, cursorController.getUserPos(cmd.user));
            default -> logger.log(System.Logger.Level.ERROR, "invalid cmd type: " + cmd.toString());
        }
        UserFileMem mem = userFile.dump(cmd);
        logger.log(System.Logger.Level.DEBUG, "mem = " + mem.content + " : " + mem.unixtime);
        var cmpRes = history.cmpCurrentFileContent(mem.content);
        logger.log(System.Logger.Level.DEBUG, cmpRes);
        history.setValue(mem);
        // Создаем Response
        CmdResponse response = new CmdResponse();
        response.state = cursorController.toResponseString();
        response.cmpRes = cmpRes;
        logger.log(System.Logger.Level.DEBUG, response.state + "\t" + response.cmpRes.content);
        return response;
    }

    public void jumpCursor(Cmd cmd) throws IOException {
        cursorController.setUserPos(cmd.user, userFile.normalizePosition(cmd.position));
    }
}
