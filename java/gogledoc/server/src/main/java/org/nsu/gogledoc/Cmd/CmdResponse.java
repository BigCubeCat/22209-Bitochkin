package org.nsu.gogledoc.Cmd;

import com.fasterxml.jackson.annotation.JsonProperty;
import org.nsu.gogledoc.FileWorker.CmpRes;

import java.util.ArrayList;

public class CmdResponse {
    @JsonProperty("state")
    public ArrayList<String> state;
    @JsonProperty("res")
    public CmpRes cmpRes;
    @JsonProperty("update")
    public boolean update = true;
}
