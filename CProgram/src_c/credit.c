#include <stdio.h>

int main(){

    long long ID;
    int len = 0;

    //1.input the card
    fst:
    printf("Please input the number of your credit card:\n");
    scanf("%lld", &ID);

    long long temp_1 = ID;
    while(temp_1){
        temp_1 /= 10;
        len++;
    }

    if (!(len == 16 || len == 15 || len == 13)){
        printf("Your numbers of card is wrong.\n");
        goto fst;
    }

    //2.calculate the digit
    int digit = 0;
    int pos = 1;
    long long temp_2 = ID;
    int sum = 0;

    while (pos <= len){

        digit = temp_2 % 10;

        if (pos % 2 != 0){
            sum += digit;
        }else{
            sum += (2 * digit >= 10) ? (2 * digit - 9) : (2 * digit);
        }

        temp_2 /= 10;
        pos++;

    }

    if (sum % 2 != 0){
        printf("Your numbers of card is wrong.\n");
        goto fst;
    }

    //3.catch the frist two number and sort those ID
    long long temp_3 = ID;

    while (temp_3 >= 100){
        temp_3 /= 10;
    }

    if ((len == 15) && (temp_3 == 34 || temp_3 == 37)){
        printf("Your card is MAMEX\n");
    }else if ((len == 16) && (temp_3 == 51 || temp_3 == 55)){
        printf("Your card is MASTERCADE\n");
    }else if ((len == 13 || len == 16) && (temp_3 / 10 == 4)){
        printf("Your card is VISA\n");
    }else{
        printf("INVALID\n");
    }
}

