// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int count_by(int start, int count)
{
  int result = start;

    for(int i = 0; i < 10; i++)
    {
      int result = result + count;
    }
  return result;
  printf("%d", result);
}

int main(int argc, char* argv[])
{
  int start;
  int count;

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork versagt\n");
    exit(1);
  } else if (rc == 0) {
    execvp("/bin/ls");
  } else {
    int wc = waitpid(rc, NULL, 0);
    printf("Enter a starting point and number by which we will increment:\n");
    scanf("%d %d", &start, &count);
    count_by(start, count);
  }
    return 0;
}
