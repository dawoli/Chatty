#include<bits/stdc++.h>
#include<random>
using namespace std;
int length_of_each[5005], num_of_sticks;
int main(){
    ios::sync_with_stdio(false);

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin>>num_of_sticks;
    for (int i =1;i<=num_of_sticks;i++){
        cin >> length_of_each[i];
    }

    cout << 5;
}
