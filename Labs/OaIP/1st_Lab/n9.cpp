#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 0;
    cin >> a;  
    int sum = 0;
    for(int i = 1; i <= a; i++){ 
        if(i % 5 == 0 || i % 2 == 0){
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
