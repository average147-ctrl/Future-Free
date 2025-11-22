#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string Path = "C:\\tmp\\books.txt";
string title, author, year;
ofstream outFile;
ifstream inFile;
void Find(){
    inFile.open(Path);
        if (!inFile.is_open()){
            cout << "Ошибка при отрытии файла!" << endl;
        } else {
            string search;
            cout << "Введите слово для поиска: " << endl;
            cin.ignore();
            getline(cin, search);
            string line;
            bool found = false;
            while (getline(inFile, line)) {
                if (line.find(search) != string::npos) { 
                    cout << "Найдено: " << line << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
        cout << "Совпадений не найдено." << endl;
}inFile.close();
}
void Create() {
    ofstream outFile(Path); 
    
    if (!outFile.is_open()) { 
        cout << "Ошибка открытия файла\n" << endl;
    } else {

        while (true) {

            cout << "Введите название книги: \n";
            cin.ignore();
            getline(cin, title);

            if (title.empty()) {
                 break;
            }
            cout << "Введите автора книги: \n";
            cin.ignore();
            getline(cin, author);

            cout << "Введите год выпуска: \n";
            cin.ignore();
            getline(cin, year);

            outFile << title << endl;
            outFile << author << endl;
            outFile << year << endl;
            outFile << endl;
        } outFile.close();
    }
}
void Sort(){
    inFile.open(Path);
        if (!inFile.is_open()){
            cout << "Ошибка при отрытии файла!" << endl;
        } else {
            string line;
            while(getline(inFile, line)){
            string search;
            cout << "Введите слово для поиска: " << endl;
            cin.ignore();
            getline(cin, search);
            bool found = false;
            while (getline(inFile, line)) {
                if (line.find(search) != string::npos) { 
                    cout << "Найдено: " << line << endl;
                    found = true;
                }
            }
            
            if (!found)
        cout << "Совпадений не найдено." << endl;
}}inFile.close();
}
int main() { 
    int vibor; 
    do { 
        cout << "1. Добавить\n"; 
        cout << "2. Поиск\n"; 
        cout << "3. Сортировка\n"; 
        cout << "4. Вывод\n"; 
        cout << "0. Завершить программу\n"; 
        cout << "Введите ваш выбор: "; 
        cin >> vibor; 
        switch (vibor) { 
            case 1: 
                Create();
                break; 
            case 2: 
                Find();
                break; 
            case 3: 
                Sort();
                break; 
            case 4: 
            
                break; 
            case 0: 
                cout << "Программа завершена.\n"; 
                break; 
            default: 
                cout << "Неверный выбор. Попробуйте снова.\n"; 
            } 
        } while (vibor != 0); 

    return 0;
}