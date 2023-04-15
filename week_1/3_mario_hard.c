/*  
    Завдання:
    Напішіть програму яка запитує у користувача число від 1 до 8,
    а після друкує дві пів-піраміди заданої висоти,
    
    Якщо користувач не ввів додатне ціле число від 1 до 8 включно, 
    програма має продовжувати запитувати число, поки користувач його не введе.
    Відстань між пірамідами 2 хеші
    
    Приклад якщо height = 4:
       #  #
      ##  ##
     ###  ###
    ####  ####
*/

#include <cs50.h>
#include <stdio.h>

void print_sumbols(char, int);
void print_pyramide(int);

int main(void)
{   
    // Створити змінну яка зберігатиме висоту
    int height;
    
    // Цикл виконуватиметься до поки користувач не введе правильні дані
    do{
        // get_int вертає число введене користувачем
        height = get_int("Height: ");
    }while(height < 1 || height > 8);
    
    // Надрукувати пірамідки заданої висоти
    print_pyramide(height);
}


void print_sumbols(char c, int count) {
    // функція яка друкує символ с задану кількість разів count
    for(int i = 0; i < count; i++){
        printf("%c", c);
    }
}

void print_pyramide(int height) {
    // друкує 2 пів піраміди заданої висоти
    
    //цикл відповідає за кількість рядків
    for(int r = 0; r < height; r++) {
        // Визначаєм кількість # у і-му рядку пів піраміди
        int hashes = r + 1;
        // изначаєм кількість пробілів у і-му рядку пів піраміди
        int spaces = height - hashes;
        
        // друкуєм...
        print_sumbols(' ', spaces);
        print_sumbols('#', hashes);
        print_sumbols(' ', 2);
        print_sumbols('#', hashes);
        print_sumbols('\n', 1);
    }
}
