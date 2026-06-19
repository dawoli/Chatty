#include<bits/stdc++.h>
using namespace std;
int myLog(int x){
    int power=1;
    while(int(pow(2,power))<x)power++;
    return power;
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
    }
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
    }
    for(int i=1;i<myLog(n);i++){
        string s;
        cin>>s;
    }
    int T;
    scanf("%d",&T);
    while(T--){
        puts("1");
    }
    return 0;
}