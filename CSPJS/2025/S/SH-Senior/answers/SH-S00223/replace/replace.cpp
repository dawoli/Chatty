#include<bits/stdc++.h>
using namespace std;
const int MAXN=500006;
string l1[MAXN],l2[MAXN];
int l[MAXN],r[MAXN];
int n,q,dj;
bool compare(string x,string y,int q1,int q2,int w1,int w2){
    if((q2-q1)!=(w2-w1))return false;
    for(int i=0;i<=q2-q1;i++)
        if(x[q1+i]!=y[w1+i])return false;
    return true;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    dj=0;
    for(int i=1;i<=n;i++){
        cin>>l1[i]>>l2[i];
        int d=MAXN,e=0;
        for(int j=0;j<l1[i].size();j++){
            if(l1[i][j]!=l2[i][j]){
                d=j;
                break;
            }
        }
        for(int j=l1[i].size()-1;j>=0;j--){
            if(l1[i][j]!=l2[i][j]){
                e=j;
                break;
            }
        }
        if(d>e) continue;
        dj++;
        l[dj]=d,r[dj]=e;
    }
    while(q--){
        int ans=0;
        string o1,o2;
        cin>>o1>>o2;
        int d=MAXN,e=0;
        for(int j=0;j<o1.size();j++){
            if(o1[j]!=o2[j]){
                d=j;
                break;
            }
        }
        for(int j=o1.size()-1;j>=0;j--){
            if(o1[j]!=o2[j]){
                e=j;
                break;
            }
        }
        if(d>e) continue;
        dj++;
        for(int j=1;j<=dj;j++){
            if(compare(o1,l1[j],d,e,l[j],r[j])&&compare(o2,l2[j],d,e,l[j],r[j])){
                 ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
