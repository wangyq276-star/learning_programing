#include <stdio.h>
#include <stdbool.h>

int main(){
    int high = 10;

    do{

        printf("Please give me the high of the building\n(between 1 and 8):");
        scanf("%d",&high);

        if (1 <= high && high <= 8){
            break;
        }else{
            printf("Your answer is wrong.\n");
        }
    }while(true);


    for(int i = 0; i < high; i++){
        int x = high-1-i,y = i+1;
        while(x--){
            printf(" ");
        }
        while(y--){
            printf("#");
        }

        x = high-1-i,y = i+1;
        printf(" ");
        while(y--){
            printf("#");
        }
        while(x--){
            printf(" ");
        }
        printf("\n");
    }
}

