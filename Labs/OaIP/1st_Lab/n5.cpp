#include <iostream>
using namespace std;
int main()
{
    const int size = 10;
    int arr[size];
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
    if(maxind == 10 - 1  and  minind == 5 - 1){
        cout << (arr[minind] + arr[maxind]) / 2 << " ";
    } else { 
        cout << "Макс не на 10 месте или мин не на пятом месте ";
    }
    
}