#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int t,n,x[N],ans;
void input(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i];
}
int col[N],score;
void dfs(int k){
	if(k==n+1){
		ans=max(score,ans);
		return;
	}
	bool flag=0;int i=k-1;
	for(;i>=1;i--)
		if(col[i]==col[k]){
			flag=1;
			break;
		}
	if(flag&&x[k]==x[i])score+=x[k];
	dfs(k+1);
	if(flag&&x[k]==x[i])score-=x[k];
	col[k]=1;
	flag=0;i=k-1;
	for(;i>=1;i--)
		if(col[i]==col[k]){
			flag=1;
			break;
		}
	if(flag&&x[k]==x[i])score+=x[k];
	dfs(k+1);
	if(flag&&x[k]==x[i])score-=x[k];
	col[k]=0;
	
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		input();
		ans=score=0;
		dfs(1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
