#ifndef PREFIXCALC_H
#define PREFIXCALC_H
#include <stdio.h>
#include <string.h>

#define LEN 32




int unlink_cb(const char *fpath, __attribute__((unused)) const struct stat *sb, __attribute__((unused)) int typeflag,
              __attribute__((unused)) struct FTW *ftwbuf);
int removeDir(char *path);
void printfile40(char **file);
void put(char *string);

int recursivePrefix(char *a);
void setN();


#endif //PREFIXCALC_H
