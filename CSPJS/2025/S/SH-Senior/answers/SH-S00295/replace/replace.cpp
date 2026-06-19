#include<bits/stdc++.h>
using namespace std;
string s[200005][2];
int l[200005];
vector<int>nxt[200005];
int main(){
    //freopen("replace.in","r",stdin);
    //freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        l[i]=s[i][0].length();
        int ind=2,cn=0;
        nxt[i].resize(l[i]+1);
        while(ind<=l[i]){
            if(s[i][0][ind-1]==s[i][0][cn])nxt[i][ind++]=++cn;
            else if(cn>0)cn=nxt[i][cn];
            else nxt[i][ind++]=0;
        }
    }
    /*for(int i=1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        int len=t1.length();
        if(len!=t2.length()){
            cout<<0<<"\n";
            continue;
        }
        int start,end;
        for(int j=1;j<=len;j++){
            if(t1[j]==t2[j]){
                start=j;
                break;
            }
        }
        for(int j=len;j>=1;j--){
            if(t1[j]==t2[j]){
                end=j;
                break;
            }
        }
        int lenmode=end-start+1;
        string mode1=t1.substr(start,lenmode);
        string mode2=t2.substr(start,lenmode);
        vector<int>nxt(lenmode+1);
        int ind=2,cn=0;
        while(ind<=lenmode){
            if(mode1[ind-1]==mode1[cn])nxt[ind++]=++cn;
            else if(cn>0)cn=nxt[cn];
            else nxt[ind++]=0;
        }
        for(int j=1;j<=n;j++){
            if(l[j]<lenmode)continue;
            int x=0,y=0;
            while(x<=n){
                if(s1[x]==s2[y]){
                    x++,y++;
                    if(y==m){
                        cout<<x-y+1<<endl;
                        y=nxt[y];
                    }
                }
                else if(y>0)y=nxt[y];
                else x++;
            }
        }
    }*/
    for(int i=1;i<=q;i++){
        int ans=0;
        string t1,t2;
        cin>>t1>>t2;
        int len=t1.length();
        if(len!=t2.length()){
            cout<<0<<"\n";
            continue;
        }
        for(int j=1;j<=n;j++){
            if(l[j]>len)continue;
            int x=0,y=0;
            vector<int>pt;
            while(x<=n){
                if(s[j][0][x]==t1[y]){
                    x++,y++;
                    if(y==l[j]){
                        pt.push_back(x-y+1);
                        y=nxt[j][y];
                    }
                }
                else if(y>0)y=nxt[j][y];
                else x++;
            }
            for(auto k:pt){
                int flag=1;
                for(int w=k;w<=k+l[j]-1;w++){
                    if(t2[w]!=s[j][1][w]){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
//g++ -O2 -std=c++14 -static replace.cpp -Wall -o replace