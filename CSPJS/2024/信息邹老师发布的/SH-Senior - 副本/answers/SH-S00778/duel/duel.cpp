#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int lft=0;
	for(int i=1,j=2;j<=n;j++){
		if(a[i]<a[j]){
			lft++;
			i++;
		}
		//cout<<lft<<endl;
	}
	cout<<n-lft;
	return 0;
} 
