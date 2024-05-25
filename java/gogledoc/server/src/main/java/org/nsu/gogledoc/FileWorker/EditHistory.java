package org.nsu.gogledoc.FileWorker;

public class EditHistory {
    private UserFileMem mem = new UserFileMem();

    public int lastVersion() {
        return mem.unixtime;
    }

    public EditHistory() {}

    public void setValue(UserFileMem mem) {
        this.mem = mem;
    }

    private String sliceString(String str, boolean isStart) {
        int size = (str.length() - mem.content.length());
        char[] dst = new char[size];
        if (isStart) {
            str.getChars(0, size, dst, 0);
        } else {
            str.getChars(mem.content.length(), mem.content.length() + size, dst, 0);
        }
        return new String(dst);
    }

    public static int currentUnixTime() {
        return (int) (System.currentTimeMillis() / 1000);
    }

    public CmpRes cmpCurrentFileContent(String fileContent) {
        // Алгоритм очень наивен, так как горят сроки
        CmpRes res = new CmpRes();
        if (fileContent.equals(mem.content)) {
            res.hasChanges = false;
            mem.unixtime = currentUnixTime();
            return res;
        }
        mem.unixtime = currentUnixTime();
        res.hasChanges = true;
        // Нужно добавить немного
        if (fileContent.startsWith(mem.content)) {
            // Добавить в конец
            res.replaceAll = false;
            res.content = sliceString(fileContent, false);
            res.begin = -1;
            return res;
        } else if (fileContent.endsWith(mem.content)) {
            // Добавить в начало
            res.replaceAll = false;
            res.content = sliceString(fileContent, true);
            res.begin = 0;
            return res;
        }
        // Удаление происходит реже при редактировании документа, да и сроки горят
        res.replaceAll = true;
        res.begin = 0;
        res.content = fileContent;
        return res;
    }
}
