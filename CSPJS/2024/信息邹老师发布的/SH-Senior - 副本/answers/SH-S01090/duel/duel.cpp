#include<iostream>
#include<cstdio>
using namespace std;
int n, a, numCount[100005], ans;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a; numCount[a]++;
    }
    for(int i = 1; i <= 100000; i++)    ans = max(ans, numCount[i]);
    cout<<ans;
}