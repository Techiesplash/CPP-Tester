#include "../../test.h"
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
    tFailDump("Example Dump  (Fail)", alphabet, strlen(alphabet));
    tPassDump("Example Dump  (Pass)", alphabet, strlen(alphabet));
    tFailMsg("Failure Message");
    tPassMsg("Pass Message");
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
        tAssert(1==1, "Test Assert (Pass)");
        otherCommands();
        tAssert(1==2, "Test Assert (Fail)");
        otherCommands();
        // Can pass args through these funcs
        //          Ret   Exception          Func      Name
        tException<void, std::out_of_range>(ThrowsEx, "Test Exception (Pass)");
        tException<void, std::invalid_argument>(ThrowsEx, "Test Exception (Fail, incorred)");
        tException<void, std::out_of_range>(NoEx, "Test Exception (Pass, none)");
        tNoException<void>(ThrowsEx, "Test NoException (Fail)");
        tNoException<void>(NoEx, "Test NoException (Pass)");
    });
};

// Also auto-register
TestField field("Test Field");

int main()
{
    tRunTests(false);
}