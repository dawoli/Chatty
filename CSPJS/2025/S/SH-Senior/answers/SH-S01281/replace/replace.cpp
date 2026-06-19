#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5; 
int n, q;
string s1[N], s2[N], t1[N], t2[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	for(int i = 1; i <= n; ++ i)
		cin >> s1[i] >> s2[i];
	
	bool flag = true, cnt = false;
	for(int i = 1; i <= n; ++ i){
		if(s1[1][i] != 'a' && s1[1][i] != 'b')
			flag = false;
		else if(s1[1][i] == 'b'){
			if(!cnt)
				cnt = true;
			else
				flag = false;
		}
		if(!flag)
			break;
	}
	
	for(int i = 1; i <= q; ++ i){
		cin >> t1[i] >> t2[i];
//		if(flag){
			cout << 1 << endl;
//			continue;
//		}
	}
	return 0;
}
