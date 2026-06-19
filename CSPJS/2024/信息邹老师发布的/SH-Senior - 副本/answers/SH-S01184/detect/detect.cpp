#include<bits/stdc++.h>
using namespace std;
double speed(int u,int a,int s){
	double k=0;
	k=sqrt(u*u+2*s*a);
	return k-0.0001;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,l,v,sum=0;
		cin>>n>>m>>l>>v;
		int d[n+1],u[n+1],a[n+1],p[m+1],s[m+1];
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++){
			cin>>d[i]>>u[i]>>a[i];
		}
		for(int i=1;i<=m;i++)cin>>p[i];
		for(int i=1;i<=n;i++){
			if(d[i]>p[m])continue;
			else if(a[i]==0&&u[i]>v&&d[i]<p[m]){
				sum++;
				s[m]=1;
			}
			else if(a[i]>0&&speed(u[i],a[i],p[m]-d[i])>v*1.0&&d[i]<p[m]){
				sum++;
				s[m]=1;
			}
			else if(a[i]<0){
				for(int j=m;j>=1;j--){
					if(d[i]>p[j])continue;
					if(speed(u[i],a[i],p[j]-d[i])<=0.0){
						continue;
					}
					if(speed(u[i],a[i],p[j]-d[i])>v*1.0){
						sum++;
						s[j]=1;
						break;
					}
				}
			}
		}
		int add=0;
		for(int i=1;i<=m;i++){
			if(s[i]==0)add++;
		}
		cout<<sum<<" "<<add<<"\n";
	}
	return 0;
}
