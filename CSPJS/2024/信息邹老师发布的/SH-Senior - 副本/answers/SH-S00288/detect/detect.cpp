#include <iostream>
using namespace std;
int t=0;
int n=0,m=0,l=0,v=0;
int p[100001];
struct st{
	int u,o,q;
}f[3001];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int w=1;w<=t;w++){
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>f[i].u>>f[i].o>>f[i].q;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		int ans=0;
		int s=9999;
		for(int i=1;i<=n;i++){
			if(f[i].q==0){
				if(f[i].o>v){
					ans++;
					s=min(s,f[i].u);
				}
			}
			else continue;
		}
		int ans2=0;
		for(int i=1;i<=m;i++){
			if(p[i]<s){
				ans2++;
			}
		}
		cout<<ans<<" "<<ans2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

