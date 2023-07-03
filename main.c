#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Project header.h"

int main(){
    
    puts("\nStarting the CPSC 1070 Anti-Spam and Anti-Phishing Detector...");
    puts("Opening myemail.txt file...done.");
    puts("Comparing myemail.txt against key SPAM phrases...done.");
    puts("Comparing myemail.txt against key phishing phrases...done.");

    ProcessSpamPhish();
    
    puts("The following words were misspelled:");
    ProcessSpellCheck();

    puts("Program is ending.");
    
    return 0;
}
