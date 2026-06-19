#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
using ll =long long;
deque<int> pl;
vector<int> ex;
int n,m;
vector<int> c;
string s;
ll ans;
bool check(){
    int ly=0,qy=0;
    for(int i=0;i<n;i++){
        int x=pl[i];
        if(qy>=c[x] || s[i]=='0'){
            qy++;
        }
        else{
            ly++;
        }
    }
    if(ly>=m) return true;
    else return false;
}
int dfs(){
    if(pl.size()==n){
        if(check()) ans=(ans+1ll)%p;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(ex[i]==0){
            ex[i]=1;
            pl.push_back(i);
            dfs();
            pl.pop_back();
            ex[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ans=0;
    cin>>n>>m;
    cin>>s;
    c.resize(n);
    ex.resize(n);
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++) ex[i]=0;
    dfs();
    cout<<ans<<endl;
    return 0;
}
