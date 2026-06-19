#include<bits/stdc++.h>
using namespace std;
int n;
int a[5002];
int b[50000+1];
int maxx=0;
long long ans;
void dfs(int num,int sum,int maxn,int i,int j){
	if(num>=3){
		if(sum>maxn*2&&){
			
			b[sum]++;
			if(b[sum]<=maxx){
				cout<<sum<<' '<<maxn<<' '<<i<<' '<<j<<' '<<endl;
				ans++;
			}
		}
	}
	dfs(num+1,sum+a[i],a[i],i+1,j);
	dfs(num,sum,maxn,i+1,j);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool b=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i!=1])b=false;
	}
	if(b){
		for(int i=1;i<=n-2;i++)
		ans+=i;
		cout<<ans%998244353<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
		else cout<<0;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		int q=1;
		for(int j=i+1;j<=n;j++){
			if(a[j]!=a[i])break;
			else q++;
		}
		maxx=max(maxx,q);
	}
	for(int i=1;i<=n-2;i++)dfs(0,0,0,i,i);
	cout<<ans<<endl;
	return 0;
}
