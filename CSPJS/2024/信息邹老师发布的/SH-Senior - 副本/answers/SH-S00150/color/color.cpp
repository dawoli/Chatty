#include<bits/stdc++.h>
using namespace std;
long long a[1000006],blue,red,ans;
void dfs(long long x,long long number){
	freopen("color.in","r",stdin);
	freopen("color.in","w",stdout);
	if(x==1){
		if(a[number]==red){
			ans+=red;
		}
		red=a[number];
		dfs(1,number+1);
		dfs(2,number+1);
	}
	else{
		if(a[number]==blue){
			ans+=blue;
		}
		blue=a[number];
		dfs(1,number+1);
		dfs(2,number+1);
	}
}
int main(){
	int t,n;
	cin>>t>>n;
	while(t--){
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1,1);
		dfs(2,1);
		cout<<ans;
	}
	return 0;
}











