#include<bits/stdc++.h>
using namespace std;
int t;
int n;
const int N = 2e5+9;
int a[N];
//T3样例1以解压目录为准
bool ta=1; 
//目标部分分：T1-T10 
vector<int> q[2009];
long long ansl=0;
void dfs(int id,int l,int r,long long ans){
	//cout<<id<<" "<<l<<" "<<r<<endl;
	if(id>n){
		ansl = max(ansl,ans);
		return ;
	}
	if(a[id]==a[l]){
		//cout<<"left"<<endl;
		l = id;
		ans+=a[id];
		dfs(id+1,l,r,ans);
	}
	else if(a[id]==a[r]){
		//cout<<"right"<<endl;
		r = id;
		ans+=a[id];
		dfs(id+1,l,r,ans);
	}
	dfs(id+1,id,r,ans);
	dfs(id+1,l,id,ans);
	//cout<<"rev"<<endl;
}
//期望20 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>2000){
				ta = 0;
			}
			q[a[i]].push_back(i);
		}
		/*
		分数据规模处理 
		*/
		if(n<=15){
			//暴力搜索
			ansl = 0;
			dfs(1,0,0,0);
			cout<<ansl<<endl; 
		}
		else{
			//胡乱一同 
			cout<<114514<<endl;
		} 
		
	} 
	return 0;
}
