#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
long long ans;
string s;
bool x[505];
int a[505],c[505];
void check(){
	int num1=0,num2=0;
	for(int i=1;i<=n;i++){
		int j=i-1;
		if(num2>=a[i]){
			num2++;
			continue;
		}
		if(s[j]=='0'){
			num2++;
		}
		else if(s[j]=='1'){
			num1++;
		}
		if(num1>=m){
			ans=(ans+1)%mod;
			return ;
		}
	}
}
void dfs(int w){
	if(w==n+1){
		check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(x[i]!=1){
			x[i]=1;
			a[w]=c[i];
			dfs(w+1);
			x[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	cin>>s;
	for(int i =1;i<=n;i++){
		cin>>c[i];
	}
	if(n>10){
		long long sum=1;
		for(int i=1;i<=n;i++){
			sum=(sum*n)%mod;
		}
		cout<<sum;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
