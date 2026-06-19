#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n;
int a[N];
int b[N],ans=-1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]++;
		ans=max(ans,a[x]);
	}
	cout<<ans;
	return 0;
} 
