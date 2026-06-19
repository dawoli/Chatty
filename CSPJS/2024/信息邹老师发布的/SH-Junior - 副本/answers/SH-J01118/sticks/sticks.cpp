#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        if(n%7==0){
            while(n!=0){
                n-=7;
                cout<<8;
            }
        }
        cout<<endl;
    }
    return 0;
}
