#include<bits/stdc++.h>
using namespace std;
double v[100100],a[100100],r,qq[100100],qh[100100];
long long n,m,l,d[100100],T,p[100100],caowei[100100],cnt[100100],ans;
bool vis[100100];
bool cmp(long long e,long long r){
	return e<r;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m>>l>>r;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(v[i]>r&&a[i]<0){
				qq[i]=d[i];
				qh[i]=d[i]+((r*r)+(v[i]*v[i]))/(2*a[i]);
			}
			else if(v[i]>r&&a[i]>=0){
				qq[i]=d[i];
				qh[i]=l;
			}
			else if(v[i]<=r&&a<=0){
				qq[i]=0;
				qh[i]=0;
			}
			else if(v[i]<=r&&a>0){
				qq[i]=d[i]+((r*r)+(v[i]*v[i]))/(2*a[i]);
				qh[i]=l;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(&p[1],&p[m],cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(qq[i]<p[j]&&p[j]<qh[i]){
					cnt[i]++;
					caowei[cnt[i]]=j;
					vis[i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				ans++;
			}
		}
		cout<<ans<<" "<<ans;
		for(int i=1;i<=n;i++){
			cnt[i]=0;
		}
	}
} 
