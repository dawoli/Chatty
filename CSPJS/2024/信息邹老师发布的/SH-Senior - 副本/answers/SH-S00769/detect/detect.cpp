#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,m,l,V,ans=4000,sum;
int d[3005],a[3005],v[3005],p[3005],vt[3005][3005],jud[3005][3005],mm[3005];
int cv(int x,int a,int v0) {
	int vt2=v0*v0+2*a*x;
	if(vt2>0) return sqrt(vt2);
	else return 0;
}
void dfs(int x,int y,int num) {
	if(x>m) {
		int b=0;
		for(int i=1;i<=n;i++) if(mm[i]!=0) b++;
		if(b==num) ans=min(ans,y);
		return ;
	}
	dfs(x+1,y,num);
	for(int i=1;i<=n;i++) mm[i]+=jud[i][x];
	dfs(x+1,y+1,num);
	for(int i=1;i<=n;i++) mm[i]-=jud[i][x];
}
int main () {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t>0) {
		cin>>n>>m>>l>>V;
		if(n<=3000&&m<=3000) {
			int num=0;
			for(int i=1;i<=n;i++) {
				d[i]=a[i]=v[i]=p[i]=0;
				for(int j=1;j<=m;j++) {
					vt[i][j]=jud[i][j]=0;
				}
			}
			
			for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
			for(int i=1;i<=m;i++) cin>>p[i];
			for(int i=1;i<=n;i++) {
				bool flag=false;
				for(int j=1;j<=m;j++) {
					if(p[j]<d[i]) continue;
					int x=p[j]-d[i];
					vt[i][j]=cv(x,a[i],v[i]);
					if(vt[i][j]>V) {
						if(!flag) num++,flag=true;
						jud[i][j]=1;
					}
				}
			}
			dfs(0,0,num);
			cout<<num<<" "<<m-ans<<endl;
			ans=4000;
		}
		t--;
	}
	return 0;
}
