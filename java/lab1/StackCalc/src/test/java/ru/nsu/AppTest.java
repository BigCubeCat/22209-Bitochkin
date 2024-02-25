package ru.nsu;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Tag;
import org.junit.jupiter.api.Test;
import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.StackCalc.StackCalc;


public class AppTest {
    @Tag("context")
    @Test
    public void testCalcContextOut() {
        CalcContext ctx = new CalcContext();
        ctx.Push(0.1);
        Assertions.assertEquals(0.1, ctx.Print());
        Assertions.assertEquals(0.1, ctx.Pop());
        try {
            ctx.SetVariable("var", 10.0);
            Assertions.assertEquals(10, ctx.GetVariable("var"));
        } catch (UnknowVariableException e) {
            Assertions.fail();
        }
    }

    @Tag("calc")
    @Test
    public void testStackCalc() {
        try {
            StackCalc calc = new StackCalc();
            calc.RunCommand(new String[]{"PUSH", "2"});
            calc.RunCommand(new String[]{"PUSH", "2"});
            calc.RunCommand(new String[]{"*"});
            calc.RunCommand(new String[]{"POP"});
        } catch (Exception e) {
            Assertions.fail();
        }
    }
}

