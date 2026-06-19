#include<bits/stdc++.h>
using namespace std;
long long a[8];
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		for(int i=1;i<=5;i++){
			for(int j=1;j<=8;j++){
				string s;
				cin>>s;
				if(s=="math") a[i]++;
			}
		}
		int n,m;
		cin>>n>>m;
		long long ans=0;
		for(int i=m;i<=7;i++){
			ans+=a[i];
			n--;
		}
		long long sum=0;
		for(int i=1;i<=5;i++){
			sum+=a[i];
		}
		ans+=sum*(n/7);
		n%=7;
		for(int i=1;i<=n;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
