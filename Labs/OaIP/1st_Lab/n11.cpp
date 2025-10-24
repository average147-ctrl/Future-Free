
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    for(int i = 32; i < 127; i++){
        cout << "Символ: " << char(i) << " Код символа: " << i << endl;
    }
    return 0;
}