#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int mod=998244353;
bool used[5005]={false};
long long ans[5005];
int l[5005];
int Ans;
int n;
void solve(int last,int times,int cnt,int maxn){
	if(times==0){
		if(cnt>2*maxn)
			Ans=(Ans+1)%mod;
		return;
	}
	for(int i=last+1;i<=n-times+1;i++){
		if(!used[i]){
			used[i]=true;
			solve(i,times-1,cnt+l[i],max(maxn,l[i]));
			used[i]=false;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool S=true;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		if(l[i]!=1)S=false;
	}
	//maxa[i]=1
	if(S){
		ans[n]=1;
		long long sum=0;
		for(int i=n-1;i>=3;i--){
			ans[i]=ans[i+1]*(i+1)%mod;
			sum=(sum+ans[i])%mod;
		}
		cout<<sum;
		return 0;
	}
	if(n==3){
		if(l[1]+l[2]+l[3]>2*max(l[1],max(l[2],l[3])))cout<<"1";
		else cout<<"0";
		return 0;
	}
	for(int i=3;i<=n;i++){
		solve(0,i,0,0);
	}
	cout<<Ans;
	return 0;  
}
