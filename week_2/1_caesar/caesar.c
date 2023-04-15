// Підкулючаєм необхідні бібліотеки 
#include <stdio.h>
#include <cs50.h>

// прототипи власних функцій
string caesar_encrypt(string str, int k);
int str_to_int(string str);
bool is_upper_leter(char c);
bool is_lower_leter(char c);
int str_len(string str);

int main(int argc, string argv[]) {
    // Перевіряєм  кількість і валідність аргументів
    if(argc == 2 && str_to_int(argv[1]) != 0){
        string message = get_string("Enter message: ");
        // зашифрувати повідомлення і вивести в консоль
        printf("ciphertext: %s\n", caesar_encrypt(message, str_to_int(argv[1])));
        // програма завершилась успішно
        return 0;
    } else {
        printf("Usage: ./caesar key\n");
        // програма завершилась з помилкую
        return 1;
    }
    
}

string caesar_encrypt(string str, int k) {
    // По символьно шифрує ОРИГІНАЛЬНИЙ рядок шифром цезаря
    // не шифрує цифри, пробіли, та інші символи, тільки великі і малі літери.
    int str_start = 0;
    int str_end = str_len(str);
    for(int i = str_start; i != str_end; i++) {
        if(is_upper_leter(str[i])) {
            str[i] = (str[i] - 'A' + k) % 26 + 'A';
        } else if(is_lower_leter(str[i])) {
            str[i] = (str[i] - 'a' + k) % 26 + 'a';
        }
    }
    return str;
}

int str_to_int(string str) {
    // Перетворює рядок в число якщо там тільки цифри інакше вертає 0
    int start = str_len(str) - 1;
    int end = -1;
    int number = 0;
    for(int i = start, d_bit = 1; i != end; i--, d_bit *= 10) {
        if(str[i] < '0' || str[i] > '9') {
            return 0;
        }
        number += (str[i] - '0') * d_bit;
    }
    return number;
}

bool is_upper_leter(char c) {
    // Якщо передано ВЕЛИКУ літеру вертає true інакше false
    return c >= 'A' && c <= 'Z';
}

bool is_lower_leter(char c) {
    // Якщо передано МАЛУ літеру вертає true інакше false
    return c >= 'a' && c <= 'z';
}

int str_len(string str) {
    // Повертає кількість символів у рядку
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}
