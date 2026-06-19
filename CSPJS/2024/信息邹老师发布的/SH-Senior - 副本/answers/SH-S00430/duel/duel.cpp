#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,r[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	int i=1,j=upper_bound(r+1,r+n+1,r[i])-r,ans=n;
	while(i<j&&j<=n){
		if(r[j]>r[i]){
			i++,j++;
			ans--;
		}
		else j++;
	}
	cout<<ans<<endl;
	return 0;
}
