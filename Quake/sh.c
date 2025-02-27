#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define asize(A) (sizeof(A) / sizeof(*A))
#define SHELL "powershell.exe"

int main(int argc, char** argv) {
    char args[2056];
    for (int i = 1; i < argc; i++) {
        strcat_s(args, asize(args), argv[i]);
        strcat_s(args, asize(args), " ");
    }

    char cmd_buf[2056];

    snprintf(cmd_buf, asize(cmd_buf), SHELL " %s", args);
    
    int result = system(cmd_buf);
    
    return result;
}
