/**
 * @file JsonTest.h
 * @author Seb Madgwick
 * @brief Unit tests.
 */

//------------------------------------------------------------------------------
// Includes

#include "Json.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h> // printf
#include <string.h> // memcmp

//------------------------------------------------------------------------------
// Definitions

/**
 * @brief Whitespace.
 */
#define WS " \t\n\r \t\n\r"

//------------------------------------------------------------------------------
// Function declarations

static void Assert(const int result, const char *const message);

static void TestParseType(void);

static int CheckParseType(const char *json, const JsonType expectedType);

static void TestTestParseTypeError(void);

static int CheckTestParseTypeError(const char *json, const JsonError expectedError);

static void TestParseString(void);

static int CheckParseString(const char *json, const char *const expectedString, const size_t expectedStringSize);

static void TestParseStringError(void);

static int CheckParseStringError(const char *json, const JsonError expectedError);

static void TestParseNumber(void);

static int CheckParseNumber(const char *json, const float expectedNumber);

static void TestParseNumberError(void);

static int CheckParseNumberError(const char *json, const JsonError expectedError);

static void TestParseBoolean(void);

static int CheckParseBoolean(const char *json, const bool expectedBoolean);

static void TestParseBooleaneError(void);

static int CheckParseBooleanError(const char *json, const JsonError expectedError);

static void TestParseNull(void);

static int CheckParseNull(const char *json);

static void TestParseNullError(void);

static int CheckParseNullError(const char *json, const JsonError expectedError);

static void TestParse(void);

static int CheckParse(const char *json);

static void TestParseError(void);

static int CheckParseError(const char *json, const JsonError expectedError);

static void TestParseDefinedObjectOfString(void);

static int CheckParseDefinedObjectOfString(const char *json);

static void TestParseDefinedObjectOfNumber(void);

static int CheckParseDefinedObjectOfNumber(const char *json);

static void TestParseDefinedObjectOfObject(void);

static int CheckParseDefinedObjectOfObject(const char *json);

static void TestParseDefinedObjectOfArray(void);

static int CheckParseDefinedObjectOfArray(const char *json);

static void TestParseDefinedObjectOfBooleanTrue(void);

static int CheckParseDefinedObjectOfBooleanTrue(const char *json);

static void TestParseDefinedObjectOfBooleanFalse(void);

static int CheckParseDefinedObjectOfBooleanFalse(const char *json);

static void TestParseDefinedObjectOfNull(void);

static int CheckParseDefinedObjectOfNull(const char *json);

static void TestParseDefinedObjectOfAllTypes(void);

static int CheckParseDefinedObjectOfAllTypes(const char *json);

static void TestParseDefinedObjectError(void);

static int CheckParseDefinedObjectError(const char *json, const JsonError expectedError);

static void TestParsePartial(void);

static int CheckParsePartial(const char *json);

//------------------------------------------------------------------------------
// Variables

static int passCount;
static int failCount;

//------------------------------------------------------------------------------
// Functions

int JsonTest(void) {
    TestParseType();
    TestTestParseTypeError();
    TestParseString();
    TestParseStringError();
    TestParseNumber();
    TestParseNumberError();
    TestParseBoolean();
    TestParseBooleaneError();
    TestParseNull();
    TestParseNullError();
    TestParse();
    TestParseError();
    TestParseDefinedObjectOfString();
    TestParseDefinedObjectOfNumber();
    TestParseDefinedObjectOfObject();
    TestParseDefinedObjectOfArray();
    TestParseDefinedObjectOfBooleanTrue();
    TestParseDefinedObjectOfBooleanFalse();
    TestParseDefinedObjectOfNull();
    TestParseDefinedObjectOfAllTypes();
    TestParseDefinedObjectError();
    TestParsePartial();
    printf("Passed %u, Failed %u\n", passCount, failCount);
    return failCount == 0 ? 0 : 1;
}

static void Assert(const int result, const char *const message) {
    if (result != 0) {
        printf("Failed. %s\n", message);
        failCount++;
    } else {
        passCount++;
    }
}

