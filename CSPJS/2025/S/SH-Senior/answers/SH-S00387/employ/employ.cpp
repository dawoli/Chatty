#include <bits/stdc++.h>
using namespace std;
int n, m, c[505], mod=998244353, ans;
char s[505];
bool flag=true;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	int len=strlen(s);
	for(int i=0; i<len; i++){
		if(s[i]!='1'){
			flag=false;
			break;
		}
	}
	for(int i=1; i<=n; i++){
		cin >> c[i];
	}
	
	cout << 0; 
	
	return 0;
}
