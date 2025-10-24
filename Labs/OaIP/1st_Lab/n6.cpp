#include <iostream>
using namespace std;
int main()
{
    const int size = 10;
    double arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
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
    cout << maxind << " " << minind;
    cout << endl;
    if(maxind == 1 - 1  and  minind == 2 - 1){
        for(int i = 0; i < size; i++){
            arr[i] = arr[i] / 2;
            cout << arr[i] << " ";   
        }
    } else { 
        cout << "Макс не на 1 месте или мин не на 2 месте ";
    }
    
}