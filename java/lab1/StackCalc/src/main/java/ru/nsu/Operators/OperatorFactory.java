package ru.nsu.Operators;

import ru.nsu.logging.CalcLoggerFinder;

import java.io.*;
import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Properties;


public class OperatorFactory {

    private final System.Logger logger = CalcLoggerFinder.getLogger("factory", this.getClass().getModule());
    Map<String, OperatorInterface> map = new HashMap<>();
    Properties names = new Properties();

    public OperatorFactory() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(
                Objects.requireNonNull(getClass().getResource("/factory.txt")).openStream())
        )) {
            String line;
            while ((line = br.readLine()) != null) {
                logger.log(System.Logger.Level.DEBUG, line);
                String[] words = line.split(" ");
                names.setProperty(words[0], words[1]);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public OperatorInterface getCommand(String name) throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
        if (!isLoaded(name)) {
            map.put(name, (OperatorInterface) Class.forName(
                    names.getProperty(name)
            ).getDeclaredConstructor().newInstance());
        }
        return map.get(name);
    }

    boolean isLoaded(String name) {
        return map.containsKey(name);
    }

    public boolean isCommand(String cmd) {
        return names.containsKey(cmd);
    }
}
