#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include "CPU.h"

#define FINISH   999
#define CONTINUE 9999

void Interp(Stack *stack_ptr, INFO_STACK) {
    
    ASSERT_OK(stack_ptr, inf_st)

    char str[6];
    int res = 0;

    do{
        scanf("%s", str);
        res = CommandStack(str, stack_ptr, inf_st);
        if (res == FINISH) break;

        StackPrint(*stack_ptr, inf_st);
    }while(CONTINUE);
}

int CommandStack(char *str, Stack *stack_ptr, INFO_STACK) {

    if (CmpCommand(str, "size")) {

        printf("size_stack = %d\ncompacity  = %d\n", stack_ptr->size,
                                                     stack_ptr->capacity);
    }else if (CmpCommand(str, "push")) {
        
        Stack_t value = 0;
        scanf("%d", &value);
        StackPush(stack_ptr, value, inf_st);
    }else if (CmpCommand(str, "pop")) {

        if (stack_ptr->size <= 0) {
            printf("You can't take an element, because stack is empty\n");
        }else {
        
        StackPop(stack_ptr, inf_st);
        }
    }
    CASE_SIGN("+")
    CASE_SIGN("-")
    CASE_SIGN("*")
    CASE_SIGN("/")

    else if (CmpCommand(str, "finish")) {
        return FINISH;
    }
    else {
        printf ("There isn't so command, please can you try else\n");
    }

    return CONTINUE;
}

bool CmpCommand(char *str,  const char *command) {
    
    int i = 0;

    while (command[i] != '\0') {
        if (command[i] != str[i])
            return 0;
        ++i;
    }

    if(str[i] == '\0')
        return 1;
    return 0;
}

Stack_t CalcSign(const Stack_t val_1, const Stack_t val_2, const char *str) {

    if (str[0] == '/') {
        if (val_2 == 0)
            return DIV_NONE;
        else return val_1 / val_2;
    }
    else if (str[0] == '+') return val_1 + val_2;
    else if (str[0] == '-') return val_1 - val_2;
    else if (str[0] == '*') return val_1 * val_2;

    return 0;
}

#undef FINISH
#undef CONTINUE