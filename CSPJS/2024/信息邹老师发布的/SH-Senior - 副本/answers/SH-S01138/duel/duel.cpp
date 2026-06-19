#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
bool vis[N];
int n;
int fid(int aim){
	int l=1,r=n;
	int ret=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<aim){
			if(!vis[mid]){
				ret=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}else{
			r=mid-1;
		}
	}
	return ret;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=n;
	for(int i=n;i>=1;i--){
		int now=fid(a[i]);
		if(now!=-1){
			vis[now]=1;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}