static void TestParseType(void) {
    Assert(CheckParseType("\"", JsonTypeString), "Parse type string without whitespace");
    Assert(CheckParseType("-", JsonTypeNumber), "Parse type number - without whitespace");
    Assert(CheckParseType("0", JsonTypeNumber), "Parse type number 0 without whitespace");
    Assert(CheckParseType("1", JsonTypeNumber), "Parse type number 1 without whitespace");
    Assert(CheckParseType("2", JsonTypeNumber), "Parse type number 2 without whitespace");
    Assert(CheckParseType("3", JsonTypeNumber), "Parse type number 3 without whitespace");
    Assert(CheckParseType("4", JsonTypeNumber), "Parse type number 4 without whitespace");
    Assert(CheckParseType("5", JsonTypeNumber), "Parse type number 5 without whitespace");
    Assert(CheckParseType("6", JsonTypeNumber), "Parse type number 6 without whitespace");
    Assert(CheckParseType("7", JsonTypeNumber), "Parse type number 7 without whitespace");
    Assert(CheckParseType("8", JsonTypeNumber), "Parse type number 8 without whitespace");
    Assert(CheckParseType("9", JsonTypeNumber), "Parse type number 9 without whitespace");
    Assert(CheckParseType("{", JsonTypeObject), "Parse type object without whitespace");
    Assert(CheckParseType("[", JsonTypeArray), "Parse type array without whitespace");
    Assert(CheckParseType("t", JsonTypeBoolean), "Parse type boolean true without whitespace");
    Assert(CheckParseType("f", JsonTypeBoolean), "Parse type boolean false without whitespace");
    Assert(CheckParseType("n", JsonTypeNull), "Parse type null without whitespace");
    Assert(CheckParseType(WS "\"", JsonTypeString), "Parse type string with whitespace");
    Assert(CheckParseType(WS "-", JsonTypeNumber), "Parse type number - with whitespace");
    Assert(CheckParseType(WS "0", JsonTypeNumber), "Parse type number 0 with whitespace");
    Assert(CheckParseType(WS "1", JsonTypeNumber), "Parse type number 1 with whitespace");
    Assert(CheckParseType(WS "2", JsonTypeNumber), "Parse type number 2 with whitespace");
    Assert(CheckParseType(WS "3", JsonTypeNumber), "Parse type number 3 with whitespace");
    Assert(CheckParseType(WS "4", JsonTypeNumber), "Parse type number 4 with whitespace");
    Assert(CheckParseType(WS "5", JsonTypeNumber), "Parse type number 5 with whitespace");
    Assert(CheckParseType(WS "6", JsonTypeNumber), "Parse type number 6 with whitespace");
    Assert(CheckParseType(WS "7", JsonTypeNumber), "Parse type number 7 with whitespace");
    Assert(CheckParseType(WS "8", JsonTypeNumber), "Parse type number 8 with whitespace");
    Assert(CheckParseType(WS "9", JsonTypeNumber), "Parse type number 9 with whitespace");
    Assert(CheckParseType(WS "{", JsonTypeObject), "Parse type object with whitespace");
    Assert(CheckParseType(WS "[", JsonTypeArray), "Parse type array with whitespace");
    Assert(CheckParseType(WS "t", JsonTypeBoolean), "Parse type boolean true with whitespace");
    Assert(CheckParseType(WS "f", JsonTypeBoolean), "Parse type boolean false with whitespace");
    Assert(CheckParseType(WS "n", JsonTypeNull), "Parse type null with whitespace");
}

static int CheckParseType(const char *json, const JsonType expectedType) {
    JsonType type;
    if (JsonParseType(&json, &type) != JsonErrorOK) {
        return 1;
    }
    if (type != expectedType) {
        return 1;
    }
    return 0;
}

static void TestTestParseTypeError(void) {
    Assert(CheckTestParseTypeError("", JsonErrorInvalidSyntax), "Parse type error invalid syntax");
}

static int CheckTestParseTypeError(const char *json, const JsonError expectedError) {
    JsonType type;
    if (JsonParseType(&json, &type) != expectedError) {
        return 1;
    }
    return 0;
}

