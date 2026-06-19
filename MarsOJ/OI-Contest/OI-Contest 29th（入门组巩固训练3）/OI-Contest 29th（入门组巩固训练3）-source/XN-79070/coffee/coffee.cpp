#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m;
string a[10][10];
int cnt[10];
signed main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof cnt);
		int sum=0,ans=0;
		for(int i=1;i<=5;i++){
			for(int j=1;j<=8;j++){
				cin>>a[i][j];
				cnt[i]+=(a[i][j]=="math");
				sum+=(a[i][j]=="math");
			}
		}
		cin>>n>>m;
		if(n<m){
			for(int i=m;i<=m+n-1;i++){
				ans+=cnt[i];
			}
			cout<<ans<<endl;
			continue;
		}
		int week=(n-m+1)/7;
		int e=n-week*7;
		ans+=week*sum;
		for(int i=m;i<m+e;i++){
			ans+=cnt[i%7];
		}
		cout<<ans<<endl;
	}
	return 0;
}
