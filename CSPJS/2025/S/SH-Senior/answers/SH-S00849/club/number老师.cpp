#include<iostream>
#include<cstring>

using namespace std;
int cnt[10];
const int N = 1e6+10;
char str[N];
int main() {
	scanf("%s", str);
	int len = strlen(str);
	for(int i=0;i<len;i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			cnt[str[i] - '0']++;
		}
	}
	string ans = "";
	for(int i=9;i>=0;i--) {
		if (cnt[i] != 0) {
			for(int j=0;j< cnt[i];j++) {
				ans += i + '0';
			}
		}
	}
	cout<<ans;
	return 0;
}