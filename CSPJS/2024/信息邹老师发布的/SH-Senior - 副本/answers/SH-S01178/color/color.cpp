#include<bits/stdc++.h>
using namespace std;
const int N=2003,M=100005;
long long T,n,a[N],mem[M];
long long dfs(int pos,int lastr,int lastb,long long status){
	if(pos>n)
		return 0;
	if(mem[status]!=-1)
		return mem[status];
	long long ans=0; 
	if(lastb!=0 and a[lastb]==a[pos]){
		ans=max(ans,dfs(pos+1,lastr,pos,status+(1<<pos))+a[pos]);
	} 
	else{
		ans=max(ans,dfs(pos+1,lastr,pos,status+(1<<pos)));
	}
	if(lastr!=0 and a[lastr]==a[pos]){
		ans=max(ans,dfs(pos+1,pos,lastb,status)+a[pos]);
	}
	else{
		ans=max(ans,dfs(pos+1,pos,lastb,status));
	}
	return mem[status]=ans;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int ii=1;ii<=T;ii++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(mem,-1,sizeof(mem));
		cout<<dfs(1,0,0,0)<<endl;
	}
	return 0; 
}
