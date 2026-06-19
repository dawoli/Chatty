#include<bits/stdc++.h>
using namespace std;
#define N 100005
int mi=2147483647,a=0,c;
void dfs(int x){
	
	if(x==0&&a>0){
		mi=min(a,mi);
		a=a/10;
		return;
	}
	if(x==1||x<0){
		a=a/10;
		return;
	}
	if(x>=7){
		a=a*10+8;
		dfs(x-7);
	}
	if(x>=6){
		if(a==0) a=a*10+6;
		else a=a*10;
		dfs(x-6);
	}
	if(x>=5){
		a=a*10+2;
		dfs(x-5);
	}
	if(x>=4){
		a=a*10+4;
		dfs(x-4);
	}
	if(x>=3){
		a=a*10+7;
		dfs(x-3);
	}
	if(x>=2){
		a=a*10+1;
		dfs(x-2);
	}
	a=a/10;
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int x,y;
	cin>>x;
	for(int i=0;i<x;++i){
		cin>>y;
		dfs(y);
		a=0;
		if(mi==2147483647) cout<<-1;
		else cout<<mi;
		mi=2147483647;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
