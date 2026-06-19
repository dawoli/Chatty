#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[500002],a_mx=-1;
long long cnt[500002];
long long x;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		a_mx=max(a[i],a_mx);
	}
	for(int i=1;i<=a_mx+1;i++){
		x=x-cnt[i];
		if(x<0)
			x=0;
		x+=cnt[i];
	}
	cout<<x<<endl;
	return 0;
}
