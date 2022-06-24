#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    char* oldpath;
    char* newpath;

    if(argc < 3 || argc > 4){
        printf("Usage: ln old new OR ls -s old new\n");
        exit(0);
    }
    if (strcmp(argv[1],"-s")) {
        if (link(argv[1], argv[2]) < 0) {
            printf("link %s %s: failed\n", argv[1], argv[2]);
        }
        exit(0);
    }
    oldpath = argv[2];
    newpath = argv[3];
    if (symlink(oldpath, newpath) != 0) {
        printf("symlink %s %s: failed\n", oldpath, newpath);
    }

    exit(0);
}
