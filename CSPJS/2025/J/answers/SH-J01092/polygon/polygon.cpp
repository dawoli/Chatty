#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i = 1; i <= n-2; i++){
        sum += i;
    }
    cout << sum;
    return 0;
}
