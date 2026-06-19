#include <bits/stdc++.h>
using namespace std;
int n,cnt,t;
int c[100010];
int a[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++c[a[i]];
	}
	for(int i=1;i<=100000;++i)
		c[i]+=c[i-1];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		if(i-c[a[i]-1]+c[a[i]]>n||t==n)
			++cnt;
		else
			t=i-c[a[i]-1]+c[a[i]];
	cout<<cnt;
	return 0;
}
