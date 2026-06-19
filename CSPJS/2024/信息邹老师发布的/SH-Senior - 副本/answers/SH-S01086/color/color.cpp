#include<bits/stdc++.h>
using namespace std;
int ma,n;
int f[29];
int bfs(int des,int col,int las_red,int las_blu,int man){
	if(des==n+1){
		ma=max(ma,man);
		return 0;
	}
	if(col==0){
		bfs(des+1,0,des,las_blu,man+(f[des]==f[las_red])*f[des]);
		bfs(des+1,1,des,las_blu,man+(f[des]==f[las_red])*f[des]);
	}
	else{
		bfs(des+1,0,las_red,des,man+(f[des]==f[las_blu])*f[des]);
		bfs(des+1,1,las_red,des,man+(f[des]==f[las_blu])*f[des]);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<=28;i++) f[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>f[i];
		ma=0;
		bfs(1,0,0,0,0);
		bfs(1,1,0,0,0);
		cout<<ma<<endl;
	}
	return 0;
}
