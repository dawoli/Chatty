// 感觉学的都废了....
// 咋做？
// 性质A是什么东西啊
// 性质B很奇怪，也不好做
// 怎么用map呢？devc++好像不让用?还是我用错了？ 
// HASH?有可能
// 哦对了！pair! 
// 试试 ,先暴力做做 
// 完啦，暴力废了
// string长度到底咋求啊喂！！！ 
#include <bits/stdc++.h>
using namespace std;

int main(){
	// freopen("replace.in", "r", stdin);
	// freopen("replace.out", "w", stdout);
	int n, q;
	pair<string, string> x[100010];
	cin>>n>>q;
	for (int i = 1;i<=n;++i){
		string a, b;
		cin>>a>>b;
		pair<string, string> c;
		c.first = a;
		c.second = b;
		x[i] = c;
	} 
	for (int i = 1;i <= q;++i){
		char s[100010]={};
		int s1, l = 1;
		s1 = getchar();
		while (s1 != '\n'){
			s[l] = s1;
			s1 = getchar();
			++l;
		}
		for (int x = 1; x< 100010;++x) s[x] = '~';
		for (int x = 1;x<=n;++i){
			for (int y = 1; y<=n;++y){
				for 
			}
		}
	}
	return 0;
}
 
