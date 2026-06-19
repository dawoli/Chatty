#include<bits/stdc++.h>
using namespace std;
int n,q;const int maxn=200005;
string s[maxn][3];
string t[maxn][3];
int ans[maxn];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
    for(int i=1;i<=q;i++)cin>>t[i][1]>>t[i][2];
    for(int i=1;i<=q;i++){
        // int len=strlen(t[i][1]);
        int len=t[i][1].size();
        // int len2=strlen(t[i][2]);
        int len2=t[i][2].size();
        if(len!=len2)continue;
        for(int j=1;j<=n;j++){
            // int sublen=strlen(s[j][1]);
            int sublen=s[j][1].size();
            for(int k=0;k+sublen-1<=len;k++){
                // cout<<"t[i][1].substr(k,sublen)="<<t[i][1].substr(k,sublen)<<endl;
                // cout<<"s[j][1]="<<s[j][1]<<endl;
                if(t[i][1].substr(k,sublen)==s[j][1]){
                    // cout<<"t[i][1].substr(0,k)="<<t[i][1].substr(0,k)<<endl;
                    // cout<<"s[j][2]="<<s[j][2]<<endl;
                    // cout<<"t[i][1].substr(k+sublen,sublen)="<<t[i][1].substr(k+sublen,sublen)<<endl;
                    // cout<<"concat is "<<t[i][1].substr(0,k)+s[j][2]+t[i][1].substr(k+sublen,sublen)<<endl;
                    // cout<<"t[i][2]="<<t[i][2]<<endl;
                    if(t[i][1].substr(0,k)+s[j][2]+t[i][1].substr(k+sublen,sublen)==t[i][2])
                        ans[i]++;
                }
            }
        }
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
    return 0;
}