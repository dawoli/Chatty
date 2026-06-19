#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int t;
int n,m,L,V,d[N],v[N],a[N],p[N],l[N],r[N],to[N],ans1,ans2;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        ans1=ans2=0;
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&p[i]),to[i]=m+1;
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                if(v[i]>V) l[i]=d[i];
                else{
                    if((V*V-v[i]*v[i])%(2*a[i])==0) l[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i])+1;
                    else l[i]=d[i]+ceil(1.0*(V*V-v[i]*v[i])/(2*a[i]));
                }
                l[i]=lower_bound(p+1,p+1+m,l[i])-p;
                r[i]=m;
            }
            else if(a[i]==0){
                if(v[i]>V) l[i]=lower_bound(p+1,p+1+m,d[i])-p;
                else l[i]=m+1;
                r[i]=m;
            }
            else{
                if(v[i]<=V){
                    l[i]=n+1,r[i]=m;
                    continue;
                }
                l[i]=lower_bound(p+1,p+1+m,d[i])-p;
                if((-V*V+v[i]*v[i])%(-2*a[i])==0) r[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i])-1;
                else r[i]=d[i]+floor(1.0*(V*V-v[i]*v[i])/(2*a[i]));
                r[i]=upper_bound(p+1,p+1+m,r[i])-p-1;
            }
            if(l[i]>r[i]) continue;
            to[l[i]]=min(to[l[i]],r[i]);
            ans1++;
            // cout<<l[i]<<" "<<r[i]<<"\n";
        }
        int lst=m+1;
        // for(int i=1;i<=m;i++) cout<<to[i]<<" ";
        // cout<<"\n";
        for(int i=m;i>=1;i--){
            if(to[i]==m+1) continue;
            if(to[i]>=lst) to[i]=m+1;
            else lst=to[i];
        }
        // for(int i=1;i<=m;i++) cout<<to[i]<<" ";
        // cout<<"\n";
        for(int i=1;i<=m;){
            if(to[i]==m+1){
                i++;
                continue;
            }
            i=to[i]+1;
            ans2++;
        }
        cout<<ans1<<" "<<m-ans2<<"\n";
    }
	return 0;
}
