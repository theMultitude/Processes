// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE * nf;
    nf = fopen("./text.txt", "a");

    int fc = fork();
    if (fc < 0) {
      fprintf(stderr, "fork versagt\n");
      exit(1);
    } else if (fc == 0) {
      fprintf(nf, "%s %s %s %s %s %s\n", "Life", "is", "what", "you", "make", "it");
      fclose(nf);
    } else {
      fprintf(nf, "%s %s %s %s\n", "A", "parent", "might", "say");
      fclose(nf);
    }
    return 0;
}
