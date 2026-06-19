#include<bits/stdc++.h>
using namespace std;
const int mod =  998244353;
long long sum = 1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	int c[501];
	for(int i=1;i<=n;i++){
		cin>>c[i];
		sum = sum*n%mod;
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
}
