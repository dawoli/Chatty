#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	int n,m;
	cin >> n >> m;
	string str;
	cin >> str;
	int c[n];
	for(int i=0;i<n;i++){
		cin >> c[i];
	}
	int answer=1;
	for(int i=2;i<=n;i++){
		answer=(answer*i)%998244353;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
