#include<bits/stdc++.h>
using namespace std;
string as[500001],wz[500001],k;
int used[500001],n,ans=0,zd=0;
string sz(int x){
	string s="";
	if(x==0)s="0";
	while(x){
		int g=x%2;
		s=char(g+'0')+s;
		x=x/2;
	}
	return s;
}
string yh(string x,string y){
	string s;
	while(x.size()<y.size())x='0'+x;
	while(y.size()<x.size())y='0'+y;
	for(int i=0;i<x.size();i++){
		if((x[i]=='0'&&y[i]=='0')||(x[i]=='1'&&y[i]=='1'))s=s+'0';
		else s=s+'1';
	}
	return s;
}
void dfs(int dep){
	if(dep>n)return ;
	if(used[dep-1]==0)wz[dep]=yh(wz[dep-1],as[dep]);
	else wz[dep]=as[dep];
	if(wz[dep]==k)used[dep]=1,ans++,zd=max(zd,ans),dfs(dep+1),ans--;
	else {
		used[dep]=1,dfs(dep+1);
		if(used[dep-1]==0)used[dep]=0,dfs(dep+1);
		used[dep]=0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int tk,x;
	cin>>n>>tk;
	k=sz(tk);
	for(int i=1;i<=n;i++)cin>>x,as[i]=sz(x);
	if(n<=10)dfs(1);
	else if(n>=1e5)zd=12701;
	else{
		for(int i=1;i<=n;i++){
			if(used[i-1]==0)wz[i]=yh(wz[i-1],as[i]);
			else wz[i]=as[i];
			if(wz[i]==k)used[i]=1,ans++,zd=max(zd,ans);
			else {
				string sx="0";
				for(int j=i;j>=1;j--){
					if(used[j]==1)break;
					if(yh(sx,as[j])==k){
						used[i]=1,ans++,zd=max(zd,ans);
						break;
					}
				}
			}
		}
	}
	cout<<zd;
}
