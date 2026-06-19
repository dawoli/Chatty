#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out", "w", stdout);
	
	int n,m;
	long long cum=1;
	cin >> n >> m;
	m=n;
	string s;
	getline(cin,s);
	for(int i=1;i<=m;i++){
		int a;
		cin >> a;
		if(a==0)n--;
	}
	for(int i=1;i<=n;i++){
		cum*=i;
		cum%=998244353;
	}	
	cout << cum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
