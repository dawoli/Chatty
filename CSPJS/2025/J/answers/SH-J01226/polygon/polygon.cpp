#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,ans,maxa;
int a[5005];
int fo[5005];
int fn[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//input
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a,a+n);
	//caculate ans
	long long fneg=1;
	for(int cnt=0;cnt<n-1;cnt++){
		for(int i=0;i<=maxa;i++){
			fn[i]+=fo[i];fn[i]%=MOD;
			if(i-a[cnt]<0)fn[i]+=fneg;
			else fn[i]+=fo[i-a[cnt]];
			fn[i]%=MOD;
		}for(int i=0;i<=maxa;i++){
			fo[i]=fn[i];
			fn[i]=0;
		}
		fneg*=2;fneg%=MOD;
		ans+=fo[a[cnt+1]];ans%=MOD;
	}
	//output
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
