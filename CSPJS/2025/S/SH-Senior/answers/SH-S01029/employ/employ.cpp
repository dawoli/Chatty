#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1105;
int n,m;
string s;
int c[MAXN];
long long ans=0;
int p[MAXN];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        p[i]=i;
    }
    do{
        int g=0;
        for(int i=1;i<=n;i++){
            if(g>=c[p[i]]){
                g++;
                continue;
            }
            if(s[i]=='0'){
                g++;
            }
        }
        if(n-g>=m){
            ans++;
        }
    }while(next_permutation(p+1,p+1+n));
    printf("%lld",ans);
    return 0;
}
