#include<bits/stdc++.h>
using namespace std;

bool rec[4][13];
char dx[] = {'D','C','H','S'},dy[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++) {
		char s[5];
		scanf("%s",s);
		for(int i = 0;i < 4;i++) {
			for(int j = 0;j < 13;j++) {
				if(s[0] == dx[i] && s[1] == dy[j]) {
					rec[i][j] = 1;
					break;
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 0;i < 4;i++) {
		for(int j = 0;j < 13;j++) {
			if(rec[i][j] == 0) {
				cnt ++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
