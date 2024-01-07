#pragma once

#include "fsm_realisation.h"

int Task() {
    /*
    Regular expression for decimal numbers: ^[0-9]+$
    Test: Only one of the numbers 99 and 23 will be in the output. -> 23
    */
    FILE* file = fopen("../tasks/finite_state_machine/tasks/30/input.txt", "r");
    StateMachine* sm = MakeStateMachine();
    char c = ' ';
    printf("START\n");
    while (!feof(file)) {
        char c = fgetc(file);
        if (Step(sm, c) == 1) {
            break;
        }
    }
    printf("\nEND\n");
    fclose(file);
    DeleteStateMachine(sm);
    return 0;
}
