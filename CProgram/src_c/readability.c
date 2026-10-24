#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

double L_S(const char * text,int len,char c);

int main(){
    char text[100000];

    printf("Text:");
    scanf("%[^\n]s",text);
    int len = strlen(text);

    int index = round(0.0588 * L_S(text,len,'L') - 0.296 * L_S(text,len,'S') - 15.8);
    
    if (index <= 0){
        printf("Before Grade 1");
    }else if(index > 16){
        printf("Grade 16+");
    }else{
        printf("Grade %d",index);
    }
}

double L_S(const char * text,int len,char c){

    short flag = 0;
    unsigned long letr = 0;
    unsigned long word = 0;
    unsigned int sente = 0;

    for(int i = 0; i < len; i++){
        if(text[i] == ' '){
            flag = 0;
        }else if(65 <= toupper(text[i]) && toupper(text[i]) <= 90 && flag == 0){
            flag = 1;
            word++;
        }

        if(65 <= toupper(text[i]) && toupper(text[i]) <= 90){
            letr++;
        }
        if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            sente++;
        }
    }

    if (toupper(c) == 'L'){
        return (double)letr * 100 / word;
    }else if(toupper(c) == 'S'){
        return (double)sente * 100 / word;
    }
    return 0;
}


