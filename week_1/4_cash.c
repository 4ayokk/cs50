// Файли через які підключаються необхідні функції
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    // Змінна яка зберігатиме введені користувачем дані
    float dollars;
    
    // цикл повторюватиметься до поки користувач не введе коректні дані
    do{
        dollars = get_float("Change owed: ");
    }while(dollars <= 0);
    
    // Конвертуєм долари в центи і округляєм за допомогою round
    int coins = round(dollars * 100);
    // Змінна яка зберігтиме кількість монет
    int answer = 0;
    
    // Реалізація жадібного алгоритму
    // * else if в даному випадку не підходить 
    // * тому що цей оператор припиняється щойно виконається одна із умов
    // * але в даному випадку треба щоб перевірялась кожна умова щоразу.
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
