#include <stdio.h>

#include "Onegin.h"
#include "Stack.h"

#define CASE_SIGN(sign)                                             \
                                                                    \
    else if (CmpCommand(str, sign)) {                               \
        if(stack_ptr->size <= 1) {                                  \
            printf("This command is impossible\n");                 \
        }else {                                                     \
                                                                    \
        Stack_t val_1   = 0,                                        \
                val_2   = 0;                                        \
        Stack_t val = 0;                                            \
                                                                    \
        val_1   = StackPop(stack_ptr, inf_st);                      \
        val_2   = StackPop(stack_ptr, inf_st);                      \
        val     = CalcSign(val_1,val_2, sign);                      \
                                                                    \
        if (val == DIV_NONE) {                                      \
            printf("Sorry, you can't div 0\n");                     \
            StackPush(stack_ptr, val_2, inf_st);                    \
            StackPush(stack_ptr, val_1, inf_st);                    \
        }                                                           \
                                                                    \
        else StackPush(stack_ptr, val, inf_st);                     \
        }                                                           \
    }

void  Interp(Stack *stack_ptr, INFO_STACK);

int CommandStack(char *str, Stack *stack_ptr, INFO_STACK);

bool CmpCommand(char *str, const char *command);

Stack_t CalcSign(const Stack_t val_1, const Stack_t val_2, const char *str);