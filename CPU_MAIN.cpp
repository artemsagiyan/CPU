#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "CPU.h"

#define INPUT_FILE  argv[1]
#define OUTPUT_FILE "result_commands"

int main(int argc, const char *argv[]) {

    assert(argc == 2);
    
    Stack st   = {};
    Info  info = {};

    FILE *file_in  = fopen(INPUT_FILE,  "r"),
         *file_out = fopen(OUTPUT_FILE, "a");

    info = {
        .File = file_in
    };

    StackCtor(&st, &info);

    Interp(&st, &info);

    StackPrint(st, &info);

    fclose(file_in);
    fclose(file_out);
}

#undef INPUT_FILE
#undef OUTPUT_FILE