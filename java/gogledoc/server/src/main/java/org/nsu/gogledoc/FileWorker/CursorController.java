package org.nsu.gogledoc.FileWorker;

import org.nsu.gogledoc.Logger.ServerLoggerFinder;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class CursorController {
    private final System.Logger logger = ServerLoggerFinder.getLogger(
            "cursor",
            this.getClass().getModule()
    );

    private HashMap<String, Integer> map = new HashMap<String, Integer>();

    public CursorController() {

    }

    public ArrayList<String> toResponseString() {
        ArrayList<String> result = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            String value = entry.getKey() + ":" + entry.getValue();
            logger.log(System.Logger.Level.DEBUG, "cursor value = " + value);
            result.add(value);
        }
        return result;
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
