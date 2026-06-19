#include<bits/stdc++.h>
#define error 0.00000001
using namespace std;
long long d[100009],v[1000009],a[100009],p[100009];
int f[3009][3009];
bool ok[29][29];
bool check[29];
int maxi=0;
int n,m,l,V;
void compare(int cnt){
	bool flag=0;
	for(int i=1;i<=n;i++){
		if(ok[i][0]==0) continue;
		flag=0;
		for(int j=1;j<=m;j++){
			if(check[j]==0) continue;
			if(ok[i][j]) flag=1;
		}
			
		if(!flag) return;
	}
	maxi=max(maxi,cnt);
}
void dfs(int i,int cnt){
	if(i==m+1){
		compare(cnt);
		return;
	}
	check[i]=0;
	dfs(i+1,cnt+1);
	check[i]=1;
	dfs(i+1,cnt);
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		maxi=0;
		cin>>n>>m>>l>>V;
		bool ok0=0,ok1=0,ok2=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]>0) ok0=ok1=1;
			if(a[i]<0) ok1=ok2=1;
			if(a[i]==0) ok0=ok2=1;
		}
		for(int i=1;i<=m;i++)
			cin>>p[i];
		if(!ok2){
			for(int i=1;i<=n;i++){
				if(d[i]>p[m]) continue;
				int len=p[m]-d[i];
				double cmp=sqrt(v[i]*v[i]+2*a[i]*len);
				if(cmp-(V*1.00000000)>error) ans++;
			}
			if(ans==0) m++;
			cout<<ans<<" "<<m-1<<"\n";
			continue;
		}
		if(!ok1){
			for(int i=1;i<=n;i++)
				if(v[i]>V&&p[m]>=d[i]) ans++;
			if(ans==0) m++;
			cout<<ans<<" "<<m-1<<"\n";
			continue;
		}
		if(!ok0){
			for(int i=1;i<=n;i++){
				if(d[i]>p[m]) continue;
				int l=1,r=m;
				while(l<r){
					int mid=(l+r+1)/2;
					if(p[mid]>d[i])
						r=mid;
					else if(p[mid]<d[i])
						l=mid+1;
					else{
						l=mid;
						break;
					}
				}
				v[i]+=(p[m]-d[i])*a[i];
				if(v[i]>V)
					ans++;
				if(ans==0)
					m++;
				cout<<ans<<" "<<m-1<<"\n";
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(d[i]>p[j]) continue;
				double cmp=sqrt((p[j]-d[i])*a[i]*2+v[i]*v[i]);
				if(cmp-V>error){
					ok[i][j]=1;
					if(!ok[i][0]) ans++;
					ok[i][0]=1;
				}
			}
		}
		dfs(1,0);
		cout<<ans<<" "<<maxi<<"\n";
	}
	return 0;
}
