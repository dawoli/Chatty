#include <stdio.h>
#include <string.h>
#define ull unsigned long long
const int MAXEL=5e6+10,MAXN=2e5+10,base=1331;
ull pb[MAXEL];
ull h1[MAXEL];
ull h2[MAXEL];
char s1[MAXEL],s2[MAXEL];
ull ht1[MAXN],ht2[MAXN];
int szt[MAXN];
char t1[MAXEL],t2[MAXEL];
int n,q;
void init(int n){
    pb[0]=1;
    for (int i=1;i<=n;++i){
        pb[i]=pb[i-1]*base;
    }
}
void solve(){
    scanf("%s%s",s1,s2);
    int szs=strlen(s1+1);
    for (int i=1;i<szs;++i){
        h1[i]=h1[i-1]*base+s1[i];
        h2[i]=h2[i-1]*base+s2[i];
    }
    int ans=0;
    for (int i=1;i<=n;++i){
        scanf("%s%s",t1+1,t2+1);
        szt[i]=strlen(t1+1);
        for (int j=1;j<=szt[i];++j){
            ht1[j]=ht1[j-1]*base+t1[j];
            ht2[j]=ht2[j-1]*base+t2[j];
        }
        for (int j=1;j<=szs-szt[i];++j){
            if (h1[j+szt[i]]-h1[j]*pb[szt[i]-1]==ht1[i]){
                if (h1[szs]-ht1[i]*pb[szs-j-szt[i]-1]
                    +ht2[i]*pb[szs-j-szt[i]-1]==h2[szs]){
                    ++ans;
                }
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    init(MAXEL);
    scanf("%d%d",&n,&q);
    for (int _=0;_<q;++_) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/