package org.nsu.gogledoc.FileWorker;

import java.util.HashMap;

public class CursorController {
    private HashMap<String, Integer> map = new HashMap<String, Integer>();

    public CursorController() {

    }

    public void resetAll() {
        map = new HashMap<>();
    }

    public void setUserPos(String user, Integer pos) {
        map.put(user, pos);
    }

    /*
    getUserPos(String user):
    Returns user position. Returns -1 if not found
     */
    public Integer getUserPos(String user) {
        if (map.containsKey(user)) {
            return map.get(user);
        }
        return -1;
    }
}
