#include<bits/stdc++.h>
using namespace std;
const int N=200009;
long long T,n,ans,a[N],b[N],c[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        priority_queue<long long> pa,pb,pc;
        ans=0;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",a+i,b+i,c+i);
            if(a[i]>=b[i]&&b[i]>=c[i]){
                pa.push(b[i]-a[i]);
                ans+=a[i];
            }
            else if(a[i]>=c[i]&&c[i]>=b[i]){
                pa.push(c[i]-a[i]);
                ans+=a[i];
            }
            else if(b[i]>=a[i]&&a[i]>=c[i]){
                pb.push(a[i]-b[i]);
                ans+=b[i];
            }
            else if(b[i]>=c[i]&&c[i]>=a[i]){
                pb.push(c[i]-b[i]);
                ans+=b[i];
            }
            else if(c[i]>=a[i]&&a[i]>=b[i]){
                pc.push(a[i]-c[i]);
                ans+=c[i];
            }
            else if(c[i]>=b[i]&&b[i]>=a[i]){
                pc.push(b[i]-c[i]);
                ans+=c[i];
            }
        }
        while(pa.size()>n/2){
            ans+=pa.top();
            pa.pop();
        }
        while(pb.size()>n/2){
            ans+=pb.top();
            pb.pop();
        }
        while(pc.size()>n/2){
            ans+=pc.top();
            pc.pop();
        }
        printf("%lld\n",ans);
    }
    return 0;
}
