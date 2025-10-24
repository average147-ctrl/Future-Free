#include <iostream>
using namespace std;
int main()
{
    const int size = 15;
    double arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 99 + 1;
        cout << arr[i] << " ";
    }
    cout << endl;
    int minind = 0;
    int maxind = 0;
    for(int i = 0; i < size; i++){
        if (arr[i] < arr[minind]) {
            minind = i;
        }
    }
    for(int i = 0; i < size; i++){
        if (arr[i] > arr[maxind]) {
            maxind = i;
        }
    }
    cout << endl;
    if(maxind < minind){
        cout << arr[minind] * arr[maxind] << " ";
    } else { 
        cout << "Максимальный элемент идет позже минимального";
    }
    
}