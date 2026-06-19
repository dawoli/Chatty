#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
struct stu{
	int s1;
	int s2;
	int s3;
}s[N];
//struct ch{
//	int sum;
//	int t1;
//	int t2;
//	int t3;
//}dp[N][3];
int max3(int a, int b, int c){
	return max(a, max(b, c));
}
bool cmp(stu a, stu b){
	return max3(a.s1, a.s2, a.s3) > max3(b.s1, b.s2, b.s3);
}
void solve(){
	int n;
	cin >> n;
	int res = 0;
	int tong[4] = {};
	for(int i=1; i<=n; i++){
		cin >> s[i].s1 >> s[i].s2 >> s[i].s3;
	}
	sort(s+1, s+n+1, cmp);
	for(int i=1; i<=n; i++){
		int mx = max3(s[i].s1, s[i].s2, s[i].s3);
		if(mx == s[i].s1){
			if(tong[1] < n / 2){
				res += mx;
				tong[1]++;
//				cout << 1 << " ";
			}
			else if(s[i].s2 >= s[i].s3){
				res += s[i].s2;
				tong[2]++;
//				cout << 2 << " ";
			}
			else{
				res += s[i].s3;
				tong[3]++;
//				cout << 3 << " ";
			}
		}
		else if(mx == s[i].s2){
			if(tong[2] < n / 2){
				res += mx;
				tong[2]++;
//				cout << 2 << " ";
			}
			else if(s[i].s1 >= s[i].s3){
				res += s[i].s1;
				tong[1]++;
//				cout << 1 << " ";
			}
			else{
				res += s[i].s3;
				tong[3]++;
//				cout << 3 << " ";
			}
		}
		else{
			if(tong[3] < n / 2){
				res += mx;
				tong[3]++;
//				cout << 3 << " ";
			}
			else if(s[i].s1 >= s[i].s2){
				res += s[i].s1;
				tong[1]++;
//				cout << 1 << " ";
			}
			else{
				res += s[i].s2;
				tong[2]++;
//				cout << 2 << " ";
			}
		}
	}
	cout << res << endl;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	//freopen("club.in", "w", stdin);
	int t;
	cin >> t;
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
