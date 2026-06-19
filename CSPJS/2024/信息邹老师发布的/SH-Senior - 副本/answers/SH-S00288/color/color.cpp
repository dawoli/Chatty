#include <iostream>
using namespace std;
int t=0;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n=0;
		cin>>n;
		int ans=0;
		int k[201];
		for(int j=1;j<=n;j++){
			cin>>k[j];
		}
		for(int l=1;l<=n;l++){
			int vis[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			for(int r=l+1;r<=n;r++){
				for(int h=l;h<=r;h++){
						vis[h]=1;
				}
				for(int f=n;f>=1;f--){
					for(int e=f-1;e>=1;e--){
						if(vis[f]==vis[e]){
							ans+=k[f];
						}
					}
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

