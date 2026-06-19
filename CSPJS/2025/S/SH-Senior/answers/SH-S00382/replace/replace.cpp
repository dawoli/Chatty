#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	int x[1005];
	string a[1005];
	string b[1005];
	if(q==1){
		cout << 0 << endl;
		return 0;
	}
	for(int i=1; i<=n; ++i){
		cin >> a[i] >> b[i];
	}
	for(int i=1; i<=q; ++i){
		string a, b;
		cin >> a >> b;
		for(int i=1; i<=min(a.size(), b.size()); ++i){
			if(a[i]!=b[i]){
				x[i]==1;
			}
		}
		int tmp=0;
		int cnt=0;
		int tmpst=0;
		for(int i=1; i<=min(a.size(), b.size()); ++i){
			if(x[i]==1){
				if(tmp=i-1){
					tmp=i;
				}
				else{
					tmpst=i;
					cnt++;
				}
			}
		}
		if(cnt>1){
			cout << 0 << endl;
			continue;
		}
	}
	return 0;
}
