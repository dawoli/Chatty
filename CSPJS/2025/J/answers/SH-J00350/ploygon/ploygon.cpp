#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
ll a[N]; 
int main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(n<3){
			cout<<0;
		}
		else{
			if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		return 0;
	}
	if(n==4){
		int cnt=0;
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cnt++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))) cnt++;
		if(a[1]+a[3]+a[4]>2*max(a[1],max(a[3],a[4]))) cnt++;
		if(a[2]+a[3]+a[4]>2*max(a[2],max(a[3],a[4]))) cnt++;
		if(a[1]+a[2]+a[3]+a[4]>=2*max(max(a[1],a[2]),max(a[3],a[4]))) cnt++;
		cout<<cnt;
		return 0;
	}
	if(n==5){
		int cnt=0;
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cnt++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))) cnt++;
		if(a[1]+a[2]+a[5]>2*max(a[1],max(a[2],a[5]))) cnt++;
		if(a[1]+a[3]+a[4]>2*max(a[1],max(a[3],a[4]))) cnt++;
		if(a[1]+a[3]+a[5]>2*max(a[1],max(a[3],a[5]))) cnt++;
		if(a[1]+a[4]+a[5]>2*max(a[1],max(a[4],a[5]))) cnt++;
		if(a[2]+a[3]+a[4]>2*max(a[2],max(a[3],a[4]))) cnt++;
		if(a[2]+a[3]+a[5]>2*max(a[2],max(a[3],a[5]))) cnt++;
		if(a[2]+a[4]+a[5]>2*max(a[2],max(a[4],a[5]))) cnt++;
		if(a[3]+a[4]+a[5]>2*max(a[3],max(a[4],a[5]))) cnt++;
		if(a[1]+a[2]+a[3]+a[4]>=2*max(max(a[1],a[2]),max(a[3],a[4]))) cnt++;
		if(a[1]+a[2]+a[3]+a[5]>=2*max(max(a[1],a[2]),max(a[3],a[5]))) cnt++;
		if(a[1]+a[2]+a[4]+a[5]>=2*max(max(a[1],a[2]),max(a[4],a[5]))) cnt++;
		if(a[1]+a[3]+a[4]+a[5]>=2*max(max(a[1],a[3]),max(a[4],a[5]))) cnt++;
		if(a[2]+a[3]+a[4]+a[5]>=2*max(max(a[2],a[3]),max(a[4],a[5]))) cnt++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>=2*max(a[5],max(max(a[1],a[2]),max(a[3],a[4])))) cnt++;
		cout<<cnt;
		return 0;
	}
	ll cnt=0;
	for(int l=2;l<n-1;l++){
		for(int i=1;i<=n;i++){
			ll s=0,maxs=0;
			for(int j=i;j<=i+l;j++){
				s+=a[j];
			//	cout<<a[j]<<" ";
				maxs=max(maxs,a[j]);
				if(s>maxs*2){
					cnt++;
				//	cout<<"&\n";
				}
			}
			//cout<<"*\n";
		}
	}
	cout<<cnt;
	return 0;
}
