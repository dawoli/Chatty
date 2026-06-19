/*
我真求你了
求你了我真
 
除了dfs想不到其他对的解法了，但是感觉还是有些熟悉
不管了明年再来
还好我只是初三 

话说注释真的有人看吗，还是说只是用代码检测违禁的部分 
*/ 
#include <bits/stdc++.h>  //我真求你了 
using namespace std;

const int MAXN=1e5+5;
int n,a[MAXN][3];

int dfs(int x,int d1,int d2,int d3,int res){  //要搜的编号，搜之前部门1，2，3人数，搜之前最大值 
	if(x>n) return res;
	int lres=res;
	if(d1+1<=n/2){  //编号为x的人去部门1
		lres=max(lres,dfs(x+1,d1+1,d2,d3,res+a[x][0]));
	}   
	if(d2+1<=n/2){
		lres=max(lres,dfs(x+1,d1,d2+1,d3,res+a[x][1]));
	}
	if(d3+1<=n/2){
		lres=max(lres,dfs(x+1,d1,d2,d3+1,res+a[x][2]));
	}
	return lres;
}

void oper(){
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	cout<<dfs(1,0,0,0,0)<<"\n";
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--) oper();
	return 0;
}
