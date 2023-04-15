#include <stdio.h>
#include <cs50.h>

int main(void){
    long number;
    do{
        number = get_long("Number: ");
    }while(number < 0);

    int sum = 0;
    for(long n = number / 10; n > 0; n /= 100){
        long temp_number = n % 10 * 2;
        sum += temp_number / 10;
        sum += temp_number % 10;
    }
    for(long n = number; n > 0; n /= 100){
        sum += n % 10;
    }
    
    if(sum % 10 == 0 && (number / 10000000000000 == 34 || number / 10000000000000 == 37)){
        printf("AMEX\n");
    } else if(sum % 10 == 0 && (number / 1000000000000 == 4 || number / 1000000000000000 == 4)){
        printf("VISA\n");
    } else if (sum % 10 == 0 && (number / 100000000000000 > 50 &&  number / 100000000000000 < 56)){
        printf("MASTERCARD\n");
    }else {
        printf("INVALID\n");
    }
    return 0;
}