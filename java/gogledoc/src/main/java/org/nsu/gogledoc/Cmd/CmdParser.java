package org.nsu.gogledoc.Cmd;

import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.IOException;

public class CmdParser {
    JsonNode getJson(String jsonString) throws IOException {
        ObjectMapper mapper = new ObjectMapper();
        return mapper.readTree(jsonString);
    }

    CmdType chooseType(String stringType) {
        switch (stringType) {
            case "i":
                return CmdType.INSERT;
            case "d":
                return CmdType.DELETE;
            case "c":
                return CmdType.CREATE;
            case "u":
                return CmdType.UPDATE;
        }
        return CmdType.INVALID;
    }

    static int currentUnixTime() {
        return (int) (System.currentTimeMillis() / 1000);
    }

    public Cmd parseCmd(String json) throws IOException {
        Cmd cmd = new Cmd();
        var jsonNode = getJson(json);

        cmd.user = jsonNode.get("user").asText();
        cmd.eType = chooseType(jsonNode.get("type").asText());
        if (cmd.eType == CmdType.DELETE || cmd.eType == CmdType.INSERT) {
            cmd.cursor = jsonNode.get("position").asInt();
        }
        cmd.unixtime = currentUnixTime();

        return cmd;
    }

    public String marshalCmdResponse(CmdResponse response) throws IOException {
        return "";
    }
}
