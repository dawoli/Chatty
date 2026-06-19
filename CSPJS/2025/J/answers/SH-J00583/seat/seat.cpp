#include<bits/stdc++.h>
using namespace std;
struct id12{
    int id,gra;
};
int cmp(id12 x,id12 y){
    return x.gra>y.gra;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    id12 a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].gra;
        a[i].id=i;
    }
    int sum=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].id!=1){
            sum++;
        }else break;
    }
    int ansx=sum/n+1,ansy=sum%n;
    cout<<ansx<<" ";
    if(ansx%2==1)cout<<ansy+1;
    else cout<<n-ansy;
    return 0;
}