static void TestParseString(void) {
    Assert(CheckParseString("\" !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~\"",
                            " !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~",
                            94), "Parse string valid characters <0x7F");
    Assert(CheckParseString("\"\x7E\x7F\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8A\x8B\x8C\x8D\x8E\x8F\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9A\x9B\x9C\x9D\x9E\x9F\xA0\xA1\xA2\xA3\xA4\xA5\xA6\xA7\xA8\xA9\xAA\xAB\xAC\xAD\xAE\xAF\xB0\xB1\xB2\xB3\xB4\xB5\xB6\xB7\xB8\xB9\xBA\xBB\xBC\xBD\xBE\xBF\xC0\xC1\xC2\xC3\xC4\xC5\xC6\xC7\xC8\xC9\xCA\xCB\xCC\xCD\xCE\xCF\xD0\xD1\xD2\xD3\xD4\xD5\xD6\xD7\xD8\xD9\xDA\xDB\xDC\xDD\xDE\xDF\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF7\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF\"",
                            "\x7E\x7F\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8A\x8B\x8C\x8D\x8E\x8F\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9A\x9B\x9C\x9D\x9E\x9F\xA0\xA1\xA2\xA3\xA4\xA5\xA6\xA7\xA8\xA9\xAA\xAB\xAC\xAD\xAE\xAF\xB0\xB1\xB2\xB3\xB4\xB5\xB6\xB7\xB8\xB9\xBA\xBB\xBC\xBD\xBE\xBF\xC0\xC1\xC2\xC3\xC4\xC5\xC6\xC7\xC8\xC9\xCA\xCB\xCC\xCD\xCE\xCF\xD0\xD1\xD2\xD3\xD4\xD5\xD6\xD7\xD8\xD9\xDA\xDB\xDC\xDD\xDE\xDF\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF7\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF",
                            131), "Parse string valid characters >0x7E");
    Assert(CheckParseString("\" \\\" \\\\ \\/ \\b \\f \\n \\r \\t \"", " \" \\ / \b \f \n \r \t ", 18), "Parse string non hex escape sequences");
    Assert(CheckParseString("\" \\u0041\\u0042\\u0043 \"", " ABC ", 6), "Parse string hex escape sequences for valid characters");
    Assert(CheckParseString("\" \\u004a\\u004b\\u004c \"", " JKL ", 6), "Parse string hex escape sequences lower");
    Assert(CheckParseString("\" \\u004A\\u004B\\u004C \"", " JKL ", 6), "Parse string hex escape sequences upper");
    Assert(CheckParseString("\" \\u1141\\u2242\\u3343 \"", " ABC ", 6), "Parse string hex escape sequences non zero upper nibble");
    Assert(CheckParseString("\" \\uFFFF \"", " \xFF ", 4), "Parse string hex escape sequences FFFF");
    Assert(CheckParseString("\" ABC\\u0000DEF \"", " ABC\0DEF ", 10), "Parse string including null hex escape sequence");
}

static int CheckParseString(const char *json, const char *const expectedString, const size_t expectedStringSize) {
    char string[256];
    size_t stringSize;
    if (JsonParseString(&json, string, sizeof(string), &stringSize) != JsonErrorOK) {
        return 1;
    }
    if (memcmp(string, expectedString, expectedStringSize) != 0) {
        return 1;
    }
    if (stringSize != expectedStringSize) {
        return 1;
    }
    return 0;
}

