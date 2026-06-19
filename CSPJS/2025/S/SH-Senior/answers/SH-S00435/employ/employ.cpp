#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const int maxn=509;
const int mod=998244353;
int n,m;
bool diff[maxn];
inline ll qpow(int a,int k,int mod){
    ll res=1;
    while(k){
        if(k&1) res=res*a%mod;
        k>>=1;
        a=a*a%mod;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool A=true;
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        if(ch!='1') A=false;
        diff[i]=(ch-'0')^1;
    }
    vector<int> c(n),p(n);
    int nonzero=0;
    for(int i=0;i<n;i++){
        cin>>c[i];
        if(c[i]!=0) nonzero++;
        p[i]=i;
    }
    ll ans=0;
    do{
        // for(auto x:p){
        //     cout<<x+1<<" ";
        // }
        // cout<<endl;
        int cnt=0,pass=0;
        for(int i=0;i<n;i++){
            if(cnt>=c[p[i]]||diff[i]){
                cnt++;
                // printf("Paole! %d \n",p[i]+1);
            }
            else{
                pass++;
                // printf("Employ success! %d \n",p[i]+1);
            }
            if(pass>=m){
                ans++;
                break;
            }
        }
        // cout<<endl;
    }while(next_permutation(p.begin(),p.end()));
    cout<<ans<<endl;
    return 0;
}