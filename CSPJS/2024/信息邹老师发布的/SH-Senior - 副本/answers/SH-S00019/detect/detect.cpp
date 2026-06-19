#include <bits/stdc++.h>
using namespace std;

int t,n,m,l,v,d,vi,a,p;
bool vis[1000005];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>l>>v;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>d>>vi>>a;
			if(a==0){
				if(vi>v){
					for(int i=d;i<=l;i++){
						vis[i]=true;
					}
					cnt++;
				}
			}else if(a<0){
				if(vi>v){
					for(int i=0;i<=(v*v-vi*vi)/(2*a);i++){
						vis[d+i]=true;
					}
					if((v*v-vi*vi)/(2*a)>=0) cnt++;
				}
			}else{
				for(int i=(v*v-vi*vi)/(2*a);i<=l;i++){
					vis[i]=true;
				}
				if((v*v-vi*vi)/(2*a)<=l) cnt++;
			}
		} 
		int ans=0;
		while(m--){
			cin>>p;
			if(!vis[p]){
				ans++;
			}
		}
		cout<<cnt<<' '<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
