#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int a[N],n,l,r,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	l=1,r=1;
	ans=n;
	while(r<=n){
		if (a[l]<a[r]){
			l++;
			ans--;
		}
		r++;
	}
	cout<<ans<<endl;
	return 0;
}
