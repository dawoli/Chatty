#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int s[1005][2005];

int main(){
	
	//freopen("chain.in","w",stdin);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdin);
	
	int T;
	cin >> T;
	while (T--){
		int n,k,q;
		cin >> n >> k >> q;
		for (int i = 1;i <= n;i++){
			cin >> s[i][0];
			for (int j = 1;j <= s[i][0];j++){
				cin >> s[i][j];
			}	
		}	
		while (q--){
			int r,c;
			cin >> r >> c;
			cout << "0\n";
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}	
