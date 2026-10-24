#include <stdio.h>
#include <stdbool.h>

int main(){
    int high = 0;

    do{
        printf("Please give me the high of the building:");
        scanf("%d",&high);
        if (high > 0){
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
        printf("\n");
    }
}
