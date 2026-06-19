#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,le;
    cin>>n>>m;
    vector<int> so(n*m);
    for(int i=0;i<n*m;i++)  cin>>so[i];
    le=so[0];
    sort(so.begin(),so.end(),cmp);
    vector<vector<int>> a(n,vector<int>(m,0));
    int i=1,j=1,d=1,k=0;
    while(so[k]!=le){
        if(i+d>n){
            j++;
            d=-1;
        }else if(i+d<=0){
            j++;
            d=1;
        }else{
            i+=d;
        }
        k++;
    }
    cout<<j<<" "<<i;
    return 0;
}
