#include<bits/stdc++.h> 
using namespace std;
struct num{int l=0,x[15000];}m;
int t,n,a[10]={6,2,5,5,4,5,6,3,7,6};
bool fd;
void dfs(int u,int v){
	if(7*(m.l-u)<v)return;
	if(u==m.l){
		for(int i=m.l-1;i>=0;i--)
			cout<<m.x[i];
		cout<<endl;fd=1;
	}
	if(v<2||fd)return;
	for(int i=(!u);i<10&&!fd;i++){
		if(a[i]>v)continue;
		m.x[m.l-u-1]=i;
		dfs(u+1,v-a[i]);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;m.l=n/7+1;
		if(n<2){
			cout<<-1<<endl;continue;
		}
		if(n%7==1){cout<<10;n-=8;}
		if((n+7)%7==0){
			for(int i=0;i<n/7;i++)cout<<8;
			cout<<endl;continue;
		}
		fd=0;dfs(0,n);
		if(!fd)cout<<-1<<endl;
	}
	return 0;
}
