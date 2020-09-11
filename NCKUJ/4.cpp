#include <iostream>
#include <string>
using namespace std;

int main() {
    int a = 0, b = 0;
    long long input;
    cin >> input;
    for (int i = 0; i < 12; i++) {
        int tmp = input % 10;
        input /= 10;
        if (i % 2) {  //odd
            b += tmp;
        } else {
            a += tmp;
        }
    }
    b += a * 3;
    b -= 1;
    b %= 10;
    cout << 9 - b;
}