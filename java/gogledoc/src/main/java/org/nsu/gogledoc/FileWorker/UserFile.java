package org.nsu.gogledoc.FileWorker;

import java.nio.file.Path;
import java.nio.file.Paths;

public class UserFile {
    private String owner;
    private String filePath;
    private String fileContent;

    public Path getFilePath() {
        return Paths.get(filePath);
    }
}
