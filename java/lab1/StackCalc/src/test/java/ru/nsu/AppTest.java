package ru.nsu;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Tag;
import org.junit.jupiter.api.Test;
import ru.nsu.CalcContext.CalcContext;
import ru.nsu.CalcContext.UnknowVariableException;
import ru.nsu.CmdParser.CalcConfig;
import ru.nsu.CmdParser.InputReader;
import ru.nsu.CmdParser.Parser;
import ru.nsu.Operators.Exceptions.InvalidCountVariablesException;
import ru.nsu.Operators.Util.DefineOperator;
import ru.nsu.Operators.Util.PopOperator;
import ru.nsu.Operators.Util.PrintOperator;
import ru.nsu.StackCalc.StackCalc;
import ru.nsu.StackCalc.Translator;
import ru.nsu.logging.CalcLoggerFinder;

import java.util.Scanner;

public class AppTest {
    @Tag("calc")
    @Test
    public void StackCalcCov() {
        StackCalc calc = new StackCalc();
        CalcConfig cfg = new CalcConfig();
        cfg.cmd = "abracadabra";
        cfg.pass = false;
        try {
            calc.RunCommand(cfg);
        } catch (Exception ignored) {
            Assertions.fail();
        }

        Parser parser = new Parser();
        calc.RunCommand(parser.ParseCommand("SQRT"));
        calc.RunCommand(parser.ParseCommand("PUSH invalid"));
        calc.RunCommand(parser.ParseCommand("DEFINE a 1 1"));
        calc.RunCommand(parser.ParseCommand("TEST"));
    }

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
        try {
            ctx.GetVariable("error");
            Assertions.fail();
        } catch (UnknowVariableException ignored) {
        }
    }

    @Tag("stupid_test_for_coverage")
    @Test
    public void testWhat() {
        PrintOperator operator = new PrintOperator();
        Assertions.assertEquals(0, operator.CountVariables());
        CalcConfig cfg = new CalcConfig();
        Assertions.assertTrue(cfg.pass);
    }

    @Tag("calc")
    @Test
    public void testStackCalc() {
        try {
            StackCalc calc = new StackCalc();
            Parser parser = new Parser();
            calc.RunCommand(parser.ParseCommand("DEFINE a 100"));
            calc.RunCommand(parser.ParseCommand(""));
            calc.RunCommand(parser.ParseCommand("# comment"));
            calc.RunCommand(parser.ParseCommand("PUSH a"));
            calc.RunCommand(parser.ParseCommand("SQRT"));
            calc.RunCommand(parser.ParseCommand("POP b"));
            calc.RunCommand(parser.ParseCommand("PUSH 3"));
            calc.RunCommand(parser.ParseCommand("PUSH b"));
            calc.RunCommand(parser.ParseCommand("/"));
            calc.RunCommand(parser.ParseCommand("PRINT"));
            Assertions.assertEquals(0.3, calc.GetOut());
        } catch (Exception e) {
            Assertions.fail();
        }
    }

    @Tag("error")
    @Test
    public void testExceptions() {
        StackCalc calc = new StackCalc();
        Parser parser = new Parser();
        calc.RunCommand(parser.ParseCommand("PUSH a"));
        Assertions.assertNull(calc.GetOut());
        try {
            Translator tr = new Translator(null);
            tr.Run();
            Assertions.fail();
        } catch (NullPointerException ignored) {
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

    @Tag("utils_")
    @Test
    public void UtilsCov() {
        PopOperator pop = new PopOperator();
        Assertions.assertEquals(1, pop.CountVariables());
        String[] args = {"1", "2", "3"};
        DefineOperator dop = new DefineOperator();
        try {
            dop.Exec(null, args);
            Assertions.fail();
        } catch (InvalidCountVariablesException ignored) {
        }
    }

    @Tag("utils_")
    @Test
    public void LoggerCov() {
        System.Logger logger = CalcLoggerFinder.getLogger("factory", this.getClass().getModule());
        Assertions.assertTrue(logger.isLoggable(System.Logger.Level.ERROR));
        logger.log(System.Logger.Level.ERROR, "tst", new Throwable("a"));
        logger.log(System.Logger.Level.ERROR, "tst");
    }

    @Tag("cmd_parser")
    @Test
    public void CmdParserTest() {
        CalcConfig _cfg = new CalcConfig();
        try {
            Scanner scanner = new Scanner("# test\nDEFINE variable 10\n");
            InputReader ir = new InputReader(scanner);
            Translator translator = new Translator(ir);
            translator.Run();
            ir.close();
        } catch (Exception e) {
            System.out.println(e);
            Assertions.fail();
        }
    }

}

