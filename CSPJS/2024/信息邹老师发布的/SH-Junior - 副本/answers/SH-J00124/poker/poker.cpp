#include<bits/stdc++.h>
using namespace std;
int n,sum=52;
char x,y;
map<char,bool>a[504];
signed main(){
   freopen("poker.in","r",stdin);
   freopen("poker.out","w",stdout);
   cin>>n;
   for(register int i=1;i<=n;i++){
    cin>>x>>y;
    if(!a[x][y]){
        sum--;
        a[x][y]=1;
    }
   }
   cout<<sum;
   return 0;
}
