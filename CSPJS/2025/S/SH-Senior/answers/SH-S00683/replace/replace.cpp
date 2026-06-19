#include<iostream>
#include<fstream>
using namespace std;
const int N=2e5+5;
pair<string,string>mp[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>mp[i].first>>mp[i].second;
    while(q--){
        string t1,t2,tmp;
        cin>>t1>>t2;
        int ans=0;
        for(int i=0;i<t1.size();i++){
            for(int j=1;j<=n;j++){
                tmp=t1;
                tmp.replace(i,mp[j].first.size(),mp[j].second);
                if(tmp==t2)
                    ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}