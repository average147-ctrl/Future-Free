#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 0;
    cin >> a;  
    if(a > 0){ 
        cout << "Число положительное"<< endl; 
    } else if (a < 0){    
        cout << "Число отрицательное"<< endl;
    }else{
        cout << "Равно нулю";
    }
    return 0;
}
