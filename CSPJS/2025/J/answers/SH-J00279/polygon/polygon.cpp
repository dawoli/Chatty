#include<bits/stdc++.h>
using namespace std;

int n,a[5009],ans;

void dfs(int id,int sum,int k,int x,bool b){
	if(sum>k*2&&x>=3&&b==false){
		ans++;
	}
	if(id>n){
		return;
	}
	dfs(id+1,sum+a[id],a[id],x+1,false);
	dfs(id+1,sum,k,x,true);
	return;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0,false); 
	cout<<ans;
	return 0;
}
/*
我不行了，弄了1h迷惑做法一点没对（虽然现在还有1.75h结束）
话说这个998244353是个什么梗吗？ 
随便写个dfs交了吧。。。 
预估40分 
总分340（？） 
题目难度大概是橙橙黄绿 
所以这题正解是什么？
看着有点像DP但实际感觉无法实现 
*/ 
