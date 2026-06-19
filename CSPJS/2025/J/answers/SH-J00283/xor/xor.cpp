#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],s[N];
int fi(int l,int r,int k){
	if(l>r)return 666666;
	if(a[l]==k)return l;
	int ans=666666;
	for(int i=l+1;i<=r;i++){
		if((s[i]^s[l-1])==k){
			ans=i;
			break;
		}
	}
	ans=min(ans,fi(l+1,min(ans,r),k));
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	int t=0;
	int ans=-1;
	while(t!=666666){
		t=fi(t+1,n,k);
		ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
