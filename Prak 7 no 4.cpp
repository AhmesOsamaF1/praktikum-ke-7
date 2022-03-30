#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;

void push(char);
char pop();

char stack[100];
int top = -1;

main() {
    char str[100];
    int i, count = 0, len;

    cout<<"Masukan sebuah string : "; gets(str);
    len = strlen(str);
    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    for (i = 0; i < len; i++) {
        if (str[i] == pop())
            count++;
    }

    if (count == len)
        cout<<"Kalimat tersebut adalah palindrom"<<endl;
    else
        cout<<"Kalimat tersebut bukan palindrom"<<endl;
        getch();
}

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return(stack[top--]);
}
