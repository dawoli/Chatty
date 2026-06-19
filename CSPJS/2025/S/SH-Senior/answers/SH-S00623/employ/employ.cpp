#include<bits/stdc++.h>
using namespace std;
int n,m,a[555],sum=0;
char c[555];
bool f[555];
void dfs(int num,int cnt){
	if(num>n){
		if(n-cnt>=m) sum++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i]=1;
		dfs(num+1,cnt+((cnt>=a[i])||!(c[i]-'0')));
		f[i]=0;
	}
}
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(i,0);
		f[1]=0;
	}
	cout<<sum<<endl;
	
	return 0;
}
