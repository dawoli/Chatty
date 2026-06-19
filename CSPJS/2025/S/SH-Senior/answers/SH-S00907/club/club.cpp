#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int a1[N],a2[N],a3[N];
bool b[N];
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		int n,ans=0,ans1=0,ans2=0,ans3=0;
		cin>>n;
		int one,two,three;
		int m=n/2;
		for(int i=1;i<=n;i++)
			cin>>a1[i]>>a2[i]>>a3[i];
		sort(a1+1,a1+n+1);
		for(int i=1;i<=m;i++)
			ans+=a1[n+1-i];
		cout<<ans<<"\n";
	}
	return 0;
} 
