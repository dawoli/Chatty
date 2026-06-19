#include<bits/stdc++.h>
using namespace std;
string s;
int T,n,m,x,y;
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>x>>y;
        n=m=0;
        cin>>s;
        for(int i=0;i<y;i++){
            if(s[i]=='$')n++;
        }
        cout<<n<<" "<<y-1<<"\n";
    }
    return 0;
}
