#include <stdio.h>
#include <cs50.h>


string encript_str(string str, const string key);
unsigned int shift_leter(const char c, const char key);
int to_alphabet(const char c);
bool is_valid_key(const string str);
bool is_leter(const char c);
bool is_upper_leter(const char c);
bool is_lower_leter(const char c);
unsigned int str_len(const string str);


int main(int argc, string argv[]) {
    if (argc == 2 && is_valid_key(argv[1])) {
        string key = argv[1];
        string message = get_string ("Enter message \n");
        printf("ciphertext: %s\n", encript_str(message, key));
    } else {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    return 0;
}

string encript_str(string str, const string key) {
    // шифрує рядок шифром Віженера
    int key_len = str_len(key);
    for(int i = 0, j = 0; str[i] != '\0'; i++) {
        if(is_leter(str[i])) {
            char base = is_upper_leter(str[i]) ? 'A' : 'a';
            str[i] = shift_leter(str[i], key[j]) + base;
            j = (j + 1) % key_len;
        }
    }
    return str;
}

unsigned int shift_leter(const char c, const char key) {
    // якщо символ являється літерою зсуває його відносно алфавіту
    // на задану ключем key кількість позицій
    if(is_leter(c))
        return  (to_alphabet(c) + to_alphabet(key)) % 26;
    else return c;
}

int to_alphabet(const char c) {
    // Поертає відстань до літери в алфавіті (рахунок починається з 0)
    // Символ вертається без змін якщо він не являється літерою
    return is_upper_leter(c) ? c - 'A' : is_lower_leter(c) ? c - 'a' : -1;
}

bool is_valid_key(const string str) {
    // якщо в рядку хоча б один символ
    // не являється літерою (A-Z, a-z) вертає false інакше true
    for(int i = 0; str[i] != '\0'; i++)
        if(!is_leter(str[i])) return false;
    return true;
}

bool is_leter(const char c) {
    // якщо переданий символ літера вертає true інакше false
    return is_upper_leter(c) || is_lower_leter(c);
}

bool is_upper_leter(const char c) {
    // Якщо передано ВЕЛИКУ літеру вертає true інакше false
    return c >= 'A' && c <= 'Z';
}

bool is_lower_leter(const char c) {
    // Якщо передано МАЛУ літеру вертає true інакше false
    return c >= 'a' && c <= 'z';
}

unsigned int str_len(const string str) {
    // Повертає довжину рядка (string aka char*)
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}