static void TestParseStringError(void) {
    Assert(CheckParseStringError("", JsonErrorInvalidSyntax), "Parse string error invalid syntax");
    Assert(CheckParseStringError("{", JsonErrorUnexpectedType), "Parse string error unexpected type");
    Assert(CheckParseStringError("\"0123456789ABCDEF\"", JsonErrorStringTooLong), "Parse string error string too long");
    Assert(CheckParseStringError("\"abc", JsonErrorMissingStringEnd), "Parse string error missing string end");
    Assert(CheckParseStringError("\"\x01\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x01");
    Assert(CheckParseStringError("\"\x02\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x02");
    Assert(CheckParseStringError("\"\x03\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x03");
    Assert(CheckParseStringError("\"\x04\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x04");
    Assert(CheckParseStringError("\"\x05\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x05");
    Assert(CheckParseStringError("\"\x06\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x06");
    Assert(CheckParseStringError("\"\x07\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x07");
    Assert(CheckParseStringError("\"\x08\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x08");
    Assert(CheckParseStringError("\"\x09\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x09");
    Assert(CheckParseStringError("\"\x0A\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x0A");
    Assert(CheckParseStringError("\"\x0B\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x0B");
    Assert(CheckParseStringError("\"\x0C\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x0C");
    Assert(CheckParseStringError("\"\x0D\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x0D");
    Assert(CheckParseStringError("\"\x0E\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x0E");
    Assert(CheckParseStringError("\"\x0F\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x0F");
    Assert(CheckParseStringError("\"\x10\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x10");
    Assert(CheckParseStringError("\"\x11\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x11");
    Assert(CheckParseStringError("\"\x12\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x12");
    Assert(CheckParseStringError("\"\x13\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x13");
    Assert(CheckParseStringError("\"\x14\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x14");
    Assert(CheckParseStringError("\"\x15\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x15");
    Assert(CheckParseStringError("\"\x16\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x16");
    Assert(CheckParseStringError("\"\x17\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x17");
    Assert(CheckParseStringError("\"\x18\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x18");
    Assert(CheckParseStringError("\"\x19\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x19");
    Assert(CheckParseStringError("\"\x1A\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x1A");
    Assert(CheckParseStringError("\"\x1B\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x1B");
    Assert(CheckParseStringError("\"\x1C\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x1C");
    Assert(CheckParseStringError("\"\x1D\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x1D");
    Assert(CheckParseStringError("\"\x1E\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x1E");
    Assert(CheckParseStringError("\"\x1F\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x1F");
    Assert(CheckParseStringError("\"\\a\"", JsonErrorInvalidStringEscapeSequence), "Parse string error invalid escape sequence");
    Assert(CheckParseStringError("\"\\ux\"", JsonErrorInvalidStringHexEscapeSequence), "Parse string error invalid hex escape sequence 1");
    Assert(CheckParseStringError("\"\\u0x\"", JsonErrorInvalidStringHexEscapeSequence), "Parse string error invalid hex escape sequence 2");
    Assert(CheckParseStringError("\"\\u00x\"", JsonErrorInvalidStringHexEscapeSequence), "Parse string error invalid hex escape sequence 3");
    Assert(CheckParseStringError("\"\\u000x\"", JsonErrorInvalidStringHexEscapeSequence), "Parse string error invalid hex escape sequence 4");
}

static int CheckParseStringError(const char *json, const JsonError expectedError) {
    char string[16]; // too small for "0123456789ABCDEF"
    size_t stringSize;
    if (JsonParseString(&json, string, sizeof(string), &stringSize) != expectedError) {
        return 1;
    }
    return 0;
}

static void TestParseNumber(void) {
    Assert(CheckParseNumber("-0", -0.0f), "Parse number -0");
    Assert(CheckParseNumber("-0.0", -0.0f), "Parse number -0.0");
    Assert(CheckParseNumber("-0.123", -0.123f), "Parse number -0.123");
    Assert(CheckParseNumber("-123", -123.0f), "Parse number -123");
    Assert(CheckParseNumber("-123.456", -123.456f), "Parse number -123.456");
    Assert(CheckParseNumber("-123.456e1", -1234.56f), "Parse number -123.456e1");
    Assert(CheckParseNumber("-123.456E1", -1234.56f), "Parse number -123.456E1");
    Assert(CheckParseNumber("-123.456e+1", -1234.56f), "Parse number -123.456e+1");
    Assert(CheckParseNumber("-123.456E+1", -1234.56f), "Parse number -123.456E+1");
    Assert(CheckParseNumber("-123.456e-1", -12.3456f), "Parse number -123.456e-1");
    Assert(CheckParseNumber("-123.456E-1", -12.3456f), "Parse number -123.456E-1");
    Assert(CheckParseNumber("0", 0.0f), "Parse number 0");
    Assert(CheckParseNumber("0.0", 0.0f), "Parse number 0.0");
    Assert(CheckParseNumber("0.123", 0.123f), "Parse number 0.123");
    Assert(CheckParseNumber("123", 123.0f), "Parse number 123");
    Assert(CheckParseNumber("123.456", 123.456f), "Parse number 123.456");
    Assert(CheckParseNumber("123.456e1", 1234.56f), "Parse number 123.456e1");
    Assert(CheckParseNumber("123.456E1", 1234.56f), "Parse number 123.456E1");
    Assert(CheckParseNumber("123.456e+1", 1234.56f), "Parse number 123.456e+1");
    Assert(CheckParseNumber("123.456E+1", 1234.56f), "Parse number 123.456E+1");
    Assert(CheckParseNumber("123.456e-1", 12.3456f), "Parse number 123.456e-1");
    Assert(CheckParseNumber("123.456E-1", 12.3456f), "Parse number 123.456E-1");
}

static int CheckParseNumber(const char *json, const float expectedNumber) {
    float number;
    if (JsonParseNumber(&json, &number) != JsonErrorOK) {
        return 1;
    }
    if (number != expectedNumber) {
        return 1;
    }
    return 0;
}

static void TestParseNumberError(void) {
    Assert(CheckParseNumberError("", JsonErrorInvalidSyntax), "Parse number error invalid syntax");
    Assert(CheckParseNumberError("{", JsonErrorUnexpectedType), "Parse number error unexpected type");
    Assert(CheckParseNumberError("-", JsonErrorInvalidNumberFormat), "Parse number error -");
    Assert(CheckParseNumberError("00", JsonErrorInvalidNumberFormat), "Parse number error 00");
    Assert(CheckParseNumberError(".", JsonErrorInvalidSyntax), "Parse number error .");
    Assert(CheckParseNumberError("-.", JsonErrorInvalidNumberFormat), "Parse number error -.");
    Assert(CheckParseNumberError("0.", JsonErrorInvalidNumberFormat), "Parse number error 0.");
    Assert(CheckParseNumberError(".0", JsonErrorInvalidSyntax), "Parse number error .0");
    Assert(CheckParseNumberError("0e", JsonErrorInvalidNumberFormat), "Parse number error 0e");
    Assert(CheckParseNumberError("0E", JsonErrorInvalidNumberFormat), "Parse number error 0E");
    Assert(CheckParseNumberError("0e+", JsonErrorInvalidNumberFormat), "Parse number error 0e+");
    Assert(CheckParseNumberError("0E+", JsonErrorInvalidNumberFormat), "Parse number error 0E+");
    Assert(CheckParseNumberError("0e-", JsonErrorInvalidNumberFormat), "Parse number error 0e-");
    Assert(CheckParseNumberError("0E-", JsonErrorInvalidNumberFormat), "Parse number error 0E-");
    Assert(CheckParseNumberError("01234567890123456789012345678901", JsonErrorNumberTooLong), "Parse number error number too long"); // string size = 33
}

static int CheckParseNumberError(const char *json, const JsonError expectedError) {
    float number;
    if (JsonParseNumber(&json, &number) != expectedError) {
        return 1;
    }
    return 0;
}

static void TestParseBoolean(void) {
    Assert(CheckParseBoolean("true", true), "Parse boolean true");
    Assert(CheckParseBoolean("false", false), "Parse boolean false");
}

static int CheckParseBoolean(const char *json, const bool expectedBoolean) {
    bool boolean;
    if (JsonParseBoolean(&json, &boolean) != JsonErrorOK) {
        return 1;
    }
    if (boolean != expectedBoolean) {
        return 1;
    }
    return 0;
}

static void TestParseBooleaneError(void) {
    Assert(CheckParseBooleanError("", JsonErrorInvalidSyntax), "Parse boolean error invalid syntax");
    Assert(CheckParseBooleanError("{", JsonErrorUnexpectedType), "Parse boolean error unexpected type");
    Assert(CheckParseBooleanError("t", JsonErrorInvalidSyntax), "Parse boolean error t");
    Assert(CheckParseBooleanError("tr", JsonErrorInvalidSyntax), "Parse boolean error tr");
    Assert(CheckParseBooleanError("tru", JsonErrorInvalidSyntax), "Parse boolean error tru");
    Assert(CheckParseBooleanError("True", JsonErrorInvalidSyntax), "Parse boolean error True");
    Assert(CheckParseBooleanError("TRUE", JsonErrorInvalidSyntax), "Parse boolean error TRUE");
    Assert(CheckParseBooleanError("f", JsonErrorInvalidSyntax), "Parse boolean error f");
    Assert(CheckParseBooleanError("fa", JsonErrorInvalidSyntax), "Parse boolean error fa");
    Assert(CheckParseBooleanError("fal", JsonErrorInvalidSyntax), "Parse boolean error fal");
    Assert(CheckParseBooleanError("fals", JsonErrorInvalidSyntax), "Parse boolean error fals");
    Assert(CheckParseBooleanError("False", JsonErrorInvalidSyntax), "Parse boolean error False");
    Assert(CheckParseBooleanError("FALSE", JsonErrorInvalidSyntax), "Parse boolean error FALSE");
}

static int CheckParseBooleanError(const char *json, const JsonError expectedError) {
    bool boolean;
    if (JsonParseBoolean(&json, &boolean) != expectedError) {
        return 1;
    }
    return 0;
}

static void TestParseNull(void) {
    Assert(CheckParseNull("null"), "Parse null");
}

static int CheckParseNull(const char *json) {
    if (JsonParseNull(&json) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

static void TestParseNullError(void) {
    Assert(CheckParseNullError("", JsonErrorInvalidSyntax), "Parse null error invalid syntax");
    Assert(CheckParseNullError("{", JsonErrorUnexpectedType), "Parse null error unexpected type");
    Assert(CheckParseNullError("n", JsonErrorInvalidSyntax), "Parse null error n");
    Assert(CheckParseNullError("nu", JsonErrorInvalidSyntax), "Parse null error nu");
    Assert(CheckParseNullError("nul", JsonErrorInvalidSyntax), "Parse null error nul");
    Assert(CheckParseNullError("Null", JsonErrorInvalidSyntax), "Parse null error Null");
    Assert(CheckParseNullError("NULL", JsonErrorInvalidSyntax), "Parse null error NULL");
}

static int CheckParseNullError(const char *json, const JsonError expectedError) {
    if (JsonParseNull(&json) != expectedError) {
        return 1;
    }
    return 0;
}

static void TestParse(void) {
    Assert(CheckParse("{}"), "Parse empty object without whitespace");
    Assert(CheckParse("[]"), "Parse empty array without whitespace");
    Assert(CheckParse("{" WS "}"), "Parse empty object with whitespace");
    Assert(CheckParse("[" WS "]"), "Empty empty array with whitespace");
    Assert(CheckParse("{\"a\":\"string\",\"b\":123,\"c\":{\"x\":0},\"d\":[0],\"e\":true,\"f\":false,\"g\":null}"), "Parse object of each type without whitespace");
    Assert(CheckParse("[\"string\",123,{\"x\":0},[0],true,false,null]"), "Parse array of each type without whitespace");
    Assert(CheckParse("{" WS "\"a\"" WS ":" WS "\"string\"" WS "," WS "\"b\"" WS ":" WS "123" WS "," WS "\"c\"" WS ":" WS "{" WS "\"x\"" WS ":" WS "0" WS "}" WS "," WS "\"d\"" WS ":" WS "[" WS "0" WS "]" WS "," WS "\"e\"" WS ":" WS "true" WS "," WS "\"f\"" WS ":" WS "false" WS "," WS "\"g\"" WS ":" WS "null" WS "}"), "Parse object of each type with whitespace");
    Assert(CheckParse("[\"string\"" WS "," WS "123" WS "," WS "{" WS "\"x\"" WS ":" WS "0" WS "}" WS "," WS "[" WS "0" WS "]" WS "," WS "true" WS "," WS "false" WS "," WS "null]"), "Parse array of each type with whitespace");
}

static int CheckParse(const char *json) {
    if (JsonParse(&json) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

static void TestParseError(void) {
    Assert(CheckParseError("{", JsonErrorMissingKey), "Parse error missing key");
    Assert(CheckParseError("{\"x\"", JsonErrorMissingColon), "Parse error missing colon");
    Assert(CheckParseError("{\"x\":0,", JsonErrorMissingKey), "Parse error missing key after comma");
    Assert(CheckParseError("{\"x\":0", JsonErrorMissingObjectEnd), "Parse error missing object end for single value without comma");
    Assert(CheckParseError("[", JsonErrorInvalidSyntax), "Parse error missing array end for empty array");
    Assert(CheckParseError("[0", JsonErrorMissingArrayEnd), "Parse error missing array end for single value without comma");
    Assert(CheckParseError("[0,", JsonErrorInvalidSyntax), "Parse error missing array end for single value with comma");
}

static int CheckParseError(const char *json, const JsonError expectedError) {
    if (JsonParse(&json) != expectedError) {
        return 1;
    }
    return 0;
}

static void TestParseDefinedObjectOfString(void) {
    Assert(CheckParseDefinedObjectOfString("{\"key\":\"string\"}"), "Parse defined object of string without whitespace");
    Assert(CheckParseDefinedObjectOfString("{" WS "\"key\"" WS ":" WS "\"string\"" WS "}"), "Parse defined object of string with whitespace");
}

static int CheckParseDefinedObjectOfString(const char *json) {
    const char **const jsonPointer = &json;

    // {
    if (JsonParseObjectStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "key" : "string"
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseString(jsonPointer, NULL, 0, 0) != JsonErrorOK) {
        return 1;
    }

    // }
    if (JsonParseObjectEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

static void TestParseDefinedObjectOfNumber(void) {
    Assert(CheckParseDefinedObjectOfNumber("{\"key\":123}"), "Parse defined object of number without whitespace");
    Assert(CheckParseDefinedObjectOfNumber("{" WS "\"key\"" WS ":" WS "123" WS "}"), "Parse defined object of number with whitespace");
}

static int CheckParseDefinedObjectOfNumber(const char *json) {
    const char **const jsonPointer = &json;

    // {
    if (JsonParseObjectStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "key" : 123
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseNumber(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }

    // }
    if (JsonParseObjectEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

static void TestParseDefinedObjectOfObject(void) {
    Assert(CheckParseDefinedObjectOfObject("{\"key\":{\"x\":0}}"), "Parse defined object of object without whitespace");
    Assert(CheckParseDefinedObjectOfObject("{" WS "\"key\"" WS ":" WS "{" WS "\"x\"" WS ":" WS "0" WS "}" WS "}"), "Parse defined object of object with whitespace");
}

static int CheckParseDefinedObjectOfObject(const char *json) {
    const char **const jsonPointer = &json;

    // {
    if (JsonParseObjectStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "key" : { "x" : 0 }
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseObjectStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseNumber(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseObjectEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // }
    if (JsonParseObjectEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

static void TestParseDefinedObjectOfArray(void) {
    Assert(CheckParseDefinedObjectOfArray("{\"key\":[0]}"), "Parse defined object of array without whitespace");
    Assert(CheckParseDefinedObjectOfArray("{" WS "\"key\"" WS ":" WS "[" WS "0" WS "]" WS "}"), "Parse defined object of array with whitespace");
}

static int CheckParseDefinedObjectOfArray(const char *json) {
    const char **const jsonPointer = &json;

    // {
    if (JsonParseObjectStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "key" : [ 0 ]
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseArrayStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseNumber(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseArrayEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // }
    if (JsonParseObjectEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

static void TestParseDefinedObjectOfBooleanTrue(void) {
    Assert(CheckParseDefinedObjectOfBooleanTrue("{\"key\":true}"), "Parse defined object of boolean true without whitespace");
    Assert(CheckParseDefinedObjectOfBooleanTrue("{" WS "\"key\"" WS ":" WS "true" WS "}"), "Parse defined object of boolean true with whitespace");
}

static int CheckParseDefinedObjectOfBooleanTrue(const char *json) {
    const char **const jsonPointer = &json;

    // {
    if (JsonParseObjectStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "key" : true
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseBoolean(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }

    // }
    if (JsonParseObjectEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

static void TestParseDefinedObjectOfBooleanFalse(void) {
    Assert(CheckParseDefinedObjectOfBooleanFalse("{\"key\":false}"), "Parse defined object of boolean false without whitespace");
    Assert(CheckParseDefinedObjectOfBooleanFalse("{" WS "\"key\"" WS ":" WS "false" WS "}"), "Parse defined object of boolean false with whitespace");
}

static int CheckParseDefinedObjectOfBooleanFalse(const char *json) {
    const char **const jsonPointer = &json;

    // {
    if (JsonParseObjectStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "key" : false
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseBoolean(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }

    // }
    if (JsonParseObjectEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

static void TestParseDefinedObjectOfNull(void) {
    Assert(CheckParseDefinedObjectOfNull("{\"key\":null}"), "Parse defined object of null without whitespace");
    Assert(CheckParseDefinedObjectOfNull("{" WS "\"key\"" WS ":" WS "null" WS "}"), "Parse defined object of null with whitespace");
}

static int CheckParseDefinedObjectOfNull(const char *json) {
    const char **const jsonPointer = &json;

    // {
    if (JsonParseObjectStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "key" : null
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseNull(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // }
    if (JsonParseObjectEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

static void TestParseDefinedObjectOfAllTypes(void) {
    Assert(CheckParseDefinedObjectOfAllTypes("{\"a\":\"string\",\"b\":123,\"c\":{\"x\":0},\"d\":[0],\"e\":true,\"f\":false,\"g\":null,\"h\":null}"), "Parse defined object of all types without whitespace");
    Assert(CheckParseDefinedObjectOfAllTypes("{" WS "\"a\"" WS ":" WS "\"string\"" WS "," WS "\"b\"" WS ":" WS "123" WS "," WS "\"c\"" WS ":" WS "{" WS "\"x\"" WS ":" WS "0" WS "}" WS "," WS "\"d\"" WS ":" WS "[" WS "0" WS "]" WS "," WS "\"e\"" WS ":" WS "true" WS "," WS "\"f\"" WS ":" WS "false" WS "," WS "\"g\"" WS ":" WS "null" WS "," WS "\"h\"" WS ":" WS "null" WS "}"), "Parse defined object of all types with whitespace");
}

static int CheckParseDefinedObjectOfAllTypes(const char *json) {
    const char **const jsonPointer = &json;

    // {
    if (JsonParseObjectStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "a" : "string" ,
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseString(jsonPointer, NULL, 0, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseComma(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "b" : 123 ,
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseNumber(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseComma(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "c" : { "x" : 0 } ,
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseObjectStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseNumber(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseObjectEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseComma(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "d" : [ 0 ] ,
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseArrayStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseNumber(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseArrayEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseComma(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "e" : true ,
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseBoolean(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseComma(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "f" : false ,
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseBoolean(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseComma(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "g" : null ,
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseNull(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseComma(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // "h" : null
    if (JsonParseKey(jsonPointer, NULL, 0) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseNull(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // }
    if (JsonParseObjectEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

static void TestParseDefinedObjectError(void) {
    Assert(CheckParseDefinedObjectError("\"a\":0,\"b\":[0]}", JsonErrorUnexpectedType), "Parse defined object error missing object start");
    Assert(CheckParseDefinedObjectError("{:0,\"b\":[0]}", JsonErrorMissingKey), "Parse defined object error missing key");
    Assert(CheckParseDefinedObjectError("{\"a\"0,\"b\":[0]}", JsonErrorMissingColon), "Parse defined object error missing colon");
    Assert(CheckParseDefinedObjectError("{\"a\":0\"b\":[0]}", JsonErrorMissingComma), "Parse defined object error missing comma");
    Assert(CheckParseDefinedObjectError("{\"a\":0,\"b\":0]}", JsonErrorUnexpectedType), "Parse defined object error missing array start");
    Assert(CheckParseDefinedObjectError("{\"a\":0,\"b\":[0}", JsonErrorMissingArrayEnd), "Parse defined object error missing array end");
    Assert(CheckParseDefinedObjectError("{\"a\":0,\"b\":[0]", JsonErrorMissingObjectEnd), "Parse defined object error missing object end");
}

static int CheckParseDefinedObjectError(const char *json, const JsonError expectedError) {
    const char **const jsonPointer = &json;
    JsonError error;
    while (true) {
        // {
        error = JsonParseObjectStart(jsonPointer);
        if (error != JsonErrorOK) {
            break;
        }

        // "a" : 0 ,
        error = JsonParseKey(jsonPointer, NULL, 0);
        if (error != JsonErrorOK) {
            break;
        }
        error = JsonParseNumber(jsonPointer, NULL);
        if (error != JsonErrorOK) {
            break;
        }
        error = JsonParseComma(jsonPointer);
        if (error != JsonErrorOK) {
            break;
        }

        // "d" : [ 0 ]
        error = JsonParseKey(jsonPointer, NULL, 0);
        if (error != JsonErrorOK) {
            break;
        }
        error = JsonParseArrayStart(jsonPointer);
        if (error != JsonErrorOK) {
            break;
        }
        error = JsonParseNumber(jsonPointer, NULL);
        if (error != JsonErrorOK) {
            break;
        }
        error = JsonParseArrayEnd(jsonPointer);
        if (error != JsonErrorOK) {
            break;
        }

        // }
        error = JsonParseObjectEnd(jsonPointer);
        if (error != JsonErrorOK) {
            break;
        }
    }
    if (error != expectedError) {
        return 1;
    }
    return 0;
}

static void TestParsePartial(void) {
    Assert(CheckParsePartial("[0,{\"x\":0},0]"), "Parse partial without whitespace");
    Assert(CheckParsePartial("[" WS "0" WS "," WS "{" WS "\"x\"" WS ":" WS "0}" WS "," WS "0]"), "Parse partial with whitespace");
}

static int CheckParsePartial(const char *json) {
    const char **const jsonPointer = &json;

    // [
    if (JsonParseArrayStart(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // 0 ,
    if (JsonParseNumber(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseComma(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // { "x" : 0 } ,
    if (JsonParse(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    if (JsonParseComma(jsonPointer) != JsonErrorOK) {
        return 1;
    }

    // 0
    if (JsonParseNumber(jsonPointer, NULL) != JsonErrorOK) {
        return 1;
    }

    // ]
    if (JsonParseArrayEnd(jsonPointer) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

//------------------------------------------------------------------------------
// End of file
