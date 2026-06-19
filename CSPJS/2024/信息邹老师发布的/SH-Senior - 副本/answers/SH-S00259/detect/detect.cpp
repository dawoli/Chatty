#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,w,d[100005],v[100005],a[100005],p[100005],c,b,f,ans1;
vector<int> k[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>w;
		ans1=0;
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(k,0,sizeof(k));
		for(int i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)
			cin>>p[i];
		for(int i=1;i<=n;i++){
			f=0;
			if(a[i]==0){
				if(v[i]>w && d[i]<=p[m]){
					f=1;
					for(int j=1;j<m;j++)
						if(p[j]>d[i]) k[i].push_back(j);
				}
			}else if(a[i]>0){
				c=l*2*a[i]+1;
				if(v[i]>w) b=d[i]*2*a[i]-1;
				else b=d[i]*2*a[i]+w*w-v[i]*v[i];
				for(int j=1;j<m;j++)
					if(b<p[j]*2*a[i] && p[j]*2*a[i]<c){
						k[i].push_back(j);
						f=1;
					}
			}else{
				c=d[i]*2*a[i]+w*w-v[i]*v[i];
				if(v[i]>w) b=d[i]*2*a[i]+1;
				else b=l*2*a[i]+1;
				for(int j=1;j<m;j++)
					if(b>p[j]*2*a[i] && p[j]*2*a[i]>c){
						k[i].push_back(j);
						f=1;
					}
			}
			ans1+=f;
		}
		cout<<ans1<<' ';
		if(ans1) cout<<m-1<<'\n';
		else cout<<m<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
