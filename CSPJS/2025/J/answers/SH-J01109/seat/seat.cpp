#include<bits/stdc++.h>
using namespace std;

int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int st=a[1],po;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==st){
            po=i;
            break;
        }
    }
    int y=(po-1)/n+1,x;
    if(y%2==1){
        x=(po-1)%n+1;
    }
    else x=n-(po-1)%n;
    cout<<y<<" "<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
