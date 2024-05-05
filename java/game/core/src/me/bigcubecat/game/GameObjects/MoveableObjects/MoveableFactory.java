package me.bigcubecat.game.GameObjects.MoveableObjects;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Properties;

public class MoveableFactory {
    Map<String, Class<?>> map = new HashMap<>();
    Properties names = new Properties();

    public MoveableFactory() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(
                Objects.requireNonNull(getClass().getResource("/factory/moveable")).openStream())
        )) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] words = line.split(" ");
                names.setProperty(words[0], words[1]);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    public SceneObject createObject(String name, MoveableConf conf) throws ClassNotFoundException, NoSuchMethodException, InstantiationException, IllegalAccessException, InvocationTargetException {
        if (!isLoaded(name)) {
            map.put(name, Class.forName(
                    names.getProperty(name)
            ));
        }
        SceneObject moveableObject = (SceneObject) map.get(name).getDeclaredConstructor().newInstance();
        moveableObject.Setup(conf);
        return moveableObject;
    }

    boolean isLoaded(String name) {
        return map.containsKey(name);
    }

    public boolean isObject(String name) {
        return names.containsKey(name);
    }

}
