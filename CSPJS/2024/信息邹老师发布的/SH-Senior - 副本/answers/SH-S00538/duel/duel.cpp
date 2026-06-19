#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int cur=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			cur+=cnt;
			cnt=0;
		}
		cnt++;
		if(cur>0) cur--;
	}
	cur+=cnt;
	cout<<cur;
	return 0;
} 
