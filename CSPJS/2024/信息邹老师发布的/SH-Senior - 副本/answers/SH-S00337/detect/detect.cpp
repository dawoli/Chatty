#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int d[100001]={},v[100001]={},a[100001]={},p[100001]={},you[100001];
		int n=0,m=0,L=0,V=0,ans=0;
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;j++)	cin>>d[j]>>v[j]>>a[j];
		for(int j=1;j<=m;j++)	cin>>p[j];
		for(int j=1;j<=n;j++){
			if(a[j]==0&&v[j]>V){
				int a=1;
				for(int k=1;k<=m;k++)
					if(p[k]>=d[j])	a++;
				if(a>1)	ans++;
			}
			else if(a[j]>0&&v[j]>=V){
				int a=1;
				for(int k=1;k<=m;k++)
					if(p[k]>d[j])	a++;
				if(a>1)	ans++;
			}
			else if(a[j]>0&&v[j]<V){
				float dis=float(V*V-v[j]*v[j])/(2*a[j]);
				int a=1;
				for(int k=1;k<=m;k++)
					if(p[k]>dis+d[j])	a++;
				if(a>1)	ans++;
			}
			else if(a[j]<0&&v[j]>V){
				float dis=float(V*V-v[j]*v[j])/(2*a[j]);
				int a=1;
				for(int k=1;k<=m;k++)
					if(d[j]<=p[k]&&p[k]<dis+d[j])	a++;
				if(a>1)	ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
