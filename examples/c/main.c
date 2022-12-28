#include "../../ctest.h"
 char* alphabet = "abcdefghijklmnopqrstuvwxyz";
#include <string.h>

void otherCommands()
{
    tFailDump("Example Dump  (Fail)", alphabet, strlen(alphabet));
    tPassDump("Example Dump  (Pass)", alphabet, strlen(alphabet));
    tFailMsg("Failure Message");
    tPassMsg("Pass Message");
}

void unitTest()
{
    tCase("Example Test");

    // Demonstrate a test passing
    tAssert(1==1, "Test Assertion (Pass)");
    otherCommands();
    
    // Demonstrate a test failing
    tAssert(1==2, "Test Assertion (Fail)");
    otherCommands();

    tFinishTest();
}

int main()
{
    unitTest();
    tPrintTotalScore();
}