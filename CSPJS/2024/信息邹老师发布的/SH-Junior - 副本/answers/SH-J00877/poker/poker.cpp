#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	vector<vector<bool>> v(5,vector<bool>(14,false));
	int num = 0;
	for(int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		int x,y;
		if(s[0] == 'D')
		{
			x = 1;
		}else if(s[0] == 'C'){
			x = 2;
		}else if(s[0] == 'H'){
			x = 3;
		}else{
			x = 4;
		}
		if(s[1] == 'A')
		{
			y = 1;
		}else if(s[1] == 'T'){
			y = 10;
		}else if(s[1] == 'J'){
			y = 11;
		}else if(s[1] == 'Q'){
			y = 12;
		}else if(s[1] == 'K'){
			y = 13;
		}else{
			y = s[1]-48;
		}
		if(v[x][y] == false)
		{
			num++;
			v[x][y] = true;
		}
	}
	cout << 52-num;
	return 0;
}

