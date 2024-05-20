package org.nsu.gogledoc.Cmd;

import com.fasterxml.jackson.annotation.JsonProperty;

import java.util.ArrayList;

public class CmdResponse {
    @JsonProperty("state")
    public ArrayList<String> state;
}
