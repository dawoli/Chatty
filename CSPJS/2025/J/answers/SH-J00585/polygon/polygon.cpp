#include<bits/stdc++.h>
using namespace std;
const int maxn=998244353; 	
int n,a[5500],ans,b[5500];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long sum=n;
	for(int i=n-2;i<n;i++) sum*=i;
	ans=sum/6;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1]+a[i];
		a[i]*=2;
	}
	for(int i=n;i>2;i--){
		for(int j=i-2;j>0;j--){
			if(b[i]-b[j-1]<=a[i]){
				ans-=j;
				break;
			}
		}
	}
	cout<<ans%maxn;
	return 0;
}
