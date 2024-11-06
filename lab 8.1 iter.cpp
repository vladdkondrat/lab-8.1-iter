#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Функція для підрахунку груп з трьох знаків оклику "!!!"
bool ContainsTripleExclamationIter(char* str) {
    if (strlen(str) < 3)
        return false;
    for (int i = 0; i < strlen(str) - 2; ++i) {
        if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!') {
            return true;
        }
    }
    return false;
}

// Функція для заміни трійок знаків оклику "!!!" на "**"
char* ReplaceTripleExclamationIter(char* str) {
    size_t len = strlen(str);
    if (len < 3)
        return str;

    char* tmp = new char[len * 2 + 1]; // Забезпечуємо достатньо місця для замін
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;
    while (i < len && str[i + 2] != 0) {
        if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!') {
            strcat(t, "**");
            t += 2;
            i += 3;
        }
        else {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    while (i < len) {
        *t++ = str[i++];
    }
    *t = '\0';

    strcpy(str, tmp);
    return tmp;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Перевірка, чи містить рядок групу з трьох знаків оклику "!!!"
    bool containsTripleExclamation = ContainsTripleExclamationIter(str);
    cout << "Contains triple exclamation: " << (containsTripleExclamation ? "Yes" : "No") << endl;

    // Заміна трійок знаків оклику "!!!" на "**"
    char* dest = new char[151];
    dest = ReplaceTripleExclamationIter(str);
    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}
