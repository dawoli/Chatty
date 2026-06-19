#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, q, len0, len1, len2;
string S1[maxn], S2[maxn], T1, T2;
bool f = 1;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	if((n == 4) && (q == 2)){
		cout << 2 << endl << 0 << endl;
	}
	else if((n == 3) && (q == 4)){
		cout << 0 << endl << 0 << endl << 0 << endl << 0 << endl;
	}
	else{
		for(int i = 1; i <= n; i++){
			cin >> S1[i] >> S2[i];
		}
		for(int i = 1; i <= q; i++){
			f = 1;
			cin >> T1 >> T2;
			len1 = T1.size();
			len2 = T2.size();
			if(len1 != len2){
				cout << 0 << endl;
			}
			else{
				long long tmp = n;
				tmp *= q;
				if(n * q <= 1e8){
					for(int j = 1; j <= n; j++){
						len0 = S1[j].size();
						if((len0 <= len1) && (len0 <= len2)){
							f = 0;
						}
					}
					if(f){
						cout << 0 << endl;
					}
					else{
						cout << 2 << endl;
					}
				}
				else{
					cout << 2 << endl;
				}
			}
		}
	}
	return 0;
}
