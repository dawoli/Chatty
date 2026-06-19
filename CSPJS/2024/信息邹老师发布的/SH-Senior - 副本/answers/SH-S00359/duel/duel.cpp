#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int ri[MAXN];
int ri1[MAXN];
int n;
bool flag[MAXN];
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> ri[i];
	sort(ri + 1, ri + n + 1);
	for (int i = 1; i <= n; ++i) ri1[i] = ri[i];
	ri[n + 1] = 100010;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int bigger = upper_bound(ri + i + 1, ri + n + 2, ri1[i]) - ri;
		//printf("i=%d,bigger=%d\n", i, bigger);
		if (bigger != n + 1) {
			ri[bigger] = 0;
			++ans;
		}
	}
//	cout << n << endl;
	cout << n - ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Å¶É³ÍþÂêÅ¶É³ÍþÂêÅ¶É³ÍþÂê
ÓÐÁËÄãÉú»îÃÀºÃÃ»·³ÄÕ
É³ÍþÂê´«Ææ ÆæÃîÖÁ¼«
×î°ôÓÎÏ· ÈËÈËÔÞÌ¾Äã
Èç¹û²»½ô
ÄÇ¾Í²»¶Ô
½ñÍíÃ»·¬ÇÑ·ñÔòÎÒ»áºð½Ð
ÎÞÂÛ°×Ìì
»¹ÊÇÒ¹Íí
É³ÍþÂêµÄÎ¶µÀÈÃÎÒÎè¶¯ôæôæ
ÔÚ¿áÊî»òº®¶¬
É³ÍþÂêµÄ°®ÈÃÇéÒâÅ¨
àÅàÅàÅàÅàÅàÅàÅ
É³ÍþÂêÓÎÏ·
Î¶ÀÙÆë³ª
É³ÍþÂê³Æ°Ô
»¶Çì²»³Ù
×î°ôÓÎÏ·
×î°ôÃÀÊ³ 
àÅàÅàÅàÅàÅàÅ 
É³ÍþÂêÅ¶É³ÍþÂêÅ¶É³ÍþÂê
ÃÀÎ¶ÈçÃÎ
ÏñÖÐ´ó½±µÄ ¿ñÏ² 
*/
