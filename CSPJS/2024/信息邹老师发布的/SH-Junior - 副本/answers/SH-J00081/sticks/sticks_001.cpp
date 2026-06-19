#include<bits/stdc++.h>
using namespace std;
int mp[10];
string ans,INF;
void init(){
    mp['0']=6;
    mp['1']=2;
    mp['2']=5;
    mp['3']=5;
    mp['4']=4;
    mp['5']=5;
    mp['6']=6;
    mp['7']=3;
    mp['8']=7;
    mp['9']=6;
    for(int i=0;i<1e7;i++)ans.push_back('9');
    INF=ans;
}
string mincomp(string a,string b){
    if(a.size()<b.size())return a;
    else if(a.size()>b.size())return b;
    for(int i=0;i<a.size();i++){
        if(a[i]-'0'<b[i]-'0')return a;
        else if(a[i]-'0'>b[i]-'0')return b;
    }
    return a;
}
int n;
void dfs(string cur,int left){
    if(left<0)return;
    if(mincomp(ans,cur)==ans)return;
    if(!left){
        ans=mincomp(ans,cur);
        return;
    }
    if(left==6&&left!=n){
        ans=mincomp(ans,cur+"0");
        return;
    }else if(left==6&&left==n){
        ans="6";
        return;
    }
    if(left==2){
        ans=mincomp(ans,cur+'1');
        return;
    }
    if(left==5){
        ans=mincomp(ans,cur+'2');
        return;
    }
    if(left==4){
        ans=mincomp(ans,cur+'4');
        return;
    }
    if(left==3){
        ans=mincomp(ans,cur+'7');
        return;
    }
    if(left==7){
        ans=mincomp(ans,cur+'8');
        return;
    }
    if(left==n){
        for(char c='1';c<='9';c++){
            dfs(cur+c,left-mp[c]);
        }
    }else{
        for(char c='0';c<='9';c++){
            dfs(cur+c,left-mp[c]);
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    init();
    while(T--){
        scanf("%d",&n);
        if(n<=0){
            puts("-1");
            continue;
        }
        if(n%7==0){
            for(int i=0;i<n/7;i++)cout<<"8";
            puts("");
            continue;
        }
        dfs("",n);
        if(ans==INF)puts("-1");
        else cout<<ans<<endl,ans=INF;
    }
    return 0;
}