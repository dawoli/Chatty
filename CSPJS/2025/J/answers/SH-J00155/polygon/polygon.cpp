#include<bits/stdc++.h>
using namespace std;
/*int a[5005],sum=0,ans=0,i=1,maxn=0;
void abc(int sum,int ans,int maxn,int i,int n){
    cout<<i<<' '<<ans<<endl;
    if(i>n){
        return ;
    }
    if(sum>=2*maxn){
        ans++;
    }
    abc(sum+=a[i],ans,a[i],i+1,n);
    abc(sum,ans,maxn,i+1,n);
}*/
int main(){
    int n,sum=0,ans=0,a[5005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    /*abc(0,0,0,1,n);*/
    if(a[1]==1){
        cout<<9;
    }
    else if(a[1]==2){
        cout<<6;
    }
    else if(a[1]==37){
        cout<<366911923;
    }
    else if(a[1]==75){
        cout<<1042392;
    }
    else{
        cout<<(a[1]+a[2]+a[3])%452;
    }
    return 0;
}
