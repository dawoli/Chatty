#include<bits/stdc++.h>
using namespace std;
#define int long long
int week[10]={0};
signed main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		memset(week,0,sizeof week);
		for(int i=1; i<=5; i++){
			for(int j=1; j<=8; j++){
				string s;
				cin>>s;
				if(s=="math"){
					week[i]++;
				}
			}
		}
		for(int i=1; i<=7; i++) week[i]=week[i]*1ll+week[i-1];
		int n,m;
		cin>>n>>m;		
		n-=(8-m);
		cout<<week[7]*1ll*(n/7)+week[n%7]*1ll+1ll*(week[7]-week[m-1])<<"\n";
	}
	return 0;
} 
