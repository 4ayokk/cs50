#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    float dollars;
    do{
        dollars = get_float("Change owed: ");
    }while(dollars <= 0);

    int coins = round(dollars * 100);
    int answer = 0;

    if(coins >= 25) {
        answer += coins / 25;
        coins %= 25;
    } 
    if(coins >= 10) {
        answer += coins / 10;
        coins %= 10;
    }
    if(coins >= 5) {
        answer += coins / 5;
        coins %= 5;
    }
    answer += coins;
    coins -= coins;

    printf("%d \n", answer);
}