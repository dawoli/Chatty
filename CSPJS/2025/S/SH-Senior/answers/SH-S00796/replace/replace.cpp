#include<bits/stdc++.h>
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
#define ll long long
const int mod[2]={998244353,1000000007};
ll trans[2][5000006];
void init(){
    trans[0][0]=trans[1][0]=1;
    for(int i=1;i<=5000000;i++)
        for(int j=0;j<2;j++)
            trans[j][i]=trans[j][i-1]*(j==0?11:29)%mod[j];
}
int read(){
    int x=0;
    bool neg=0;
    char ch=gc();
    while(ch<'0'||ch>'9')
        neg|=(ch=='-'),
        ch=gc();
    while(ch>='0'&&ch<='9')
        x=x*10+(ch^48),
        ch=gc();
    return neg?-x:x; //             -2147483648 bug
}
int n,q;
struct string_hash{
    int length,H[2];
    friend bool operator ==(const string_hash &a,const string_hash &b){
        return a.length==b.length&&a.H[0]==b.H[0]&&a.H[1]==b.H[1];
    }
    friend bool operator <(const string_hash &a,const string_hash &b){
        return a.length<b.length||(a.length==b.length&&
                a.H[0]<b.H[0]||(a.H[0]==b.H[0]&&a.H[1]<b.H[1]));
    }
    string_hash del(string_hash b){
        for(int i=0;i<2;i++)
            b.H[i]=(H[i]-b.H[i]*trans[i][length-b.length]%mod[i]+mod[i])%mod[i];
        b.length=length-b.length;
        return b;
    }
    void extend_front(int x){
        length++;
        for(int i=0;i<2;i++)
            H[i]=(H[i]*trans[i][1]+x)%mod[i];
    }
    void extend_back(int x){
        for(int i=0;i<2;i++)
            H[i]=(H[i]+x*trans[i][length])%mod[i];
        length++;
    }
    void init(){
        length=H[0]=H[1]=0;
    }
};
int cnt;
struct string_suitable{
    string_hash M[2];
    vector<string_hash>L,R;
    friend bool operator <(const string_suitable &a,const string_suitable &b){
        return a.M[0]<b.M[0]||(a.M[0]==b.M[0]&&a.M[1]<b.M[1]);
    }
    bool suitable_in(string_suitable &b){
        if(M[0]==b.M[0]&&M[1]==b.M[1]&&L.size()<=b.L.size()&&R.size()<=b.R.size()){
            if(L[L.size()-1]==b.L[L.size()-1]&&R[R.size()-1]==b.R[R.size()-1])
                return 1;
            return 0;
        }
        return 0;
    }
}T[200005],cur;
bool read(string_suitable &u){
    char ch=gc();
    string A="",B="";
    while(ch<'a'||ch>'z')
        ch=gc();
    while(ch>='a'&&ch<='z')
        A+=ch,
        ch=gc();
    while(ch<'a'||ch>'z')
        ch=gc();
    while(ch>='a'&&ch<='z')
        B+=ch,
        ch=gc();
    if(A.size()!=B.size()||A==B)return 0;
    int i=0,j=A.size()-1;
    while(A[i]==B[i])i++;
    while(A[j]==B[j])j--;
    u.M[0].init();
    u.M[1].init();
    u.L.clear();
    u.R.clear();
    for(int k=i;k<=j;k++)
        u.M[0].extend_back(A[k]),
        u.M[1].extend_back(B[k]);
    string_hash L,R;
    L.init();
    R.init();
    u.L.push_back(L);
    u.R.push_back(R);
    for(int k=i-1;k>=0;k--){
        L.extend_front(A[k]);
        u.L.push_back(L);
    }
    for(int k=j+1;k<A.size();k++){
        R.extend_back(A[k]);
        u.R.push_back(R);
    }
    return 1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    init();
    n=read();q=read();
    while(n--){
        if(read(T[cnt+1]))
            cnt++;
    }
    sort(T+1,T+cnt+1);
    while(q--){
        if(!read(cur)){
            printf("0\n");
            continue;
        }
        int i=lower_bound(T+1,T+cnt+1,cur)-T,
            j=upper_bound(T+1,T+cnt+1,cur)-T;
        int ans=0;
        for(;i<j;i++){
            if(T[i].suitable_in(cur))
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}