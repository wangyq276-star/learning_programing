#include <stdio.h>

int main(){
    char name[100];
    printf("What\'s your name?");
    scanf("%99s",&name);
    printf("hello,%s\n",name);
};
