#include <iostream>
#include <algorithm>
using namespace std;

int num[1000005], cur;
bool cmp(int x, int y){
	return x > y;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if ('0' <= s[i] && s[i] <= '9'){
			num[++cur] = s[i] - '0';
		}
	sort(num+1, num+cur+1, cmp);
	for (int i = 1; i <= cur; i++)
		cout << num[i];
	return 0;
}
