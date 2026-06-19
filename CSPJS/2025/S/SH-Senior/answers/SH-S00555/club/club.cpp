#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int T;
ll n,a[N],b[N],c[N],cnt[5],p[N];

//For:100pts

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ll ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ans+=max(a[i],max(b[i],c[i]));
			if(a[i]>=b[i] && a[i]>=c[i])cnt[1]++;
			else if(b[i]>=a[i] && b[i]>=c[i])cnt[2]++;
			else if(c[i]>=b[i] && c[i]>=a[i])cnt[3]++;
		}
		if(cnt[1]>n/2){
			int op=0;
			for(int i=1;i<=n;i++){
				if(a[i]>=b[i] && a[i]>=c[i]){
					p[++op]=a[i]-max(b[i],c[i]);
				}
			}
			sort(p+1,p+cnt[1]+1);
			for(int i=1;i<=cnt[1]-n/2;i++){
				ans-=p[i];
			}
		}
		if(cnt[2]>n/2){
			int op=0;
			for(int i=1;i<=n;i++){
				if(b[i]>=a[i] && b[i]>=c[i]){
					p[++op]=b[i]-max(a[i],c[i]);
				}
			}
			sort(p+1,p+cnt[2]+1);
			for(int i=1;i<=cnt[2]-n/2;i++){
				ans-=p[i];
			}
		}
		if(cnt[3]>n/2){
			int op=0;
			for(int i=1;i<=n;i++){
				if(c[i]>=b[i] && c[i]>=a[i]){
					p[++op]=c[i]-max(b[i],a[i]);
				}
			}
			sort(p+1,p+cnt[3]+1);
			for(int i=1;i<=cnt[3]-n/2;i++){
				ans-=p[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
