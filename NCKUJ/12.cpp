#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a, n, d, k;
    cin >> a >> n >> d >> k;
    cout << a << ' ';
    for (int i = 1; i < n;i++){
        a += d;
        cout << a << ' ';
        d += k;
    }
}