#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],last=1,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		if(a[i]>a[last]){
			ans--;
			last++;
		}
	cout<<ans<<endl;
	return 0;
}
