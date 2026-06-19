#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//Ten year's OI all in vain , no long long see forefathers
inline ll read(){
	char c = getchar(); ll t = 0 , f = 1;
	while(c < '0' || c > '9'){if (c == '-') {f = -1;} ; c = getchar();};
	while(c >= '0' && c <='9'){t = t * 10 + c - 48 , c = getchar();}
	return t * f;
}
int n , q;
const int N = 5e6 + 5 , M = 2e5 + 5;
string s1 , s2;
ull dh[M] , dh1[M] , a[100] = {426,92,830,698,169,426,234,615,584,467,370,826,136,301,178,747,683,566,683,657,55,645,22,153,745,265,24,615,667};
ull hashs(string s , int p){
	ull t = 0;
	for(int i = 0 ; i < s.length() ; i++){
		t = t * p + a[s[i] - 'a'];
	}
	return t;
}
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q;
	for(int i = 0 ; i < n ; i++){
		cin >> s1 >> s2;
		dh[i] = hashs(s1 , 131) - hashs(s2 , 131);
	}
	for(int i = 0 ; i < q ; i++){
		int cnt = 0;
		cin >> s1 >> s2;
		if(s1.length() != s2.length()){
			cout << "0\n";
			continue;
		}
		ull ndh = hashs(s1 , 131) - hashs(s2 , 131);
		for(int i = 0 ; i < n ; i++){
			ull mdh = dh[i] , mdh1 = dh1[i];
			for(int j = 0 ; j < s1.length() ; j++){
				if(mdh == ndh){
					cnt++;
					mdh = 0;
					break;
				}
				else mdh *= 131;
			}
		}
		cout << cnt << "\n";
	}
	
}
