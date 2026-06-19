#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string A;
	bool s[100086];
	int c[100086];
	cin>>A;
	for(int i=0;i<n;i++){
		s[i]=A[i]-'0';
		cin>>c[i];
	}
	long long ans=1;
	int p=998*244*353;
	for(int i=0;i<m;i++){
		ans=ans%p;
		ans=ans*(m-i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
