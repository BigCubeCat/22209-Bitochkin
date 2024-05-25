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

    private final CursorController cursorController = new CursorController();
    private final UserFile userFile;
    private final EditHistory history = new EditHistory(); // TODO specify size

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
        boolean isInfo = (cmd.eType == CmdType.JUMP);
        switch (cmd.eType) {
            case JUMP -> jumpCursor(cmd);
            case REPLACE -> userFile.replace(cmd, cursorController.getUserPos(cmd.user));
            default -> logger.log(System.Logger.Level.ERROR, "invalid cmd type: " + cmd.toString());
        }
        CmdResponse response = new CmdResponse();
        if (isInfo && (history.lastVersion() == cmd.unixtime)) {
            // ничегошеньки не изменилось
            response.update = false;
            logger.log(System.Logger.Level.INFO, "no changes");
        } else {
            response.update = true;
            UserFileMem mem = userFile.dump(cmd);
            logger.log(System.Logger.Level.DEBUG, "mem = " + mem.content + " : " + mem.unixtime);
            var cmpRes = history.cmpCurrentFileContent(mem.content);
            logger.log(System.Logger.Level.DEBUG, cmpRes);
            history.setValue(mem);
            response.cmpRes = cmpRes;
        }
        response.state = cursorController.toResponseString();
        return response;
    }

    public void jumpCursor(Cmd cmd) throws IOException {
        cursorController.setUserPos(cmd.user, userFile.normalizePosition(cmd.begin));
    }
}
