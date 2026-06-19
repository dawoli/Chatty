#include<bits/stdc++.h>
using namespace std;
int T,n,a[200005];
long long ans;
bool c[200005];
void DFS(int now){
	if(now>n){
		long long C=0;
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(c[j]==c[i]){
					if(a[i]==a[j])C+=a[i];
					break;
				}
			}
		}
		ans=max(ans,C);
		return;
	}
	c[now]=0;
	DFS(now+1);
	c[now]=1;
	DFS(now+1);
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		DFS(2);
		cout<<ans<<endl;
	}
	return 0;
} 
