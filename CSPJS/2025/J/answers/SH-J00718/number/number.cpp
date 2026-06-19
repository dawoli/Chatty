#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
string t,s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.length();i++) if('0' <= s[i] && s[i] <= '9') t += s[i];
	sort(t.begin(),t.end(),greater<char>());
	cout << t << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
