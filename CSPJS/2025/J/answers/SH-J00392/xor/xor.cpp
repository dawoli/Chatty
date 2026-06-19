#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], p[500005];
bool check(int x, int st, int ed){
	int cnt=0, tmp=0;
	/*
	for(int i=1; i<=n; i++){
		tmp=tmp^a[i];
		if(tmp==k){
			cnt++;
			tmp=0;
		}
	}
	if(cnt>=x){
		return true;
	}
	else{
		return false;
	}
	*/
	for(int i=st; i<=ed; i++){
		for(int j=i; j<=ed; j++){
			tmp=p[j]^p[i-1];
			if(tmp==k){
				
				cnt++;
				if(j==n){
					return cnt>=x;
				}
				i=j;
				break;
			}
			if(j==n){
				return cnt>=x;
			}
		}
	}
	return cnt>=x;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		p[i]=p[i-1]^a[i];
	}
	
	int l=0, r=n, mid, ans=0;
	while(l<=r){
		mid=(l+r)/2;
		//cout << mid << " ";
		if(check(mid, 1, n)){
			
			l=mid+1;
			ans=mid;
		}
		else{
			
			r=mid-1;
		}
	}
	cout << ans;
	
	
	return 0;
}
