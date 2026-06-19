#include<bits/stdc++.h>
using namespace std;
#define int long long
string t1,t2,s1[200020],s2[200020];
vector<int> t[27];
int n,q;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>q;string ss1,ss2;
    for(int i=1;i<=n;i++){
        cin>>ss1>>ss2;
        int difs,dife;
        for(int j=0;j<ss1.length();j++){
            if(ss1[j]!=ss2[j]){difs=j;break;}
        }
        for(int j=ss1.length()-1;j>=0;j--){
            if(ss1[j]!=ss2[j]){dife=j;break;}
        }
        for(int j=difs;j<=dife;j++){
            s1[i]+=ss1[j];
            s2[i]+=ss2[j];
        }
    }
    sort(s1+1,s1+n+1);
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){cout<<0;continue;}
        //if(t1==upper_bound(s1+1,s1+n+1,t1))
    }
}
