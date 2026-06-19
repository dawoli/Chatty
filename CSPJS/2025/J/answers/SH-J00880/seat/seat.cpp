#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        int t;
        cin>>t;
        v.push_back(t);
    }
    int t=v[0],f=0,a,b;
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]==t){
            f=v.size()-i;
            break;
        }
    }
    a=f/n+1;
    b=f%n;
    if(f%n==0){
        a--;
    }
    if(f%n==0){
        b=n;
    }
    if(a%2==0){
        b=n-b+1;
    }
    cout<<a<<" "<<b;
    return 0;
}
