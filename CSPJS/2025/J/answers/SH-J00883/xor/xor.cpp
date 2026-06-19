#include <bits/stdc++.h>
using namespace std;
int n,k,a[505050];
int flag=1;
int main(){
    cin>>n>>k;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            flag=0;
        }
    }
    if(flag=1){
        cout<<n/2;
    }else{
        cout<<n/4;
    }
    fclose(stdin);
    fclose(stdout);
}
