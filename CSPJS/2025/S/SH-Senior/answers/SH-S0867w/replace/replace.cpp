#include<bits/stdc++.h>
using namespace std;
#define forRange(i1,_a,_b) for(i1 = _a; i1 < _b; i1 ++)

const long long MAXN = 2e5 + 10ll;
string s[2];
long long cth[MAXN],bef[MAXN],aft[MAXN];
long long n,q,addr,goal,gbef,gaft,cnt;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i,j,k,l;
	cin >> n >> q;
	forRange(i, 0, n){
		cin >> s[0] >> s[1];
		addr = 0ll;
		cth[i] = 0ll;
		bef[i] = 0ll;
		aft[i] = s[0].length() - 1;
		while(s[1].at(cth[i]) == 'a'){
			cth[i] ++;
			aft[i] --;
		} 
		while(s[0].at(addr++) == 'a'){
			cth[i] --;
			bef[i] ++;
		}
	} 
	for(; q; q--){
		cin >> s[0] >> s[1];
		cnt = 0ll;
		addr = 0ll;
		goal = 0ll;
		gbef = 0ll;
		gaft = s[0].length() - 1;
		while(s[1].at(goal) == 'a'){
			goal ++;
			gaft --;
		} 
		while(s[0].at(addr++) == 'a'){
			goal --;
			gbef ++;
		}
		forRange(i, 0, n){
			if(cth[i] == goal && bef[i] <= gbef && aft[i] <= gaft) cnt++;
		}
		cout << cnt << "\n";
	}
	
	
//	fclose(stdin);
//	checkanswers();
	
	return 0;
} 




