#include<bits/stdc++.h>
using namespace std;

int a[500005],sa[500005];
struct node{
    int l,r;
} m[5000005];
bool cmp(node x,node y){
    if(x.r==y.r) return x.l>y.l;
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    long long cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sa[i]=sa[i-1]^a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int num=sa[j]^sa[i];
            if(num==k){
                m[++cnt].l=i+1;
                m[cnt].r=j;
            }
        }
    }
    sort(m+1,m+cnt+1,cmp);
    int ans=1,last=m[1].r,p=2;
    while(p<=cnt){
        while(m[p].l<=last && p<=cnt) p++;
        if(p>cnt) break;
        ans++;
        last=m[p].r;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
