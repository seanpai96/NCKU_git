#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> v;
    int a[100001], n, mx = -1, tmp;
    memset(a, 0, sizeof(a));
    cin >> n;
    while(n--){
        cin >> tmp;
        a[tmp]++;
        if (a[tmp] > mx){
            v.clear();
            v.push_back(tmp);
            mx = a[tmp];
        }else if (a[tmp] == mx){
            v.push_back(tmp);
        }
    }
    for (int i = 0; i < v.size();i++){
        cout << v[i] << ' ';
    }
    cout << endl << mx;
}