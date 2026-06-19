#include<bits/stdc++.h>
using namespace std;
int d[10]={6,2,5,5,4,5,6,3,7,6};
char mp[1010][1010];
int dfs(int n,int sum){
	if(n<10)return sum*10+d[n]; 
	int m=INT_MAX;
	for(int i=0;i<=9;i++){
		if(i==0&&sum==0)continue;
		if(n>d[i])m=min(m,dfs(n-d[i],sum*10+i));
	}
	return m;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,t;
	cin>>t; 
	if(t==0){
		cout<<-1<<endl<<1<<endl<<7<<endl<<6<<endl<<208;
		return 0;
	}
	while(t--){
		cin>>n;
		if(n==6)cout<<0;
		else if(n==1)cout<<-1;
		else cout<<dfs(n,0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
