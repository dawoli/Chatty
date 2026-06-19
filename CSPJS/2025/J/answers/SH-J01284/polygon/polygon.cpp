#include<bits/stdc++.h>
using namespace std;
int n,lst[5005]={0};
long long ans;
void choose(int num,int max,int sum,int i,int last){
	if(num>=3&&sum>2*max&&ans<998244353-1&&last)ans++;
	else if(num>=3&&sum>2*max&&ans==998244353-1&&last)ans=0;
	if(i==n)return ;
	choose(num,max,sum,i+1,0);
	if(lst[i+1]>max)choose(num+1,lst[i+1],sum+lst[i+1],i+1,1);
	else if(lst[i+1]<=max)choose(num+1,max,sum+lst[i+1],i+1,1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>lst[i];
	choose(0,0,0,0,0);
	cout<<ans;
	return 0;
}

