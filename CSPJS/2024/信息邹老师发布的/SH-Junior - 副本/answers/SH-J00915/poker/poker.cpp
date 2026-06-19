#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map <pair <char, char> , int> mp;
char cs1[] = {'D', 'C', 'H', 'S'}, cs2[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	while(n--) {
		cin >> s;
		mp[make_pair(s[0], s[1])] = 1;
	}
	n = 0;
	for(int i = 0; i <= 3; ++i) {
		for(int j = 0; j <= 12; ++j) {
			if(mp[make_pair(cs1[i], cs2[j])] == 0) {
				++n;
			}
		}
	}
	cout << n << endl;
	return 0;
}
// LIST OF ACCOUNTS TO ORZ
// ORZ JXY2011 
// ORZ LITTLEACBG
// ORZ LIAOYANXU
// ORZ COMPOSITE_FUNCTION
// ORZ TIANTIAN2021

// luogu account : 
// input this string into nutrimatic.org : nA{1,}ification
// choose one among all the result, for example a string s
// then change s into all capital letters
// change all the 'I' in s to '1', 'O' to '0'
// then the username is __ s __, where the s represents the string s after all the above operations
// for example : s = notification
// then the username is __N0T1F1CAT10N__ but it's wrong
// some guesses may be required

// SOLUTION :
// Obviously every J T1 should be easy.
// Just store every card in a map and enumerate all the cards to find out how many cards are missing.
