#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],ans,l;
map<int,vector<int> >mp;
bool ch(int z,int x,int s){
	int l=1;
	int r=mp[z].size();
	while(l<=r){
		int mid=(l+r)/2-1;
		if(mp[z][mid]<x)	l=mid+2;
		if(mp[z][mid]>s)	r=mid;
		if(mp[z][mid]>=x&&mp[z][mid]<=s){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0].push_back(0);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
		mp[sum[i]].push_back(i);
	}
	l=0;
	for(int i=1;i<=n;++i){
		int z=sum[i]^k;
		if(mp[z].empty())	continue;
		if(ch(z,l,i-1)==0)	continue;
		ans++;
		l=i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
