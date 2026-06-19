#include <bits/stdc++.h>
using namespace std;
char h[5] = {'D','C','H','S'};
char d[14] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
map <pair <char,char>,bool> mp;
long long n,ans;
string tmp;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (long long i = 1;i <= n;i++) cin >> tmp,mp[make_pair(tmp[0],tmp[1])] = true;
	for (long long i = 0;i < 4;i++){
		for (long long j = 0;j < 13;j++){
			if (!mp.count(make_pair(h[i],d[j])))
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
} 
