#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct member{
	int c1, c2, c3, cha;
}num[N];
int T, n, club[4], ans = 0;
int ff(int a, int b, int c){
	int x = max(max(a, b), c);
	if(a == x) return 1;
	if(b == x) return 2;
	if(c == x) return 3;
}
int tt(int a, int b, int c){
	int x = min(min(a, b), c);
	if(a == x) return 1;
	if(b == x) return 2;
	if(c == x) return 3;
}
int ss(int a, int b, int c){
	if(1 != ff(a, b, c) && 1 != tt(a, b, c)) return 1;
	if(2 != ff(a, b, c) && 2 != tt(a, b, c)) return 2;
	if(3 != ff(a, b, c) && 3 != tt(a, b, c)) return 3;
}
bool cmp(member x, member y){
	return x.cha > y.cha;
}
int main(){
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout); 
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> num[i].c1 >> num[i].c2 >> num[i].c3;
			int mxx = max(max(num[i].c1, num[i].c2), num[i].c3);
			int mnn = min(min(num[i].c1, num[i].c2), num[i].c3);
			num[i].cha = mxx - mnn;
		}	
		sort(num+1, num+1+n, cmp);
		for(int i=1; i<=n; i++){
			int a = num[i].c1, b = num[i].c2, c = num[i].c3;
			int f = ff(a, b, c);
			int s = ss(a, b, c);
			int t = tt(a, b, c);
			if(club[f] < n/2){
				club[f]++;
				ans += max(max(a, b), c);
			}else if(club[s] < n/2){
				club[s]++;
				if(s == 1) ans += a;
				if(s == 2) ans += b;
				if(s == 3) ans += c;
			}else{
				club[t]++;
				ans += min(min(a, b), c);
			}
		}
		cout << ans << '\n';
		ans = 0;
		memset(club, 0, sizeof(club));
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
