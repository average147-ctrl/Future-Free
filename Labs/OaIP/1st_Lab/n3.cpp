#include <iostream>
using namespace std;
int main()
{
    const int size = 15;
    double arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 200 + 1;
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
    double temp = arr[0];
    arr[0] = arr[minind];
    arr[minind] = temp;
    temp = arr[size-1];
    arr[size-1] = arr[maxind];
    arr[maxind] = temp;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}