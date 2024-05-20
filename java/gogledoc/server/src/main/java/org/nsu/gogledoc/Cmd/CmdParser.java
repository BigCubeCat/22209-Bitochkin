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
        return switch (stringType) {
            case "i" -> CmdType.INSERT;
            case "r" -> CmdType.REPLACE;
            case "d" -> CmdType.DELETE;
            case "c" -> CmdType.CREATE;
            case "j" -> CmdType.JUMP;
            case "u" -> CmdType.UPDATE;
            case "m" -> CmdType.MESSAGE;
            default -> CmdType.INVALID;
        };
    }

    static int currentUnixTime() {
        return (int) (System.currentTimeMillis() / 1000);
    }

    public Cmd parseCmd(String json) throws IOException {
        Cmd cmd = new Cmd();
        var jsonNode = getJson(json);

        cmd.user = jsonNode.get("user").asText();
        cmd.eType = chooseType(jsonNode.get("type").asText());
        if (cmd.eType == CmdType.UPDATE) {
            return cmd;
        }
        if (cmd.eType == CmdType.JUMP) {
            cmd.position = jsonNode.get("position").asInt();
        }
        if (cmd.eType != CmdType.JUMP && cmd.eType != CmdType.DELETE) {
            cmd.content = jsonNode.get("content").asText();
        }
        if (cmd.eType == CmdType.DELETE || cmd.eType == CmdType.REPLACE) {
            cmd.size = jsonNode.get("size").asInt();
        }
        cmd.unixtime = currentUnixTime();
        return cmd;
    }

    public String marshalCmdResponse(CmdResponse response) throws IOException {
        return "";
    }
}
