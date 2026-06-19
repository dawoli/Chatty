#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
int d[100001],u[100001],a[100001];
int p[100001],ans=0;
int v1=0;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		v1=0;
		ans=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>u[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			v1=max(v1,p[i]);
		}
		for(int i=1;i<=n;i++){
			if(d[i]<=v1&&u[i]>v){
				ans++;
			}
		}
		cout<<ans<<" "<<m-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
