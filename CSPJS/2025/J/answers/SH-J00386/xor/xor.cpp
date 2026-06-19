#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n,k,a[500005];
bool vis[500005];
bool if_ok(int left,int right){
	if (vis[left]) return 0;
	ll ans=a[left];
	for (int i=left+1;i<=right;i++){
		if (vis[i]) return 0;
		ans=ans^a[i];
	}
	if (ans!=k) return 0;
	return 1;
}
void vised(int left,int right){
	for (int i=left;i<=right;i++){
		vis[i]=1;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	ll cnt=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=(n-i+1);j++){
			if (if_ok(j,j+i-1)){
				cnt++;
				vised(j,j+i-1);
			}
		}
	}
	cout<<cnt;
	return 0;
}
