#include <bits/stdc++.h> 
using namespace std;
int a[5050],b[5050];
long long sum=0,ans=0;
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n==3) {
		sum+=a[1]+a[2]+a[3];
		if (sum>2*max({a[1],a[2],a[3]})){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0; 
}
