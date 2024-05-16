package org.nsu.gogledoc.Cmd;

import com.fasterxml.jackson.annotation.JsonProperty;

public class CmdResponse {
    @JsonProperty("type")
    private String responseType;
    @JsonProperty("content")
    private String content;
    @JsonProperty("cmd")
    private String cmd;
}
