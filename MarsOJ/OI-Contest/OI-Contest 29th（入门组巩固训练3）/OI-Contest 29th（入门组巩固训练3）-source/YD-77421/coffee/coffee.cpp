#include<bits/stdc++.h>
using namespace std;

int a[10];
void work() {
    int s=0;
    memset(a,0,sizeof(a));
    string st; 
    for(int i=1;i<=5;i++) {
        for(int j=1;j<=8;j++) {
            cin>>st;
            if(st=="math") {
                a[i]++;
                s++;
            }
        }
    }
    int n,m;
    cin>>n>>m;
    long long ans=n/7*s;
    n%=7;
    while(n--) {
        ans+=a[m];
        m=m%7+1;
    }
    cout<<ans<<"\n";
}
int main() {
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    int t;
    cin>>t;
    while(t--) work();
    return 0;
}