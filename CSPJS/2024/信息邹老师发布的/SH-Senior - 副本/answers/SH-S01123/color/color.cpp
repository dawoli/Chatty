#include<bits/stdc++.h>
using namespace std;
int T;
int n,ans=-1;
int a[200005];
bool c[200005];
int check(){
	int ans1=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(c[j]==c[i]){
				if(a[j]==a[i]){
					ans1+=a[i];
				}
				break;
			}
		}
	}
	return ans1;
}
void dfs(int step){
	if(step>n){
		ans=max(ans,check());
//		for(int i=1;i<=n;i++){
//			cout<<c[i]<<"¡¡"; 
//		}
//		cout<<endl;
		return;
	}
	//red
	c[step]=1;
	dfs(step+1);
	//blue
	c[step]=0;
	dfs(step+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
	}
	return 0;
}
