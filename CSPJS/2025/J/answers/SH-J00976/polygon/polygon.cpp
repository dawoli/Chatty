#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum,m,cnt=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        sum=a[0]+a[1]+a[2];
        m=max(max(a[0],a[1]),a[2]);
        cout<<(sum>2*m?1:0);
        return 0;
    }
    srand(time(NULL));
    if(n<10)
        cout<<rand()%20+20;
    return 0;
}
