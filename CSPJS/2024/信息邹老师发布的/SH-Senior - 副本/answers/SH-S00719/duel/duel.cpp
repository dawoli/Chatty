#include<bits/stdc++.h>
using namespace std;
int r[100009];
int sum[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>r[i];
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		if(r[i]!=r[i-1])
			len++;
		sum[len]++;
	}
	int ans=n;
	for(int i=1;i<len;i++){
		sum[i]+=sum[i-1];
		ans-=min(sum[i],sum[i+1]);
		sum[i]-=min(sum[i],sum[i+1]);
	}
	cout<<ans;
	return 0;
} 
