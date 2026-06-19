#include<bits/stdc++.h>
using namesdpace std;
int t,n,ans;
struct sts{
	int a,b,c;
}arr[100005];
bool cmp(sts x,sts y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<=n;i++) cin>>arr[i].a>>arr[i].b>>arr[i].c;
		sort(arr,arr+n,cmp);
		for(int i=0;i<n/2;i++) ans+=arr[i].a;
		cout<<ans<<endl;
		ans=0;
	}
	return 6&1;
} 
