#include <iostream>
using namespace std;
int n=0;
int m[100001];
int k[100001];
int vis[100001];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		k[i]=m[i];
		vis[i]=2;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(m[i]>k[j] && vis[j]!=1){
				vis[j]=1;
				break;
			}
			else continue;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==2){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

