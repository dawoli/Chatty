#include <bits/stdc++.h>
using namespace std;

bool be_M;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<typename T>
void read(T &a){
    a=0;char c;int f=1;
    while(!isdigit(c=getchar()))if(c=='-')f=-1;
    do a=a*10+c-'0';
    while(isdigit(c=getchar()));
    a*=f;
}
template<typename T>
void write(T a){
    if(a<0)putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
namespace GSK{

typedef long long ll;
const int MAXN=400010;
const int Base=131,P1=1000000009,P2=1000000123;
char S[40000010],*Spt;
int n,q;
char *s[MAXN][2];
int len[MAXN][2];
char t[2][10000010];
int len1,len2;
pair<int,int> ht[2][10000010];
ll pw[2][10000010];
pair<int,int> gethash(char *s,int n){
    pair<int,int> res{0,0};
    for(int i=0;i<n;++i){
        res.first=((ll)res.first*Base+s[i]-'a'+78)%P1;
        res.second=((ll)res.second*Base+s[i]-'a'+78)%P2;
    }
    return res;
}
pair<int,int> gethasht(int o,int l,int r){
    if(l==0)return ht[o][r];
    return {(ht[o][r].first+P1-ht[o][l-1].first*pw[0][r-l+1]%P1)%P1,
            (ht[o][r].second+P2-ht[o][l-1].second*pw[1][r-l+1]%P2)%P2};
}
map<pair<pair<int,int>,pair<int,int>>,int> mpcnt;
const int B=80;
map<pair<pair<int,int>,pair<int,int>>,int> mp;
vector<int> pos[MAXN];
int pl[MAXN],pr[MAXN];
pair<pair<int,int>,pair<int,int>> ph[MAXN];
void main(){
    pw[0][0]=pw[1][0]=1;
    for(int i=1;i<=500000;++i){
        pw[0][i]=pw[0][i-1]*Base%P1;
        pw[1][i]=pw[1][i-1]*Base%P2;
    }
    read(n),read(q);
    Spt=&S[0];
    for(int i=1;i<=n;++i){
        for(int o=0;o<2;++o){
            s[i][o]=Spt;
            scanf("%s",s[i][o]);
            len[i][o]=strlen(s[i][o]);
            Spt+=len[i][o];
        }
        int p=0;
        while(p<min(len[i][0],len[i][1])&&s[i][0][p]==s[i][1][p])++p;
        pair<int,int> res1=gethash(s[i][0],len[i][0]);
        pair<int,int> res2=gethash(s[i][1],len[i][1]);
        ph[i]={res1,res2};
        if(len[i][0]<=B){
            mpcnt[{res1,res2}]++;
        }else{
            int l=0;
            while(l<len[i][0]&&s[i][0][l]==s[i][1][l])++l;
            if(l==len[i][0])continue;
            int r=0;
            while(r<len[i][0]&&s[i][0][len[i][0]-1-r]==s[i][1][len[i][0]-1-r])++r;
            int id;
            res1=gethash(s[i][0]+l,len[i][0]-l-r);
            res2=gethash(s[i][1]+l,len[i][0]-l-r);
            auto it=mp.find({res1,res2});
            pl[i]=l,pr[i]=r;
            if(it==mp.end()){
                mp[{res1,res2}]=id=mp.size()+1;
            }else{
                id=it->second;
            }
            pos[id].emplace_back(i);

        }
        // printf("{%lld,%lld} {%lld,%lld}\n",res1.first,res1.second,res2.first,res2.second);
        // for(int j=0;j<len[i][0];++j)putchar(s[i][0][j]);puts("");
        // for(int j=0;j<len[i][1];++j)putchar(s[i][1][j]);puts("");
    }
    while(q--){
        scanf("%s%s",t[0],t[1]);
        len1=strlen(t[0]);
        len2=strlen(t[1]);
        if(len1!=len2){
            puts("0");
            continue;
        }
        ht[0][0]={t[0][0]-'a'+78,t[0][0]-'a'+78};
        ht[1][0]={t[1][0]-'a'+78,t[1][0]-'a'+78};
        for(int i=1;i<len1;++i){
            ht[0][i].first=((ll)ht[0][i-1].first*Base+t[0][i]-'a'+78)%P1;
            ht[1][i].first=((ll)ht[1][i-1].first*Base+t[1][i]-'a'+78)%P1;
            ht[0][i].second=((ll)ht[0][i-1].second*Base+t[0][i]-'a'+78)%P2;
            ht[1][i].second=((ll)ht[1][i-1].second*Base+t[1][i]-'a'+78)%P2;
        }
        int l=0,r=0;
        while(l<len1&&t[0][l]==t[1][l])++l;
        while(r<len1&&t[0][len1-1-r]==t[1][len1-1-r])++r;
        // assert(l+r<len1);
        int ans=0;
        for(int i=0;i<=l;++i)
            for(int j=len1-1-r;j<=i+B-1&&j<len1;++j){
                pair<int,int> res1=gethasht(0,i,j);
                pair<int,int> res2=gethasht(1,i,j);
                auto it=mpcnt.find({res1,res2});
                if(it!=mpcnt.end())ans+=it->second;
            }
        pair<int,int> res1=gethasht(0,l,len1-1-r);
        pair<int,int> res2=gethasht(1,l,len1-1-r);
        auto it=mp.find({res1,res2});
        if(it!=mp.end()){
            int id=it->second;
            for(int &x:pos[id]){
                if(pl[x]>l||pr[x]>r)continue;
                res1=gethasht(0,l-pl[x],l-pl[x]+len[x][0]-1);
                res2=gethasht(1,l-pl[x],l-pl[x]+len[x][0]-1);
                ans+=ph[x]==make_pair(res1,res2);
            }
        }
        printf("%d\n",ans);
    }

}
}
bool ed_M;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int T=1;//cin>>T;
    while(T--)GSK::main();
    // cerr<<(double)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    // cerr<<(&ed_M-&be_M)/1024.0/1024.0<<" MB"<<endl;
    return 0;
}