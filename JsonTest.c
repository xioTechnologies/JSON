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
#define WS " \n\r\t \n\r\t"

//------------------------------------------------------------------------------
// Function declarations

static void Assert(const int result, const char *const message);

static void TestParseType();

static int CheckParseType(const char *json, const JsonType expectedType);

static void TestTestParseTypeError();

static int CheckTestParseTypeError(const char *json, const JsonError expectedError);

static void TestParseString();

static int CheckParseString(const char *json, const char *const expectedString, const size_t expectedStringSize);

static void TestParseStringError();

static int CheckParseStringError(const char *json, const JsonError expectedError);

static void TestParseNumber();

static int CheckParseNumber(const char *json, const float expectedNumber);

static void TestParseNumberError();

static int CheckParseNumberError(const char *json, const JsonError expectedError);

static void TestParseBoolean();

static int CheckParseBoolean(const char *json, const bool expectedBoolean);

static void TestParseBooleaneError();

static int CheckParseBooleanError(const char *json, const JsonError expectedError);

static void TestParseNull();

static int CheckParseNull(const char *json);

static void TestParseNullError();

static int CheckParseNullError(const char *json, const JsonError expectedError);

static void TestParse();

static int CheckParse(const char *json);

static void TestParseError();

static int CheckParseError(const char *json, const JsonError expectedError);

static void TestParseDefinedObjectOfString();

static int CheckParseDefinedObjectOfString(const char *json);

static void TestParseDefinedObjectOfNumber();

static int CheckParseDefinedObjectOfNumber(const char *json);

static void TestParseDefinedObjectOfObject();

static int CheckParseDefinedObjectOfObject(const char *json);

static void TestParseDefinedObjectOfArray();

static int CheckParseDefinedObjectOfArray(const char *json);

static void TestParseDefinedObjectOfBooleanTrue();

static int CheckParseDefinedObjectOfBooleanTrue(const char *json);

static void TestParseDefinedObjectOfBooleanFalse();

static int CheckParseDefinedObjectOfBooleanFalse(const char *json);

static void TestParseDefinedObjectOfNull();

static int CheckParseDefinedObjectOfNull(const char *json);

static void TestParseDefinedObjectOfAllTypes();

static int CheckParseDefinedObjectOfAllTypes(const char *json);

static void TestParseDefinedObjectError();

static int CheckParseDefinedObjectError(const char *json, const JsonError expectedError);

static void TestParsePartial();

static int CheckParsePartial(const char *json);

//------------------------------------------------------------------------------
// Variables

static int passCount;
static int failCount;

//------------------------------------------------------------------------------
// Functions

