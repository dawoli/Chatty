#include<iostream>
using namespace std;

int n, q;
bool sp = 1;
string a[210000][3], t[210000][3], s1, s2;
int al[210000][3] = {0}, ar[210000][3] = {0};
int tl[210000][3] = {0}, tr[210000][3] = {0};

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2];
		if(sp){
			int cnt1b = 0, cnt2b = 0;
			for(int j = 0; j < a[i][1].length(); j++){
				if(a[i][1][j] == 'b'){
					al[i][1] = j;
					ar[i][1] = a[i][1].length() - 1 - j;
					cnt1b++;
				}else if(a[i][1][j] != 'a'){
					sp = 0;
					break;
				}
				if(a[i][2][j] == 'b'){
					al[i][2] = j;
					ar[i][2] = a[i][2].length() - 1 - j;
					cnt2b++;
				}else if(a[i][2][j] != 'a'){
					sp = 0;
					break;
				}
			}
			sp = sp && (cnt1b == 1) && (cnt2b == 1);
		}
	}
	for(int i = 1; i <= q; i++){
		cin >> t[i][1] >> t[i][2];
		if(sp){
			int cnt1b = 0, cnt2b = 0;
			for(int j = 0; j < t[i][1].length(); j++){
				if(t[i][1][j] == 'b'){
					tl[i][1] = j;
					tr[i][1] = t[i][1].length() - 1 - j;
					cnt1b++;
				}else if(t[i][1][j] != 'a'){
					sp = 0;
					break;
				}
				if(t[i][2][j] == 'b'){
					tl[i][2] = j;
					tr[i][2] = t[i][2].length() - 1 - j;
					cnt2b++;
				}else if(t[i][2][j] != 'a'){
					sp = 0;
					break;
				}
			}
			sp = sp && (cnt1b == 1) && (cnt2b == 1);
		}
	}
	if(sp){
//		for(int i = 1; i <= n; i++){
//			cout << al[i][1] << ' ' << ar[i][1] << '&' << al[i][2] << ' ' << ar[i][2] << endl;
//		}
//		for(int i = 1; i <= q; i++){
//			cout << tl[i][1] << ' ' << tr[i][1] << '%' << tl[i][2] << ' ' << tr[i][2] << endl;
//		}
		for(int i = 1; i <= q; i++){
			int ans = 0;
			for(int j = 1; j <= n; j++){
				if(tl[i][1] - tl[i][2] != al[j][1] - al[j][2]){
					continue;
				}
				if(tl[i][1] < al[j][1] || tr[i][1] < ar[j][1]){
					continue;
				}
				ans++;
			}
			cout << ans << endl;
		}
		
	}else{
		
		for(int i = 1; i <= q; i++){
			s1 = t[i][1];
			s2 = t[i][2];
			int l = -1, r = -1, ans = 0;
			for(int j = 0; j <= s1.length(); j++){
				if(s1[j] != s2[j]){
					l = j;
					break;
				}
			}
			for(int j = s1.length() - 1; j >= 0 ; j--){
				if(s1[j] != s2[j]){
					r = j;
					break;
				}
			}
			
			for(int j = 1; j <= n; j++){
				for(int k = max(r + 1 - (signed int)a[j][1].length(), 0); k <= l && k + a[j][1].length() <= s1.length(); k++){
					if(s1.substr(k, a[j][1].length()) == a[j][1]){
						if(s2.substr(k, a[j][2].length()) == a[j][2]){
							//cout << '*' << i << ' ' << a[j][1] << endl;
							ans++;
							break;
						}
					}
				}
			}
			cout << ans << endl;
		}
		
	}
	
	return 0;
}
