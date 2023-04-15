#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    // створити рядок і зберігти туди те що введе користувач
    string name = get_string("What your name? \n");
    // друкує отриману від користувача інформацію
    printf("hello, %s\n", name);
}