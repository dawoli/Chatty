#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
int a[11451];
int c[11451];
bool vis[11451];
void dfs(int x,int b,int last){
	//cout<<x<<endl;
	if(x==b){
		//cout<<114514;
		long long h=0;
		int maxv=-114514;
		for(int i=0;i<b;i++){
			//cout<<c[i]<<" ";
			h+=c[i];
			maxv=max(maxv,c[i]);
		}
		//cout<<endl;
		if(h>2*maxv){
			//cout<<114514<<endl;
			sum++;
			sum%=998244353;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0 && i>last){
			c[x]=a[i];
			vis[i]=1;
			dfs(x+1,b,i);
			vis[i]=0;
		}
		//
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(0,i,-1);
		for(int j=0;j<=i+3;j++){
			vis[j]=0;
			c[j]=0;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
