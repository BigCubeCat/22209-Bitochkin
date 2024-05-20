package org.nsu.gogledoc.FileWorker;

import com.fasterxml.jackson.annotation.JsonProperty;

public class CmpRes {
    @JsonProperty("begin")
    public int begin = 0;
    @JsonProperty("content")
    public String content = "";
    @JsonProperty("changes")
    public boolean hasChanges = false;
    @JsonProperty("replace")
    public boolean replaceAll = false;
}