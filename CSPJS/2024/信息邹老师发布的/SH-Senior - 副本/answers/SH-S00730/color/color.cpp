#include<bits/stdc++.h>
using namespace std;
int a[100005],ans;
bool vis[100005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(a[j]==a[i]){
					if(vis[j-1]==0&&vis[i-1]==0){
						vis[j]=1;
						vis[i]=1;
						ans++;
					}else{
						continue;
					}
				}else{
					continue;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;	
}

