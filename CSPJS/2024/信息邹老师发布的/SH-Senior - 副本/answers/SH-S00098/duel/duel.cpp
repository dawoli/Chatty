#include<bits/stdc++.h>
using namespace std;
int r[100005],n,ans;
bool vis[100005];
int bs(int x){
	int l=x+1;
	int rr=n;
	int mid;
	while(l<=rr){
		mid=(l+rr)/2;
		if(r[mid]>r[x])rr=mid-1;
		else l=mid+1;
	}
	return mid;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
		int pos=bs(i);
		if(r[pos]>r[i]&&vis[pos]==0){
			ans--;
		}
		else{
			while(r[pos]<=r[i]||vis[pos]){
				pos++;
				if(pos>n){
					ans++;
					break;
				}
			}
			ans--;
		}
		vis[pos]=1;
	}
	cout<<ans;
	return 0;
}
