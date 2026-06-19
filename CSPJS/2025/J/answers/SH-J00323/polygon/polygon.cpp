#include<bits/stdc++.h>
using namespace std;
int a[5001],n,choose[5001];
long long sum=0;
bool cmp(int x,int y){
	return x>y;
}
bool check(int end){
	int sum=0;
	for(int i=2;i<=end;i++){
		sum+=choose[i];
		if(sum>choose[1]) return 1;
	}
	return 0;
}
void dfs(int step,int ch){
	if(step>n){
		if(check(ch-1)){
			sum++;
		}
		return ;
	}
	choose[ch]=a[step];
	dfs(step+1,ch+1);
	choose[ch]=0;
	dfs(step+1,ch);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag==1){
		long long s=1;
		for(int i=1;i<=n;i++){
			s*=2;
			s%=998244353;
		}
		s--; 
		s-=(long long)n;
		s-=(long long)n*(long long)(n-1)/2;
		s+=998244353;
		s%=998244353;
		cout<<s;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,1);
	cout<<sum%998244353;
	
	return 0;
}
