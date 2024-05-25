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
            case "R" -> CmdType.REPLACE;
            case "J" -> CmdType.JUMP;
            default -> CmdType.INVALID;
        };
    }

    public Cmd parseCmd(String json) {
        Cmd cmd = new Cmd();
        try {
            System.out.println("json = " + json);
            var jsonNode = getJson(json);
            cmd.user = jsonNode.get("user").asText();
            cmd.begin = jsonNode.get("begin").asInt();
            cmd.end = jsonNode.get("end").asInt();
            cmd.content = jsonNode.get("content").asText();
            cmd.eType = chooseType(jsonNode.get("type").asText());

            if (jsonNode.has("unixtime")) {
                cmd.unixtime = jsonNode.get("unixtime").asInt();
            }
        } catch (Exception e) {
            System.out.println(e);
            cmd.eType = CmdType.INVALID;
        }
        return cmd;
    }
}
