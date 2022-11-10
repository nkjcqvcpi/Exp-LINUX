#include "stdio.h"
#include "sys/types.h"
#include "unistd.h"

int main(void){
    pid_t pid1, pid2, pid3;
    pid1 = fork();
    pid2 = fork();
    pid3 = fork();
    printf("pid1: %d, pid2: %d, pid3: %d\n", pid1, pid2, pid3);
    return 0;
}