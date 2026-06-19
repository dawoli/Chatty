#include<bits/stdc++.h>
using namespace std;
int n,t,a[200000];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int ke=0;ke<(1<<n);ke++){
			vector<int> rd,bl;
			int cnt=0;
			for(int i=0;i<n;i++){
				if(ke&(1<<i)) rd.push_back(i);
				else bl.push_back(i);
			}
			for(int i=1;i<rd.size();i++){
				if(a[rd[i]]==a[rd[i-1]]) cnt+=a[rd[i]];
			}
			for(int i=1;i<bl.size();i++){
				if(a[bl[i]]==a[bl[i-1]]) cnt+=a[bl[i]];
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return 0;
}
