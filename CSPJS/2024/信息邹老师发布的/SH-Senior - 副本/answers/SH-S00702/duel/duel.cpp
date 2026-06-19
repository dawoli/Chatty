#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+10;
int n,r[Maxn],i,j=1,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+n+1); ans=n;
	for(i=2;i<=n;i++){
		if(r[i]>r[j]){
			ans--; j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
