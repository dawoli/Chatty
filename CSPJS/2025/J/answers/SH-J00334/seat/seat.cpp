#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,stud[101];
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=t;i++){
        cin>>stud[i];
    }
    int q=stud[1],w=1;
    for(int i=1;i<=t;i++){
        if(stud[i]>q)
            w++;
    }
    cout<<(w-1)/n+1<<" ";
    if(w%(2*n)<=n){
        cout<<w%(2*n);
    }
    else{
        cout<<n-w%n+1;
    }
    return 0;
}
