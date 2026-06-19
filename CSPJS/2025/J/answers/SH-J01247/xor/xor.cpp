//整体思路：
//对于存储各二进制数各数位所有的1数量的前缀和数组，若目标当前数位为true即要求奇数，反之则要求偶数
//对于搜寻区间长度，枚举整个数组，当前数作为区间（队伍）队首，一直向后直至满足所需要求 
#include <bits/stdc++.h>
using namespace std;

int n,k,ck;

bool flag[50005];
int sa[105][105];

int num[50005];

bool tar[50005]; 
long long ans;

void binary(int a,int id) { //将对应数字转换二进制，并加入前缀和中。 
	int b[50005];
	int cur = 0;
	while (a != 1 &&a != 0) {
		cur++;
		b[cur] = a % 2;
		a /= 2;
	}
	cur++;
	b[cur] = a;
	/*for (int i = 1; i <= cur; i++) {
		cout << b[i] << " ";
	}
	cout << endl;*/
	for (int i = 1; i <= cur; i++) { //注意！只有数位为1才加入前缀和。 
		if (b[i] == 1) {
			sa[id][i] = sa[id-1][i] + 1;
		}
		else {
			sa[id][i] = sa[id-1][i];
		}
	}
}

bool check(int a, int b) { //从a到b的区间，是否满足tar中的数据要求？ 
	for (int i = 1; i <= ck; i++) {
		if ((sa[b][i] - sa[a-1][i]) % 2 == 1 && tar[i] == false) {
			return false;
		}
		if ((sa[b][i] - sa[a-1][i]) % 2 == 0 && tar[i] == true) {
			return false;
		}
	}  
	return true;
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int nk = k;
	if (nk == 1) {
		tar[1] = 1;
		ck = 1;
	}
	while (nk != 1 &&nk != 0) { //将目标k备份，随后生成其二进制数组，true为奇数，false为偶数 
		ck++;
		tar[ck] = nk % 2;
		nk /= 2;
	}
	/*for (int i = 1; i <= ck; i++) cout << tar[i] << " ";
	cout << endl;*/
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		binary(num[i],i);
	} 
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= ck; j++) {
			cout << sa[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	for (int i = 1; i <= n; i++) {
		int start = i;
		while (!check(start,i)) {
			i++;
			if (i > n) {
				break;
			}
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}
