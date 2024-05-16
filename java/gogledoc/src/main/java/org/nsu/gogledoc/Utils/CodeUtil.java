package org.nsu.gogledoc.Utils;

import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;

public class CodeUtil {
    public static String stringFromBuffer(ByteBuffer buffer) {
        return StandardCharsets.UTF_8.decode(buffer).toString();
    }

    public static ByteBuffer bufferFromString(String string) {
        return StandardCharsets.UTF_8.encode(string);
    }

}