int JsonTest() {
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

static void TestParseType() {
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

static void TestTestParseTypeError() {
    Assert(CheckTestParseTypeError("", JsonErrorInvalidSyntax), "Parse type error invalid syntax");
}

static int CheckTestParseTypeError(const char *json, const JsonError expectedError) {
    JsonType type;
    if (JsonParseType(&json, &type) != expectedError) {
        return 1;
    }
    return 0;
}

static void TestParseString() {
    Assert(CheckParseString("\" !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~\"", " !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~", 94), "Parse string all valid characters");
    Assert(CheckParseString("\" \\\" \\\\ \\/ \\b \\f \\n \\r \\t \"", " \" \\ / \b \f \n \r \t ", 18), "Parse string non hex escape sequences");
    Assert(CheckParseString("\" \\u0041\\u0042\\u0043 \"", " ABC ", 6), "Parse string hex escape sequences for valid characters");
    Assert(CheckParseString("\" \\u004a\\u004b\\u004c \"", " JKL ", 6), "Parse string hex escape sequences lower");
    Assert(CheckParseString("\" \\u004A\\u004B\\u004C \"", " JKL ", 6), "Parse string hex escape sequences upper");
    Assert(CheckParseString("\" \\u1141\\u2242\\u3343 \"", " ABC ", 6), "Parse string hex escape sequences non zero upper nibble");
    Assert(CheckParseString("\" \\uFFFF \"", " \xFF ", 4), "Parse string hex escape sequences FFFF");
    Assert(CheckParseString("\" ABC\\u0000DEF \"", " ABC\0DEF ", 10), "Parse string including null hex escape sequence");
}

static int CheckParseString(const char *json, const char *const expectedString, const size_t expectedStringSize) {
    char string[128];
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

static void TestParseStringError() {
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
    Assert(CheckParseStringError("\"\x7F\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x7F");
    Assert(CheckParseStringError("\"\x80\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x80");
    Assert(CheckParseStringError("\"\x81\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x81");
    Assert(CheckParseStringError("\"\x82\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x82");
    Assert(CheckParseStringError("\"\x83\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x83");
    Assert(CheckParseStringError("\"\x84\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x84");
    Assert(CheckParseStringError("\"\x85\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x85");
    Assert(CheckParseStringError("\"\x86\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x86");
    Assert(CheckParseStringError("\"\x87\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x87");
    Assert(CheckParseStringError("\"\x88\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x88");
    Assert(CheckParseStringError("\"\x89\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x89");
    Assert(CheckParseStringError("\"\x8A\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x8A");
    Assert(CheckParseStringError("\"\x8B\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x8B");
    Assert(CheckParseStringError("\"\x8C\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x8C");
    Assert(CheckParseStringError("\"\x8D\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x8D");
    Assert(CheckParseStringError("\"\x8E\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x8E");
    Assert(CheckParseStringError("\"\x8F\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x8F");
    Assert(CheckParseStringError("\"\x90\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x90");
    Assert(CheckParseStringError("\"\x91\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x91");
    Assert(CheckParseStringError("\"\x92\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x92");
    Assert(CheckParseStringError("\"\x93\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x93");
    Assert(CheckParseStringError("\"\x94\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x94");
    Assert(CheckParseStringError("\"\x95\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x95");
    Assert(CheckParseStringError("\"\x96\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x96");
    Assert(CheckParseStringError("\"\x97\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x97");
    Assert(CheckParseStringError("\"\x98\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x98");
    Assert(CheckParseStringError("\"\x99\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x99");
    Assert(CheckParseStringError("\"\x9A\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x9A");
    Assert(CheckParseStringError("\"\x9B\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x9B");
    Assert(CheckParseStringError("\"\x9C\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x9C");
    Assert(CheckParseStringError("\"\x9D\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x9D");
    Assert(CheckParseStringError("\"\x9E\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x9E");
    Assert(CheckParseStringError("\"\x9F\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\x9F");
    Assert(CheckParseStringError("\"\xA0\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xA0");
    Assert(CheckParseStringError("\"\xA1\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xA1");
    Assert(CheckParseStringError("\"\xA2\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xA2");
    Assert(CheckParseStringError("\"\xA3\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xA3");
    Assert(CheckParseStringError("\"\xA4\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xA4");
    Assert(CheckParseStringError("\"\xA5\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xA5");
    Assert(CheckParseStringError("\"\xA6\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xA6");
    Assert(CheckParseStringError("\"\xA7\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xA7");
    Assert(CheckParseStringError("\"\xA8\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xA8");
    Assert(CheckParseStringError("\"\xA9\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xA9");
    Assert(CheckParseStringError("\"\xAA\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xAA");
    Assert(CheckParseStringError("\"\xAB\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xAB");
    Assert(CheckParseStringError("\"\xAC\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xAC");
    Assert(CheckParseStringError("\"\xAD\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xAD");
    Assert(CheckParseStringError("\"\xAE\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xAE");
    Assert(CheckParseStringError("\"\xAF\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xAF");
    Assert(CheckParseStringError("\"\xB0\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xB0");
    Assert(CheckParseStringError("\"\xB1\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xB1");
    Assert(CheckParseStringError("\"\xB2\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xB2");
    Assert(CheckParseStringError("\"\xB3\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xB3");
    Assert(CheckParseStringError("\"\xB4\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xB4");
    Assert(CheckParseStringError("\"\xB5\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xB5");
    Assert(CheckParseStringError("\"\xB6\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xB6");
    Assert(CheckParseStringError("\"\xB7\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xB7");
    Assert(CheckParseStringError("\"\xB8\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xB8");
    Assert(CheckParseStringError("\"\xB9\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xB9");
    Assert(CheckParseStringError("\"\xBA\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xBA");
    Assert(CheckParseStringError("\"\xBB\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xBB");
    Assert(CheckParseStringError("\"\xBC\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xBC");
    Assert(CheckParseStringError("\"\xBD\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xBD");
    Assert(CheckParseStringError("\"\xBE\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xBE");
    Assert(CheckParseStringError("\"\xBF\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xBF");
    Assert(CheckParseStringError("\"\xC0\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xC0");
    Assert(CheckParseStringError("\"\xC1\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xC1");
    Assert(CheckParseStringError("\"\xC2\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xC2");
    Assert(CheckParseStringError("\"\xC3\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xC3");
    Assert(CheckParseStringError("\"\xC4\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xC4");
    Assert(CheckParseStringError("\"\xC5\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xC5");
    Assert(CheckParseStringError("\"\xC6\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xC6");
    Assert(CheckParseStringError("\"\xC7\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xC7");
    Assert(CheckParseStringError("\"\xC8\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xC8");
    Assert(CheckParseStringError("\"\xC9\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xC9");
    Assert(CheckParseStringError("\"\xCA\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xCA");
    Assert(CheckParseStringError("\"\xCB\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xCB");
    Assert(CheckParseStringError("\"\xCC\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xCC");
    Assert(CheckParseStringError("\"\xCD\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xCD");
    Assert(CheckParseStringError("\"\xCE\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xCE");
    Assert(CheckParseStringError("\"\xCF\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xCF");
    Assert(CheckParseStringError("\"\xD0\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xD0");
    Assert(CheckParseStringError("\"\xD1\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xD1");
    Assert(CheckParseStringError("\"\xD2\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xD2");
    Assert(CheckParseStringError("\"\xD3\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xD3");
    Assert(CheckParseStringError("\"\xD4\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xD4");
    Assert(CheckParseStringError("\"\xD5\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xD5");
    Assert(CheckParseStringError("\"\xD6\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xD6");
    Assert(CheckParseStringError("\"\xD7\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xD7");
    Assert(CheckParseStringError("\"\xD8\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xD8");
    Assert(CheckParseStringError("\"\xD9\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xD9");
    Assert(CheckParseStringError("\"\xDA\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xDA");
    Assert(CheckParseStringError("\"\xDB\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xDB");
    Assert(CheckParseStringError("\"\xDC\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xDC");
    Assert(CheckParseStringError("\"\xDD\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xDD");
    Assert(CheckParseStringError("\"\xDE\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xDE");
    Assert(CheckParseStringError("\"\xDF\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xDF");
    Assert(CheckParseStringError("\"\xE0\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xE0");
    Assert(CheckParseStringError("\"\xE1\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xE1");
    Assert(CheckParseStringError("\"\xE2\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xE2");
    Assert(CheckParseStringError("\"\xE3\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xE3");
    Assert(CheckParseStringError("\"\xE4\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xE4");
    Assert(CheckParseStringError("\"\xE5\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xE5");
    Assert(CheckParseStringError("\"\xE6\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xE6");
    Assert(CheckParseStringError("\"\xE7\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xE7");
    Assert(CheckParseStringError("\"\xE8\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xE8");
    Assert(CheckParseStringError("\"\xE9\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xE9");
    Assert(CheckParseStringError("\"\xEA\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xEA");
    Assert(CheckParseStringError("\"\xEB\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xEB");
    Assert(CheckParseStringError("\"\xEC\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xEC");
    Assert(CheckParseStringError("\"\xED\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xED");
    Assert(CheckParseStringError("\"\xEE\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xEE");
    Assert(CheckParseStringError("\"\xEF\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xEF");
    Assert(CheckParseStringError("\"\xF0\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xF0");
    Assert(CheckParseStringError("\"\xF1\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xF1");
    Assert(CheckParseStringError("\"\xF2\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xF2");
    Assert(CheckParseStringError("\"\xF3\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xF3");
    Assert(CheckParseStringError("\"\xF4\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xF4");
    Assert(CheckParseStringError("\"\xF5\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xF5");
    Assert(CheckParseStringError("\"\xF6\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xF6");
    Assert(CheckParseStringError("\"\xF7\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xF7");
    Assert(CheckParseStringError("\"\xF8\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xF8");
    Assert(CheckParseStringError("\"\xF9\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xF9");
    Assert(CheckParseStringError("\"\xFA\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xFA");
    Assert(CheckParseStringError("\"\xFB\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xFB");
    Assert(CheckParseStringError("\"\xFC\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xFC");
    Assert(CheckParseStringError("\"\xFD\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xFD");
    Assert(CheckParseStringError("\"\xFE\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xFE");
    Assert(CheckParseStringError("\"\xFF\"", JsonErrorInvalidStringCharacter), "Parse string error invalid character \\xFF");
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

static void TestParseNumber() {
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

static void TestParseNumberError() {
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

static void TestParseBoolean() {
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

static void TestParseBooleaneError() {
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

static void TestParseNull() {
    Assert(CheckParseNull("null"), "Parse null");
}

static int CheckParseNull(const char *json) {
    if (JsonParseNull(&json) != JsonErrorOK) {
        return 1;
    }
    return 0;
}

static void TestParseNullError() {
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

static void TestParse() {
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

static void TestParseError() {
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

static void TestParseDefinedObjectOfString() {
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

static void TestParseDefinedObjectOfNumber() {
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

static void TestParseDefinedObjectOfObject() {
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

static void TestParseDefinedObjectOfArray() {
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

static void TestParseDefinedObjectOfBooleanTrue() {
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

static void TestParseDefinedObjectOfBooleanFalse() {
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

static void TestParseDefinedObjectOfNull() {
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

static void TestParseDefinedObjectOfAllTypes() {
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

static void TestParseDefinedObjectError() {
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

static void TestParsePartial() {
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
