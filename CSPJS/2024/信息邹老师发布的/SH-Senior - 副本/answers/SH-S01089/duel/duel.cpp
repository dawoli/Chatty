#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int n,a[N],tt;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+1+n);
	tt=1;
	for(int i=2; i<=n; i++){
		if(a[i]>a[tt]) tt++;
	}
	cout<<n-tt+1;
	return 0;
}
