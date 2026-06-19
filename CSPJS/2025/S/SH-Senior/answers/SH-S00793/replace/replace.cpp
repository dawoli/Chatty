#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,q;
string x,y;
string tx[N],ty[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	
	for(int i = 1;i <= n;i++){
		cin >> tx[i] >> ty[i];
	} 
	int cnt = 0;
	for(int i = 1;i <= q;i++){
		cnt = 0;
		cin >> x >> y;
		for(int j = 0;j < x.length();j++){
			for(int k = 0;k < j;k++){
				if(x[i]!=y[i]) break;
			}
			for(int o = 1;o <= n;o++){
				if(j+tx[o].length() > x.length()) continue;
				bool flag = 1;
				for(int k = j;k < j+tx[o].length();k++){
					if(tx[i][k-j] != x[k]){
						flag = 0;
						break;
					}
					if(tx[i][k-j] != y[k]){
						flag = 0;
						break;
					}
				}
				if(!flag) continue;
				
				for(int k = j+tx[o].length();k < x.length();k++){
					if(x[k] != y[k]){
						flag = 0;
						continue;
					}
				}
				
				if(flag) cnt++;
			}
		}
		cout << cnt << endl;
	}
	
	
	return 0;
}
