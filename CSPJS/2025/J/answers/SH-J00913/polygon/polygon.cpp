#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
bool vis[5005]; 
long long cnt;
bool teshu=0;
map<long long,long long>mp;
long long jiecheng(int h){
	if(mp[h]!=0)return mp[h];
	unsigned long long cnttt=1;
	for(int j=h;j>0;j--)cnttt=cnttt*j%998244353;
	mp[h]=cnttt%998244353;
	return cnttt%998244353;
}
void dfs(int start,int cntt,int maxlong){
	if(maxlong*2<cntt){
		cnt++;
		cnt=cnt%998244353;
	}
	if(start>=n)return ;
	for(int e=start+1;e<=n;e++){
		if(vis[e]==0){
			vis[e]=1;
			if(a[e]>maxlong){
				dfs(e,cntt+a[e],a[e]);
			}
			else{
				dfs(e,cntt+a[e],maxlong);
			} 
			vis[e]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)teshu=1;
	}
	if(teshu==0){
		for(int i=3;i<=n;i++){
			cnt=cnt+(jiecheng(n)/(jiecheng(n-i)*jiecheng(i))%998244353)%998244353;
		}
	}
	else dfs(0,0,0);
	cout<<cnt%998244353;
	return 0;
} 
