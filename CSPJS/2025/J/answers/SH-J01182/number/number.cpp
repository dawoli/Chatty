#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > numbers;
char inp;
string whole_inp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> whole_inp;

    int code;
    for (int i=0; i < whole_inp.size(); i++){
        inp = whole_inp[i];
        if (inp >= '0' && inp <= '9'){
            code = inp;
            numbers.push(code);
        }
    }
    while (!numbers.empty()){
        cout << numbers.top();
        numbers.pop();
    }
    cout  << endl;
    return 0;
}
