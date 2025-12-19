#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string Path = "C:\\tmp\\books.txt";
string outputPath = "C:\\tmp\\output.txt";
string title, author, year;
ofstream outFile;
ifstream inFile;

void saveResult(const string& operation, const string& result) {
    ofstream outputFile(outputPath, ios::app);
    
    if (!outputFile.is_open()) {
        cout << "Ошибка при открытии файла результатов!" << endl;
        return;
    }
    
    outputFile << "=== " << operation << " ===" << endl;
    outputFile << result << endl;
    outputFile << "==========================" << endl << endl;
    
    outputFile.close();
}

void Find() {
    inFile.open(Path);
    string resultText = "";
    
    if (!inFile.is_open()) {
        cout << "Ошибка при открытии файла!" << endl;
        resultText = "Ошибка при открытии файла books.txt";
    } else {
        string search;
        cout << "Введите слово для поиска: " << endl;
        cin.ignore();
        getline(cin, search);
        string line;
        bool found = false;
        
        resultText = "Поиск: " + search + "\n";
        
        while (getline(inFile, line)) {
            if (line.find(search) != string::npos) {
                string foundResult = "Найдено: " + line;
                cout << foundResult << endl;
                resultText += foundResult + "\n";
                found = true;
            }
        }
        
        if (!found) {
            string notFoundMsg = "Совпадений не найдено.";
            cout << notFoundMsg << endl;
            resultText += notFoundMsg;
        }
    }
    
    inFile.close();
    saveResult("ПОИСК", resultText);
}

void Create() {
    ofstream outFile(Path);
    string resultText = "Добавленные книги:\n";
    
    if (!outFile.is_open()) {
        cout << "Ошибка открытия файла\n" << endl;
        resultText = "Ошибка открытия файла books.txt";
    } else {
        while (true) {
            cout << "Введите название книги: \n";
            getline(cin, title);

            if (title.empty()) {
                break;
            }
            
            cout << "Введите автора книги: \n";
            getline(cin, author);

            cout << "Введите год выпуска: \n";
            getline(cin, year);

            outFile << title << endl;
            outFile << author << endl;
            outFile << year << endl;
            outFile << endl;
            
            resultText += "Название: " + title + ", Автор: " + author + ", Год: " + year + "\n";
        }
        outFile.close();
    }
    
    saveResult("ДОБАВЛЕНИЕ", resultText);
}

void Sort() {
    inFile.open(Path);
    string resultText = "Результаты сортировки:\n";
    
    if (!inFile.is_open()) {
        cout << "Ошибка при открытии файла!" << endl;
        resultText = "Ошибка при открытии файла books.txt";
    } else {
        string search;
        cout << "Введите слово для поиска (в текущей реализации): " << endl;
        cin.ignore();
        getline(cin, search);
        
        string line;
        bool found = false;
        resultText = "Поиск для сортировки: " + search + "\n";
        
        while (getline(inFile, line)) {
            if (line.find(search) != string::npos) {
                string foundResult = "Найдено: " + line;
                cout << foundResult << endl;
                resultText += foundResult + "\n";
                found = true;
            }
        }
        
        if (!found) {
            string notFoundMsg = "Совпадений не найдено.";
            cout << notFoundMsg << endl;
            resultText += notFoundMsg;
        }
    }
    
    inFile.close();
    saveResult("СОРТИРОВКА/ПОИСК", resultText);
}

int main() {
    ofstream clearFile(outputPath);
    clearFile.close();
    
    int vibor;
    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Добавить книги\n";
        cout << "2. Поиск книги\n";
        cout << "3. Сортировка книг\n";
        cout << "4. Вывод книг по году\n";
        cout << "0. Завершить программу\n";
        cout << "Введите ваш выбор: ";
        cin >> vibor;
        cin.ignore();
        
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
                cout << "Функция вывода по году не реализована" << endl;
                saveResult("ВЫВОД ПО ГОДУ", "Функция не реализована");
                break;
            case 0:
                cout << "Программа завершена. Результаты сохранены в output.txt\n";
                saveResult("ЗАВЕРШЕНИЕ", "Программа завершена пользователем");
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (vibor != 0);

    return 0;
}