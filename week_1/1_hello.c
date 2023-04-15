/*  Завдання:
    Напішіть програму яка запитує у користувача його ім'я, 
    а потім виводить hello, такий-то, де такий-то -- ім’я користувача. 
*/
#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    string name = get_string("What your name? \n");
    printf("hello, %s\n", name);
}
