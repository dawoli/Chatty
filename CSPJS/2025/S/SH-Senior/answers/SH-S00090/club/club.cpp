#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
bool if1=1,if2=1,if3=1;
int t,n;
long long a[100005][5];
void solveA(int have){
	priority_queue<int>q;
	for(int i=1;i<=n;i++){
		q.push({a[i][have]});
	}
	long long tot=0;
	for(int i=1;i<=n/2;i++){
		tot+=q.top();
		q.pop();
	}
	cout<<tot<<"\n";
}

int vis[100005];
long long res=0;
void dfs(int cur,int pos,long long sum){
	if(cur>n){
		res=max(res,sum);
		return ;
	}
	
	if(vis[1]+1<=n/2){
		vis[1]++;
		dfs(cur,1,sum+a[cur][1]);
		vis[1]--;
	}
	
	if(vis[2]+1<=n/2){
		vis[2]++;
		dfs(cur,2,sum+a[cur][2]);
		vis[2]--;
	}
	if(vis[3]+1<=n/2){
		vis[3]++;
		dfs(cur,3,sum+a[cur][3]);
		vis[3]--;
	}
	
}
void solveN(){
	res=0;
	memset(vis,0,sizeof vis);
	vis[1]++;
	dfs(1,1,a[1][1]);
	vis[1]--;
	vis[2]++;
	dfs(1,2,a[1][2]);
	vis[2]--;
	vis[3]++;
	dfs(1,3,a[1][3]);
	vis[3]--;
}
int main(){
	 freopen("club.in ","r",stdin);
	 freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		if1=1;if2=1;if3=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				
			}
			if(a[i][1])if1=0;
				if(a[i][2])if2=0;
				if(a[i][3])if3=0;
		}
		if((if1&&if2)||(if1&&if3)||(if2&&if3)){
//			cout<<"(1)";
			if(!if1)solveA(1);
			if(!if2)solveA(2);
			if(!if3)solveA(3);
		}else{
			solveN();
//			cout<<"(2)";
			cout<<res<<endl;
		}
	}
	 fclose(stdin);
	 fclose(stdout);
	return 0;
}

