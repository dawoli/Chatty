#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[109];
int x,ind;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[(i-1)*m+j];
            if(i+j==2)x=a[(i-1)*m+j];
        }
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            ind=n*m-i+1;
            break;
        }
    }
    int s=ind%(2*n);
    cout<<(ind+n-1)/n<<" ";
    if(s==0){
        cout<<1;
        return 0;
    }
    if(s<=n){
        cout<<s;
        return 0;
    }
    cout<<2*n-s+1;
    return 0;
}