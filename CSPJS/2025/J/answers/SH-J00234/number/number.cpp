#include <iostream>
#include <cstring>
using namespace std;
long long cnt[105];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++) if (s[i] >= '0' && s[i] <= '9') cnt[s[i] - '0']++;
	for (int i = 9;i >= 0;i--) while (cnt[i]) cout << i,cnt[i]--;
	return 0;
}
