#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
using ll =long long;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<string> s1(n+1),s2(n+1),p1(n+1),p2(n+1);
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    vector<int> sl(n+1),sr(n+1);
    for(int j=1;j<=n;j++){
        int l=0,r=0,sig=1;
        ll ans=0;
        for(int i=0;i<s1[j].length();i++){
            if(s1[j][i]!=s2[j][i]){
                if(sig==1){
                    l=i;sig=0;
                }
                r=i;
            }
        }
        for(int i=l;i<=r;i++){
            p1[j].push_back(s1[j][i]);
            p2[j].push_back(s2[j][i]);
        }
        sl[j]=l;sr[j]=r;
    }

    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){
            cout<<0<<endl;continue;
        }
        else{
            int l=0,r=0,sig=1;
            ll ans=0;
            for(int i=0;i<t1.length();i++){
                if(t1[i]!=t2[i]){
                    if(sig==1){
                        l=i;sig=0;
                    }
                    r=i;
                }
            }
            string c1,c2;
            for(int i=l;i<=r;i++){
                c1.push_back(t1[i]);
                c2.push_back(t2[i]);
            }
            for(int i=1;i<=n;i++){
                if(c1==p1[i] && c2==p2[i]){
                    int sign=1;
                    if(l-sl[i]<0 || r+s1[i].length()-sr[i]-1 >=t1.length()) sign=0;
                    else{
                        for(int j=1;j<=sl[i];j++){
                            if(s1[i][sl[i]-j]!=t1[l-j]) sign=0;
                        }
                        for(int j=1;j<=s1[i].length()-sr[i]-1;j++){
                            if(s1[i][sr[i]+j]!=t1[r+j]) sign=0;
                        }
                    }
                    ans+=sign;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
