#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=5e6+5;

int n,q;
int ans;
int t[MAXM][26],tot=0;
vector<int> cnt[MAXM];
map<string,pair<int,int> > mp;
pair<string,pair<string,string> > split(string s1,string s2){
    int l=-1,r=-1;
    int m=s1.length();
    for(int j=0;j<m;j++){
        if(s1[j]!=s2[j]){
            if(l==-1){
                l=j;
            }
            r=j;
        }
    }
    if(l==r&&r==-1){
        return {"",{"",""}};
    }
    string tmp1,tmp2,tmp3;
    tmp1=tmp2=tmp3="";
    for(int j=l-1;j>=0;j--){
        tmp2+=s1[j];
    }
    for(int j=r+1;j<m;j++){
        tmp3+=s1[j];
    }
    for(int j=l;j<=r;j++){
        tmp1+=s1[j];
    }
    for(int j=l;j<=r;j++){
        tmp1+=s2[j];
    }
    return {tmp1,{tmp2,tmp3}};
}
void insert(int k,string s,int id){
    int m=s.length();
    for(int i=0;i<m;i++){
        if(t[k][s[i]-'a']==0){
            t[k][s[i]-'a']=++tot;
        }
        k=t[k][s[i]-'a'];
    }
    cnt[k].push_back(id);
}
set<int> st;
void query(int k,string s,bool rev){
    for(int j:cnt[k]){
        if(rev){
            if(st.count(j)!=0){
                // cerr<<j<<"\n";
                ans++;
            }
        }else{
            st.insert(j);
        }
    }
    int m=s.length();
    for(int i=0;i<m;i++){
        if(t[k][s[i]-'a']==0){
            return;
        }
        k=t[k][s[i]-'a'];
        for(int j:cnt[k]){
            if(rev){
                if(st.count(j)!=0){
                    // cerr<<j<<"\n";
                    ans++;
                }
            }else{
                st.insert(j);
            }
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    string s1,s2;
    string tmp1,tmp2,tmp3;

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        auto ret=split(s1,s2);
        tmp1=ret.first;
        tmp2=ret.second.first;
        tmp3=ret.second.second;
        if(tmp1==""){
            continue;
        }
        if(mp.count(tmp1)==0){
            mp[tmp1]={tot+1,tot+2};
            tot+=2;
        }
        insert(mp[tmp1].first,tmp2,i);
        insert(mp[tmp1].second,tmp3,i);
    }

    for(int i=1;i<=q;i++){
        cin>>s1>>s2;
        auto ret=split(s1,s2);
        tmp1=ret.first;
        tmp2=ret.second.first;
        tmp3=ret.second.second;
        st.clear();
        ans=0;
        query(mp[tmp1].first,tmp2,false);
        query(mp[tmp1].second,tmp3,true);
        cout<<ans<<"\n";
    }
    return 0;
}
