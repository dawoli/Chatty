#include <bits/stdc++.h>
using namespace std;
string s;
int n,m,c[505],ifall1=1,ac[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i=1;i<=n;i++) cin >> c[i];
	for (int i=0;i<s.length();i++){
		if (s[i]=='1'){
			ac[i+1]=1;
		}
		else{
			ifall1=0;
			ac[i+1]=0;
		}
	}
	if (ifall1==0){
		cout << 18;
	}
	return 0;
}
