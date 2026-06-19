#include<bits/stdc++.h>
using namespace std;

struct member{
    int fir,sec,thi;
} a[100005];
int b[5];
bool cmp(member x,member y){
    int f1,f2;
    if(x.fir>=x.sec) f1=x.fir-x.sec;
    else f1=x.sec-x.fir;
    if(y.fir>=y.sec) f2=y.fir-y.sec;
    else f2=y.sec-y.fir;
    return f1>f2;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>a[i].fir>>a[i].sec>>a[i].thi;
        }
        sort(a+1,a+n+1,cmp);
        int lika=0,likb=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(a[i].fir>=a[i].sec && lika<n/2){
                lika++;
                sum+=a[i].fir;
                if(lika==n/2){
                    for(int j=i+1;j<=n;j++) sum+=a[j].sec;
                    cout<<sum<<endl;
                    break;
                }
            }
            else if(a[i].fir<a[i].sec && likb<n/2){
                likb++;
                sum+=a[i].sec;
                if(likb==n/2){
                    for(int j=i+1;j<=n;j++) sum+=a[j].fir;
                    cout<<sum<<endl;
                    break;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
