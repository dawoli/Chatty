#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,t;
	string s;
	int cnt=0,a;
	long long res=1;
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++){
		cin>>a;
		if (a==0){
			cnt++;
		}
	}
	if (n-a<m){
		cout<<"0"<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++){
		res=(res*i)%998244353;
	}
	cout<<res;
	return 0;
}
