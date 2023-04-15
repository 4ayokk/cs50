/*  
    Завдання:
    Напішіть програму яка запитує у користувача число від 1 до 8,
    а після друкує піраміду заданої висоти,
    
    Якщо користувач не ввів додатне ціле число від 1 до 8 включно, 
    програма має продовжувати запитувати число, поки користувач його не введе.
    Приклад якщо height = 4:
       #
      ##
     ###
    ####
*/
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // змінна яка зберігатиме введене число
    int height;
    // цикл який виконуватименься до поки користувач не введе правильне число
    do{
        height = get_int("height(1 - 8)\n");
    }while(height < 1 || height > 8);
    
    // Цикл який відповідає за кількість рядків
    for(int i = 0; i < height; ++i) {
        // визначаєм скільки # буде у і-му рядку
        int hash_counter = i+1;
        // Визначаєм скільки ' ' буде у і-му рядку
        int space_counter = height - hash_counter;
        
        // Цикл який друкує пробіли
        for(int space = 0; space < space_counter; ++space){
            printf(" ");
        }
        // Цикл який друкує #
        for(int hash = 0; hash < hash_counter; ++hash){
            printf("#");
        }
        // коли рядок надруковано програма повинна перейти на новий
        printf("\n");
    }
}