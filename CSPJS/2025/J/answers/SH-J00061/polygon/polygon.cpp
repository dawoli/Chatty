#include<bits/stdc++.h>
using namespace std;
int jc(int n){
    if(n==1)    return 1;
    return n*jc(n);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long sum=0;
    bool flag=true;
    int n,maxnum=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=false;
        maxnum=max(a[i],maxnum);
    }
    maxnum*=2;
    if(n==3){
        if(a[0]+a[1]+a[2]>=maxnum)  cout<<1;
        else    cout<<0;
        return 0;
    }else if(flag){
        for(int i=3;i<n;i++){
            sum+=jc(n)/(jc(i)*jc(n-i));
            sum%=998244353;
        }
        sum++;
        sum%=998244353;
        cout<<sum;
        return 0;
    }
    return 0;
}
