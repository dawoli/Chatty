#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,a[MAXN],r[MAXN],ans;
 
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r[a[i]]++;
	}
	for(int i=1;i<=MAXN;i++){
		ans=max(ans-r[i],0)+r[i];
	}
	cout<<ans;
	return 0;
}
