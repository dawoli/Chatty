#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n,m,x,ansx,ansy;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            if(i%n==0){
                ansx=i/n;
            }
            else{
                ansx=i/n+1;
            }
            if(ansx%2==0){
                ansy=ansx*n-i+1;
            }
            else{
                ansy=i-(ansx-1)*n;
            }
        }
    }
    cout<<ansx<<' '<<ansy;
    return 0;
}
