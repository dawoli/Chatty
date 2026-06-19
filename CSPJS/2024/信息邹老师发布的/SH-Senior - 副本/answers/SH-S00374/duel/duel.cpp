#include <bits/stdc++.h>
using namespace std;
int n,a[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int p=1;
	for(int i=1;i<=n;i++){
		if(a[i]>a[p])p++;
	}
	cout<<n-p+1;
	return 0;
}
