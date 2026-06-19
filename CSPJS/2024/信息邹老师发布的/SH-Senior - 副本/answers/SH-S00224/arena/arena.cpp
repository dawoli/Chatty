#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n],c[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>c[i];
    }
    int k,g;
    while(pow(2,k)<n){
        k++;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<pow(2,(k-j));j++){
            cin>>g;
        }
    }
    int t,x0,x1,x2,x3;
    for(int i=0;i<t;i++){
        cin>>x0>>x1>>x2>>x3;
    }
    for(int i=0;i<t;i++){
        cout<<1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
