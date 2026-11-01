#include <stdio.h>

int main(){
    int money = 0;
    int coins[4] = {25, 10, 5, 1};
    do{
        printf("Please give me the money:");
        scanf("%d",&money);
        if (money > 0){
            break;
        }else{
            printf("Your answer is wrong.\n");
        }
    }while(1);
    for(int i = 0; i < (sizeof coins / sizeof coins[0]); i++){
        printf("%d $%d\n",((int)money/coins[i]),(coins[i]));
        money = money % coins[i];
    }


}
