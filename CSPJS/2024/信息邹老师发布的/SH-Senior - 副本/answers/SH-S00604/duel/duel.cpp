#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n,cnt,r[maxn];
bool vis1[maxn];//false表示r[i]未发动攻击，true表示发动过了
bool vis2[maxn];//false表示还活着，true表示已经死了 
int check(){
	for (int i = 1 ; i <= n ; i ++ )	for (int j = 1 ; j <= n ; j ++ )	if (r[i] > r[j] && vis1[i] == 0 && vis2[j] == 0) {
		vis2[j] = 1;
		vis1[j] = 1;
		vis1[i] = 1;
		cnt --;
		continue; 
	}
	return cnt;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i ++ )	cin >> r[i];
	cnt = n;
	cout << check();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
