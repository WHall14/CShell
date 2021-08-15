#include "headerfile.h"

int n;
void setN(){
    n = 0;
}

int recursivePrefix(char *a){
    int x = 0;
    if(n > strlen(a)){
        return x;
    }
    while (a[n] == ' ') {
        n++;
    }
    if (a[n] == '+'){
        n++;
        int operand1 = recursivePrefix(a);
        n++;
        int operand2 = recursivePrefix(a);
        return operand1 + operand2;
    }else if (a[n] == '-'){
        n++;
        int operand1 = recursivePrefix(a);
        n++;
        int operand2 = recursivePrefix(a);
        return operand1 - operand2;
    }
    while ((a[n] >= '0') && (a[n] <= '9')){
        x = 10*x + (a[n++] - '0'); // changes value from a ascii alphabet value to a number
    }
    return x;
}
