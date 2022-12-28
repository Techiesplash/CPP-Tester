#include "../../microtest.h"
 char* alphabet = "abcdefghijklmnopqrstuvwxyz";
#include <string.h>

void otherCommands()
{
    utFailDump("Example Dump  (Fail)", alphabet, strlen(alphabet));
    utPassDump("Example Dump  (Pass)", alphabet, strlen(alphabet));
    utFailMsg("Failure Message");
    utPassMsg("Pass Message");
}

void unitTest()
{
    utCase("Example Test");

    // Demonstrate a test passing
    utAssert(1==1, "Test Assertion (Pass)");
    otherCommands();
    
    // Demonstrate a test failing
    utAssert(1==2, "Test Assertion (Fail)");
    otherCommands();

    utFinishTest();
}

int main()
{
    unitTest();
    utPrintTotalScore();
}