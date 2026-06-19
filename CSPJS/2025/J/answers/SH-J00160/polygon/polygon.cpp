#include<bits/stdc++.h>
using namespace std;
#define int long long
int modans=998244353;
int a[200005];
int sum;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int maxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+n+1);
	if(sum>2*maxa&&n>=3){
		cout<<1<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}
