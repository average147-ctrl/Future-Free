#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cstring>
int main() {
    char str[100];
   cin.getline(str, 100);
   int count = 0;
   vector<string> Ve; 
   int countmin = 0;
   int countrav = 0;
   int min = 10000;  
   const char det[] = " ";
   char* token = strtok(str, det);
   while(token != nullptr){
       Ve.push_back(token);
    
       if(token[0] == 'a' || token[0] == 'A'){ // Подсчет количества слов на букву "a"
           count++;
       }
       int length = sizeof(str) / sizeof(str[0]) - 1;
       char kon = str[length - 1]; //Переменная количства элементов слова
       for(int i = 0; i < kon; i++){  //Подсчет количствва букв в слове
          countmin++;
          token[i] = tolower(token[0]); // Возведение элемента в нижний регистр
       }
       if(countmin <= min){     // Нахождение минималльного по длине слова
           min = countmin;
           countmin = 0;
       }
       if(token[0] == kon){ // Проверка на равенство первого и пососледнего
           countrav++;
       }
       token = strtok(nullptr, det);
   }
   cout << endl;
   for(auto el : Ve){
       cout << el << " ";
   }

cout << endl << "Минимальное количество букв в слове: " << min << endl << " Количество слов на букву а: " << count << endl << " Количесвто слов с совпадающими последними и первымим буквами: " << countrav;
return 0; 
}
