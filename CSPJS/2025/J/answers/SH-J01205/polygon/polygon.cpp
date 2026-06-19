#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n;
    cin>>n;
    if(n<=2){
        cout<<"0";
        return 0;
    }
   int a;
    int cnt=0;
    int maxx=0;
    for(int i=0;i<n;i++){
        cin>>a;
        cnt+=a;
        maxx=max(maxx,a);
    }
    if(maxx*2<cnt) cout<<"1";
    else cout<<"0";
    return 0;
}
