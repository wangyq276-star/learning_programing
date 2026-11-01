#include <stdio.h>
#include <ctype.h>

struct map{
    char key;
    int value;
};

struct map abc[26] = {
    {'A',1},{'B',3},{'C',3},{'D',2},
    {'E',1},{'F',4},{'G',2},{'H',4},
    {'I',1},{'J',8},{'K',5},{'L',1},
    {'M',3},{'N',1},{'O',1},{'P',3},
    {'Q',10},{'R',1},{'S',1},{'T',1},
    {'U',1},{'V',4},{'W',4},{'X',8},
    {'Y',4},{'Z',10}
};

unsigned short score(const char * input);

int main(){
    unsigned short score_1;
    unsigned short score_2;

    score_1 = score("Player 1:");
    score_2 = score("Player 2:");

    if (score_1 > score_2){
        printf("Player 1 wins!");
    }else if(score_2 > score_1){
        printf("Player 2 wins!");
    }else{
        printf("Tie!");
    }


}

unsigned short score(const char * input){
    printf("%s",input);
    unsigned short total = 0;
    char ch;
    while ((ch = toupper(getchar())) != '\n'){
        for(int i = 0; i < 26; i++){
            if (abc[i].key == ch){
                total += abc[i].value;
            }
        }
    }
    return total;
}

