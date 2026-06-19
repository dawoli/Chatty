#include<bits/stdc++.h>
using namespace std;
long long ans;
void dfs(int n,long long num){
	if(n==1) return;
	if(n==0){
		ans=num;
		return;
	}
	num*=10;
	if(num>ans&&ans!=0)return;
	if(n>=7)dfs(n-7,num+8);
	if(n>=6&&num!=0)dfs(n-6,num);
	else if(n>=6) dfs(n-6,num+6);
	if(n>=2)dfs(n-2,num+1);
	if(n>=5)dfs(n-5,num+2);
	if(n>=3)dfs(n-3,num+7);
	if(n>=4)dfs(n-4,num+4);
	
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		ans=0;
		dfs(n,0);
		if(ans==0)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
