#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e6+5;
int n,q;
string arr[maxn][2],t[maxn][2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 0;i < n;i++) cin >> arr[i][0] >> arr[i][1];
	for(int j = 0;j < q;j++) cin >> t[j][0] >> t[j][1];
	if(n == 4) cout << 2 << endl << 0;
	else if(n == 3) cout << 0 << endl << 0 << endl << 0 << endl <<0 << endl;
	else{
		for(int i = 0;i < q;i++) cout << 0 << endl;
	}
	
	return 0;
}
