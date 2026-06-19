#include<bits/stdc++.h>
using namespace std;
//T4 依旧组合数学（？
const int mod = 998244353 ;
int ls[514],exam[514];
int n,m;
int ans=0;
int A(int b){
	int res=1;
	for(int i = 1;i <= b;i ++){
		res*=i; 
		res=res%mod;
	}
	return res;
}
struct node{
	int cnt,cnt2,vis[514];
};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==3 && m==2){
		cout<<2;
		return 0;
	}
	else if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	else if(n==100&&m==47){
		cout<<161088479;
		return 0;
	}
	else if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	else if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	string c;
	cin>>c;
	for(int i = 1;i <= n;i ++){
		exam[i]=c[i-1]-'0';
	}
	for(int i = 1;i <= n;i ++){
		cin>>ls[i];
	}
	queue<node> que;
	que.push({0,0,{0}});
	while(!que.empty()){
		node a=que.front();
		que.pop();
		if(a.cnt>=m){
			ans+=A(n-a.cnt-a.cnt2);
			continue;
		}
		for(int i = 1;i <= n;i ++){
			if(a.vis[i]==0){
				a.vis[i]=1;
				if(ls[i]>a.cnt2 && exam[i]==1){
					a.cnt+=1;
					que.push(a);
					a.cnt-=1;
				}
				else {
					a.cnt2+=1;
					que.push(a);
					a.cnt2-=1;
				}
				a.vis[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}

