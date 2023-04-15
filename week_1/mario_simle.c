#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do{
        height = get_int("height(1 - 8)\n");
    }while(height<1 || height > 8);
    for(int i = 0; i < height; ++i){
        int hash_counter = i+1;
        int space_counter = height - hash_counter;
        for(int space = 0; space < space_counter; ++space){
            printf(" ");
        }
        for(int hash = 0; hash < hash_counter; ++hash){
            printf("#");
        }
        printf("\n");
    }
}