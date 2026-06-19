#include<bits/stdc++.h>
using namespace std;

int t,cnt[1000005];
struct node{
	float d,v,a;
}a[100005];

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,l,v,p[100005],ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].v>>a[i].a;
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=n;i++){
			if(a[i].v>v&&a[i].a>=0){
				int flag=0;
				for(int j=1;j<=m;j++){
					if(p[j]>=a[i].d){
						flag=1;
						cnt[p[j]]++;
					}
				}
				if(flag) ans++;	
			}else if(a[i].v>v&&a[i].a<0){
				int flag=0;
				float len=(v*v-a[i].v*a[i].v)/(2*a[i].a);
				float ll=(0-a[i].v*a[i].v)/(2*a[i].a);
				for(int j=1;j<=m;j++){
					if(p[j]>=a[i].d&&p[j]<=(a[i].d+ll)&&p[j]<=(a[i].d+len)){
						flag=1;
						cnt[p[j]]++;
					}
				}
				if(flag) ans++;
			}else if(a[i].v<=v&&a[i].a>0){
				int flag=0;
				float len=(v*v-a[i].v*a[i].v)/(2*a[i].a);
				for(int j=1;j<=m;j++){
					if(p[j]>=(a[i].d+len)){
						flag=1;
						cnt[p[j]]++;
					}
				}
				if(flag) ans++;
			}else continue;
		}
		if(ans==0) cout<<ans<<" "<<m;
		else cout<<ans<<" "<<m-1<<endl;
	}
}
