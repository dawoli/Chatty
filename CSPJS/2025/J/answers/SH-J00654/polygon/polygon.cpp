#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005][5005],sum;
long long jiecheng(int a){
	long long i=1;
	while(a>0){
		i*=2;
		a--;
	}
	return i;
}
long long dfs(long long n,long long minn){
	//cout<<n<<" "<<minn<<endl;
	if(minn<=0) return jiecheng(n)%998244353;
	if(n<1) {
		return 0;
	}
	if(b[n][minn]){
		return b[n][minn];
	}
	b[n][minn]=dfs(n-1, minn-a[n])+dfs(n-1, minn);
	b[n][minn]%=998244353;
	return b[n][minn]%998244353;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long woqu=dfs(i-1,a[i]+1);
		sum+=woqu%998244353;
		sum%=998244353;
		//cout<<woqu<<endl;
	}
	cout<<sum%998244353;
	return 0;
}
