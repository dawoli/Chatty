#include<bits/stdc++.h>
using namespace std;
int n,a[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
