#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m,T,K;
int x[4];
long long a[100003],ablity[100003],c[100003];
bool home[100003],out[100003];

void solve(int round){

}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    K=int(log2(n))+1;
    for(int i=1;i<=n-1;i++)cin>>home[i];
    cin>>T;
    for(int o=0;o<T;o++){
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=0;i<n;i++){
            ablity[i]=a[i]^x[i%4];
        }
        for(int i=0;i<n;i++) out[i]=0;

        for(int i=n+1;i<2^K;i++)
        solve(1);
//        if(log2(k-r))
    }
    return 0;
}
