#include<bits/stdc++.h>
using namespace std;
int n,k,ra[50009],an[50009];
int l,r,mid;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>ra[i];
	for(int i=0;i<n;i++){
		r=n;
		mid=(r-l)/2;
		if(mid=l+1) r--; 
		if(mid=r+1) l++;
		if(ra[r]-ra[l]+ra[mid]==n) r+=ra[r];
	}
	cout<<r-1;
	return 0;
}
