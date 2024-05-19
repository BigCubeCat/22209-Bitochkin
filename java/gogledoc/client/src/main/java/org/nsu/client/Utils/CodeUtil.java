package org.nsu.client.Utils;

import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;

public class CodeUtil {
    public static String stringFromBuffer(ByteBuffer buffer) {
        return StandardCharsets.UTF_8.decode(buffer).toString();
    }

    public static String stringFromHeapByteBuffer(ByteBuffer buffer) {
        try {
            return new String(buffer.array(), StandardCharsets.UTF_8);
        } catch (Exception e) {
            return "";
        }
    }

    public static ByteBuffer bufferFromString(String string) {
        return StandardCharsets.UTF_8.encode(string);
    }
}
