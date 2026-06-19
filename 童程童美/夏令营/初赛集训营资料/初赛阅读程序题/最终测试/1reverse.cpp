#include <iostream>
using namespace std;
int main()
{
	string s; cin>>s;
	if(s[0]=='-'){ cout << "-"; s=s.substr(1); }
	bool zero=true;
	for(int i=s.length()-1;i>=0;i--)
	{
		if(zero&&s[i]=='0') continue;
		zero=false;
		cout << s[i];
	}
	if(zero) cout << 0 << endl;
	return 0;
}

