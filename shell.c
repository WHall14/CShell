#include "headerfile.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/utsname.h>


void remove_newline_ch(char *line) {//strtok puts a \n on strings, this removes it
    size_t new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}

void read_line(char **line){ // passed by ref as we have to eventually free it
    *line = NULL;
    size_t len = LEN;
    getline(*&line, &len, stdin);
}

void parse_line(char **line, char **command, char **vals){
    char* i = *line;
    if(i[3] == ' '){
        i[3] = '_';
    }else if(i[4] == ' '){
        i[4] = '_';
    }
    *command = strtok(i, "_");
    remove_newline_ch(*command);
    *vals = strtok(NULL, "_");
    if(*vals != NULL){
        remove_newline_ch(*vals);
    }
}


void runcommand(char **command, char **vals, int* check){
    if(strcmp(*command, "calc") == 0) {
        printf("%s\n", *vals);
        setN();
        printf("%d\n", recursivePrefix(*vals));
    }else if(strcmp(*command, "time") == 0){
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        printf("%s", asctime(tm));
    }else if(strcmp(*command, "path") == 0){
        char size[256];
        getcwd(size, sizeof(size));
        printf("%s\n", size);
    }else if(strcmp(*command, "sys") == 0){
        struct utsname uname_pointer;
        uname(&uname_pointer);
        printf("Machine: %s\n", uname_pointer.sysname);
        printf("Version: %s\n", uname_pointer.machine);
    }else if(strcmp(*command, "put") == 0){
        put(*vals);
    }else if(strcmp(*command, "get") == 0){
        printfile40(vals);
    }else if(strcmp(*command, "quit") == 0){
        *check = 0;
        return;
    }else{
        printf("Bad command\n");
    }
}

int main() {
    int check = 1;
    char *line, *command = NULL, *vals = NULL;
    do {
        printf(">");
        read_line(&line);
        parse_line(&line, &command, &vals);
        runcommand(&command, &vals, &check);
        free(line);
    }while(check);

    return 0;
}
