// Задание 1 
// #include <iostream>
// using namespace std;
// int main() {
// setlocale(LC_ALL, "RU");

//     double fuel_volume = 0;
//     cin >> fuel_volume;
//     if (fuel_volume > 50) {
//         cout << "Топлива достаточно" << endl;
//     } else if (fuel_volume < 50 and fuel_volume > 20){
//         cout << "Рекомендуется заправка" << endl;
//     }else {
//         cout << "Топливо на исходе, срочно заправтесь!" << endl;
//     return 0;
//     }
// }




// Задание 2

#include <iostream>
using namespace std;
int main(){
    setlocale(LC_ALL, "RU");
    int a =0;
    cout << "Введите количество топлива:";
    while (a >= 0){
        cin >> a;
        if (a < 0) {
            cout << "Введено некорекное число";
            break;
        }
    }
    return 0;
}