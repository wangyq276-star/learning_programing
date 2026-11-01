#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

void secret(string ansr,int key);
int check(int argc,char * argv[]);

int main(int argc,char * argv[]){
    if(check(argc,argv)){return 1;}

    int key = atoi(argv[1]);

    string ansr = get_string("plaintext:  ");
    secret(ansr,key);

    printf("ciphertext: %s",ansr);
    return 0;
}

int check(int argc,char * argv[]){
    if(argc != 2){
        printf("Usage: ./caesar key");
        return 1;
    }
    for(int i = 0; i < strlen(argv[1]); i++){
        if(! isdigit(argv[1][i])){
            printf("Usage: ./caesar key");
            return 1;
        }
    }
    return 0;
}

void secret(string ansr,int key){
    for(int i = 0; i < strlen(ansr); i++){
        if(65 <= ansr[i] && ansr[i] <= 90){
            ansr[i] = (ansr[i] - 65 + key) % 26 + 65;
        }else if(97 <= ansr[i] && ansr[i] <= 122){
            ansr[i] = (ansr[i] - 97 + key) % 26 + 97;
        }
    }
}
