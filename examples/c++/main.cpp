#include "../../microtest.h"
#include <exception>
#include <string.h>

char *alphabet = "abcdefghijklmnopqrstuvwxyz";
// Anything you can do in C can be done here; this is just another way

void ThrowsEx()
{
    throw std::out_of_range("Test");
}

void NoEx()
{
}

void otherCommands()
{
    utFailDump("Example Dump  (Fail)", alphabet, strlen(alphabet));
    utPassDump("Example Dump  (Pass)", alphabet, strlen(alphabet));
    utFailMsg("Failure Message");
    utPassMsg("Pass Message");
}

// Demonstrate OO Features
class TestField : UnitField
{
    using UnitField::UnitField;

    void Setup()
    {
        puts("Setup");
    }

    void Teardown()
    {
        puts("Teardown");
    }

    // Unit tests here auto-register
    UnitTest sampleTest = UnitTest("Sample Test", []() {
        utAssert(1==1, "Test Assert (Pass)");
        otherCommands();
        utAssert(1==2, "Test Assert (Fail)");
        otherCommands();
        // Can pass args through these funcs
        //          Ret   Exception          Func      Name
        utException<void, std::out_of_range>(ThrowsEx, "Test Exception (Pass)");
        utException<void, std::invalid_argument>(ThrowsEx, "Test Exception (Fail, incorred)");
        utException<void, std::out_of_range>(NoEx, "Test Exception (Pass, none)");
        utNoException<void>(ThrowsEx, "Test NoException (Fail)");
        utNoException<void>(NoEx, "Test NoException (Pass)");
    });
};

// Also auto-register
TestField field("Test Field");

int main()
{
    utRunTests(false);
}