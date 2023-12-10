#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main (int argc, char *args[])
{
    if (argc <2 ){
        fprintf(stderr, "Usage %s <file 1> <file 2> ... <file 3>", args[0]);
    }

    for(int i=1; i<argc; i++){
        const char *filename = args[i];
        struct stat file_stat;

        if(stat(filename, &file_stat)==-1)
        {
            fprintf(stderr, "Could not open file %s\n", filename);
        }

        printf("file: %s\n", filename);
        printf("size: %ld\n", file_stat.st_size);
        printf("Inode Number: %lu\n\n", (unsigned long)file_stat.st_ino);
    }
}