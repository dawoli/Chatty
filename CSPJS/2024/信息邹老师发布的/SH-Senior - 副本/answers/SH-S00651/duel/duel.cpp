#include <bits/stdc++.h>
using namespace std;
typedef long ll;
ll n,ans;
ll a[100009],b[100009];
bool gj[100009];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		gj[a[i]]=1;
		b[a[i]]++;
	}
	ans=n;
	sort(a+1,a+n+1);
	for(ll i=a[1];i<=a[n]-1;i++){
		if(b[i+1]==0){
			b[i+1]=b[i];
		}
		if(b[i]<=b[i+1]&&gj[i+1]==1){
			ans-=b[i];
			gj[i+1]=0;
		}
		else if(b[i]>b[i+1]&&gj[i+1]==1){
			ans-=b[i+1];
			b[i+1]+=(b[i]-b[i+1]);
		}
	}
	cout<<ans;
	return 0;
}
