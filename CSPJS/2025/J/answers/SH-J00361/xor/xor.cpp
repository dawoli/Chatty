#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500009];
int x[29],y[29];
int sum[500009][29],f[500009];
int M[3000000];
int cur[500009];
void cal(int s[],int ss){
    int i=0;
    while(ss>0){
        s[i]=ss%2;
        ss/=2;
        i++;
    }
    return ;
}
int cal2(int a,int b){
    int ans=0,i=1;
    while(a>0&&b>0){
        ans+=i*((a%2+b%2)%2);
        a/=2;
        b/=2;
        i*=2;
    }
    while(a>0){
        ans+=i*(a%2);
        i*=2;
        a/=2;
    }
    while(b>0){
        ans+=i*(b%2);
        i*=2;
        b/=2;
    }
    return ans;
}
int cal3(int a[]){
    int ans=0;
    for(int i=21;i>=0;i--)ans=ans*2+a[i];
    return ans;
}
int s[29];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    cal(x,k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cal(sum[i],a[i]);
        for(int j=0;j<=20;j++)sum[i][j]=(sum[i-1][j]+sum[i][j])%2;
    }
    M[0]=0;
    for(int i=1;i<=n;i++){
        int mmm=cal3(sum[i]);
        if(a[i]==k){
            f[i]=f[i-1]+1;
            M[mmm]=i;
            continue;
        }
        int xx=cal2(k,mmm);
        f[i]=f[i-1];
        int mm=M[xx];
        if(mm){
            f[i]=max(f[i-1],f[mm]+1);
        }
        else if(xx==0){
            f[i]=1;
        }
        M[mmm]=i;
    }
    cout<<f[n];
    return 0;
}