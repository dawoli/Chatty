#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+1;
int t,n,m,l,v,d[maxn],w[maxn],a[maxn],p[maxn],cnt;
double s,e;
bool A,B,vis[maxn];
int hi_speed() {
	int ans=0;
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(vis[j]) {
				continue;
			}
			s=e=-1;
			if(!a[j]&&w[j]>v) {
				s=d[j];
				e=l+1;
			}
			else if(a[j]>0&&d[i]+(v*v-w[j]*w[j])/(2*a[j])<l) {
				s=d[j]+(v*v-w[j]*w[j])/(2*a[j]);
				e=l+1;
			}
			else if(a[j]<0&&w[j]>v) {
				s=d[j];
				e=d[j]+(v*v-w[j]*w[j])/(2*a[j]);
			}
			if(!vis[j]&&s<=p[i]&&p[i]<e) {
				vis[j]=1;
				ans++;
				continue;
			}
		}
	}
	return ans;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n>>m>>l>>v;
		memset(vis,0,sizeof vis);
		A=B=0;
		for(int i=1;i<=n;i++) {
			cin>>d[i]>>w[i]>>a[i];
			if(a[i]) {
				A=1;
			}
			if(a[i]<=0) {
				B=1; 
			}
		}
		for(int i=1;i<=m;i++) {
			cin>>p[i];
		}
		int h=hi_speed();
		cout<<h<<" ";
		if((!A||!B)&&h) {
			cout<<m-1<<endl;
		}
		else if(!h) {
			cout<<m<<endl;
		}
		else {
			cout<<"I don't know"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
