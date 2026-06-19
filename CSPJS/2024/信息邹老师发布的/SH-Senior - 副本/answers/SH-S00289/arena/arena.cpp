#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],ans;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
}
