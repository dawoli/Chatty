#include<bits/stdc++.h>
using namespace std;
const int b[10]={6,2,5,5,4,5,6,3,7,6};
int r[100],bb=0,l=100000000;
long long minn,rn[51];
int check(int t){
    int i;
    long long s=0;
    if(r[1]==0){
        return 0;
    }
    for(i=1;i<=t;i++){
        s+=pow(10,t-i)*r[i];
    }
    if(bb==0||s<minn){
        l=t;
        minn=s;
        bb=1;
    }
    return 1;
}
void dfs(int i,int n){
    int j=0;
    if(i==1) j++;
    for(;j<=9;j++){
        if(b[j]<=n){
            r[i]=j;
            n-=b[j];
            if(n==0){
                if(check(i)==1)
                    break;
            }
            else if(n>0&&i<l) dfs(i+1,n);
            n+=b[j];
        }
    }
}
int main(){
    int n,tn,i,j,x,u;
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>tn;
    for(i=1;i<=tn;i++){
        cin>>n;
        bb=0;
        l=10000000;
        if(n<=40){
            dfs(1,n);
            if(bb) rn[i]=minn;
            else rn[i]=-1;
        }
        else{
            x=n/7-1;
            u=n-7*x;
            dfs(1,u);
            rn[i]=pow(10,x)*minn;
            for(j=0;j<x;j++)
                rn[i]+=pow(10,j)*8;
        }
    }
    for(i=1;i<=tn;i++)
        cout<<rn[i]<<endl;
    return 0;
}
