#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    if(a < 1) {
        cout << "Calm";
    } else if (a < 4) {
        cout << "Light air";
    } else if (a < 28) {
        cout << "Breeze";
    } else if (a < 48) {
        cout << "Gale";
    } else if (a < 64) {
        cout << "Storm";
    } else {
        cout << "Hurricane";
    }
}