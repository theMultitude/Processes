// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


int mult (int a)
{
  int r = a * 100;
  return r;
}

int main(int argc, char *argv[])
{
    int x = 100;

    int first = mult(x);
    printf("%d\n", first);

    int child = fork();
    if (child < 0) {
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (child == 0) {
      int kid = mult(x);
      printf("X is %d\n", kid);
    } else {
      int par = mult(x);
      printf("X is %d\n", par);
    }
    return 0;
}
