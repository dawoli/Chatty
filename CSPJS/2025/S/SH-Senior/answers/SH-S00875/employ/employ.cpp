#include<bits/stdc++.h>
using namespace std;

int n,m;
string a;
int c[1000010];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	int ans=1;
	for(int i=1;i<=m;i++){
		ans=ans*i;
	}
	cout<<ans%998244353<<endl;
	return 0;
}
