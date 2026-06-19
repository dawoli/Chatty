#include<bits/stdc++.h>
using namespace std;
int a[100005],T,n;
int vis[100005];
int main(){
	freopen("duel.in","w",stdin);
	freopen("duel.out","r",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int j=1;j<=n;j++){
			for(int i=1;i<n;i++){
				if(a[i+1]>a[i]&&vis[i+1]==0){
					vis[i]=-1;
					a[i]=-1;
					vis[i+1]=1;
				}else{
					continue;
				}
			}
		}
	}
}
