#include<bits/stdc++.h>
using namespace std;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int q=m;
	char a[505];
	cin>>a;
	for(int i=1;i<=q;i++){
		int b;
		cin>>b;
		
		if(b==0) m--;
		
	}
	cout<<m<<endl;

	if(m<n) cout<<0;
	else{
		for(int i=n;i<=m;i++){
			ans*=i;
			ans%=998244353;
		}
		for(int i=1;i<=q-m;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
