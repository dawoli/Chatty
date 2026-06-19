#include <iostream>
#include <string>
using namespace std;
const int SMAXN = 1005, MAXN = 2e5+5;
const int MAXLEN = 1001;
int q,n,ans;
bool state = false;   // false:模拟;true:特殊性质
bool replaced(string& s1, string s2, string s3, string tgt) {
//	cout << "s1=" << s1 << ", s2=" << s2 << ", s3=" << s3
//	<< ", tgt=" << tgt << "\n";
	if(s1.size() < s2.size()) return false;
	size_t ppos = s1.find(s2);
//	cout << "finding " << s2 << " in " << s1 << " -> "
//	<< ppos << "\n";
	if(ppos == string::npos) return false;
	s1 = s1.replace(s1.begin()+ppos,
	s1.begin()+ppos+s2.size(), s3);
//	cout << "ppos=" << ppos << ", changed ts1=" << s1 << "\n";
	return s1 == tgt;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
//	if(n > SMAXN || q > SMAXN) state = true;
	if(!state) {
		string s1[n+1], s2[n+1], t1[q+1], t2[q+1];
		for(int i = 1;i <= n;i ++) {
			cin >> s1[i] >> s2[i];
		}
		for(int i = 1;i <= q;i ++) {
			cin >> t1[i] >> t2[i];
		}
		for(int i = 1;i <= q;i ++) {
			string ts1=t1[i];
			for(int j = 1;j <= n;j ++) {
				if(replaced(ts1, s1[j], s2[j], t2[i])) ans++;
//				cout << "ppos=" << ppos << ", changed ts1=" << ts1
//				<< ", t2[i]=" << t2[i] << ", ans=" << ans << "\n";
				ts1=t1[i];
			}
			cout << ans << '\n';
			ans = 0;
		}
	} else {
		register char c=getchar();
		register int cnt=0;
		int s11[n+1], s12[n+1], s21[n+1], s22[n+1],
		t11[n+1], t12[n+1], t21[n+1], t22[n+1];
		for(int i = 1;i <= n;i ++) {
			while(c != 'b') cnt++, c=getchar();
			s11[i]=cnt; cnt=0; c=getchar();
			while(c != ' ') cnt++, c=getchar();
			s12[i]=cnt; cnt=0; c=getchar();
			while(c != 'b') cnt++, c=getchar();
			s21[i]=cnt; cnt=0; c=getchar();
			while(c != ' ') cnt++, c=getchar();
			s22[i]=cnt; cnt=0; c=getchar();
		}
		for(int i = 1;i <= q;i ++) {
			while(c != 'b') cnt++, c=getchar();
			t11[i]=cnt; cnt=0; c=getchar();
			while(c != ' ') cnt++, c=getchar();
			t12[i]=cnt; cnt=0; c=getchar();
			while(c != 'b') cnt++, c=getchar();
			s21[i]=cnt; cnt=0; c=getchar();
			while(c != ' ') cnt++, c=getchar();
			s22[i]=cnt; cnt=0; c=getchar();
		}
		for(int i = 1;i <= q;i ++) {

		}
	}
	return 0;
}
