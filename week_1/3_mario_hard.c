#include <cs50.h>
#include <stdio.h>

void print_sumbols(char, int);
void print_pyramide(int);

int main(void)
{   
    int height;
    do{
        height = get_int("Height: ");
    }while(height < 1 || height > 8);

    print_pyramide(height);
}

void print_sumbols(char c, int count){
    for(int i = 0; i < count; i++){
        printf("%c", c);
    }
}

void print_pyramide(int height) {
    for(int r = 0; r < height; r++){
        int hashes = r + 1;
        int spaces = height - hashes;

        print_sumbols(' ', spaces);
        print_sumbols('#', hashes);
        print_sumbols(' ', 2);
        print_sumbols('#', hashes);
        print_sumbols('\n', 1);
    }
}
