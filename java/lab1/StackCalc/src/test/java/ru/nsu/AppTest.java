package ru.nsu;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Tag;
import org.junit.jupiter.api.Test;
import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.CmdParser.Parser;
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
            Parser parser = new Parser();
            calc.RunCommand(parser.ParseCommand("DEFINE a 100"));
            calc.RunCommand(parser.ParseCommand("PUSH a"));
            calc.RunCommand(parser.ParseCommand("SQRT"));
            calc.RunCommand(parser.ParseCommand("POP b"));
            calc.RunCommand(parser.ParseCommand("PUSH 3"));
            calc.RunCommand(parser.ParseCommand("PUSH b"));
            calc.RunCommand(parser.ParseCommand("/"));
            calc.RunCommand(parser.ParseCommand("POP"));
            Assertions.assertEquals(0.3, calc.GetOut());
        } catch (Exception e) {
            Assertions.fail();
        }
    }

    @Tag("calc")
    @Test
    public void testParabola() {
        try {
            StackCalc calc = new StackCalc();
            Parser parser = new Parser();
            calc.RunCommand(parser.ParseCommand("DEFINE a 1"));
            calc.RunCommand(parser.ParseCommand("DEFINE b -2"));
            calc.RunCommand(parser.ParseCommand("DEFINE c 1"));
            // b^2
            calc.RunCommand(parser.ParseCommand("PUSH b"));
            calc.RunCommand(parser.ParseCommand("PUSH b"));
            calc.RunCommand(parser.ParseCommand("*"));
            calc.RunCommand(parser.ParseCommand("POP B"));
            // - 4ac
            calc.RunCommand(parser.ParseCommand("PUSH 4"));
            calc.RunCommand(parser.ParseCommand("PUSH a"));
            calc.RunCommand(parser.ParseCommand("*"));
            calc.RunCommand(parser.ParseCommand("PUSH c"));
            calc.RunCommand(parser.ParseCommand("*"));
            calc.RunCommand(parser.ParseCommand("PUSH -1"));
            calc.RunCommand(parser.ParseCommand("*"));
            calc.RunCommand(parser.ParseCommand("PUSH B"));
            // D
            calc.RunCommand(parser.ParseCommand("+"));
            calc.RunCommand(parser.ParseCommand("POP D"));

            // x1

            calc.RunCommand(parser.ParseCommand("PUSH b"));
            calc.RunCommand(parser.ParseCommand("PUSH -1"));
            calc.RunCommand(parser.ParseCommand("*"));
            calc.RunCommand(parser.ParseCommand("PUSH D"));
            calc.RunCommand(parser.ParseCommand("SQRT"));
            calc.RunCommand(parser.ParseCommand("-"));
            calc.RunCommand(parser.ParseCommand("PUSH a"));
            calc.RunCommand(parser.ParseCommand("/"));
            calc.RunCommand(parser.ParseCommand("PUSH 2"));
            calc.RunCommand(parser.ParseCommand("/"));
            calc.RunCommand(parser.ParseCommand("POP"));
            Assertions.assertEquals(1, calc.GetOut());

            // x2

            calc.RunCommand(parser.ParseCommand("PUSH b"));
            calc.RunCommand(parser.ParseCommand("PUSH -1"));
            calc.RunCommand(parser.ParseCommand("*"));
            calc.RunCommand(parser.ParseCommand("PUSH D"));
            calc.RunCommand(parser.ParseCommand("SQRT"));
            calc.RunCommand(parser.ParseCommand("+"));
            calc.RunCommand(parser.ParseCommand("PUSH a"));
            calc.RunCommand(parser.ParseCommand("/"));
            calc.RunCommand(parser.ParseCommand("PUSH 2"));
            calc.RunCommand(parser.ParseCommand("/"));
            calc.RunCommand(parser.ParseCommand("POP"));
            Assertions.assertEquals(1, calc.GetOut());
        } catch (Exception e) {
            Assertions.fail();
        }
    }
}

