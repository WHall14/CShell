#include <ftw.h>
#include "headerfile.h"


int unlink_cb(const char *fpath, __attribute__((unused)) const struct stat *sb, __attribute__((unused)) int typeflag,
              __attribute__((unused)) struct FTW *ftwbuf){
    int rv = remove(fpath);
    if (rv) perror(fpath); // attempts to remove rv if it cant it returns it
    return rv;
}

int removeDir(char *path){
    return nftw(path, unlink_cb, 64, FTW_DEPTH | FTW_PHYS); //using nftw to traverse a file tree
    //FTW_DEPTH visits subdirectories before itself and FTW_PHYS only goes to physical directories not symbolic links
}

void printfile40(char **file){
    size_t len = LEN;
    FILE *fp;
    fp = fopen(*file, "r");
    if(fp == NULL){
        printf("File Doesn't Exist\n");
        return;
    }
    int check = 1;
    while (check){
        for (int i = 0; i < 40; ++i) {
            if(getline(*&file, &len, fp) == 1){
                check = 0;
                break;
            }
            printf("%s",*file);
        }
        if(check){
            getchar();
        }
    }
    fclose(fp);
}

void put(char *string){
    struct stat st = {0};
    char buffer[255], buffer2[255];
    strcpy(buffer, string);
    char * token = strtok(buffer, " ");
    char *dir = token;



    int fcheck = 0;
    token = strtok(NULL, " ");
    while (token != NULL){
        if(strcmp(token, "-f") == 0){
            fcheck = 1;
            token = strtok(NULL, " ");
            if (token != NULL){
                printf("Syntax Error, Not allowed strings after -f\n");
                return;
            }
        }
        token = strtok(NULL, " ");
    }


    strcpy(buffer, string);
    token = strtok(buffer, " ");

    if(fcheck == 1 && stat(token, &st) != -1){
        removeDir(token);
        mkdir(token, 0700);
    }else if(stat(token, &st) != -1 && fcheck == 0){
        printf("Directory exists and -f not specified\n");
        return;
    }else{
        mkdir(token, 0700);
    }

    token = strtok(NULL, " ");
    while (token != NULL){
        if(strcmp(token, "-f") == 0){
            break;
        }
        FILE *sfp = fopen(token, "r");// only wanna read from file
        if(sfp == NULL){
            printf("Following file does not exist: %s\n", token);
            token = strtok(NULL, " ");
            continue;
        }


        strcpy(buffer2, dir);
        strcat(buffer2, "/");
        strcat(buffer2, token); // this is the new file name with the new path concatenated
        FILE *dfp = fopen(buffer2, "w"); // only wanna write

        int ch;
        while( (ch=fgetc(sfp)) != EOF){
            fputc(ch,dfp);
        }
        fclose(dfp);
        remove(token);


        token = strtok(NULL, " ");
    }


}
