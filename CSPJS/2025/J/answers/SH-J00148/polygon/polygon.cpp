#include <bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=998244353;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int maxn=INT_MIN;
	long long sum=0;
	if (n==3){
		for (int i=1;i<=n;i++){
			cin>>a[i];
			if (a[i]>maxn)maxn=a[i];
			sum+=a[i];
		}
		if (sum>maxn*2){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
