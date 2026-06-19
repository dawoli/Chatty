#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s,a[200],t,ans1,ans2;
void dfs(int dep,int x,int y){//x:ÁÐ£¬y:ÐÐ 
	if(dep==t){
		ans1=x,ans2=y;
		return ;
	}
	if(x%2==1&&y!=m){
		dfs(dep+1,x,y+1);
	}
	else if(x%2==1&&y==m){
		dfs(dep+1,x+1,y);
	}
	else if(x%2==0&&y!=1){
		dfs(dep+1,x,y-1);
	}
	else{
		dfs(dep+1,x+1,y);
	}
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			t=i;
		}
	}
	//cout<<t<<" ";
	dfs(1,1,1);
	cout<<ans1<<" "<<ans2;
	return 0;
}
