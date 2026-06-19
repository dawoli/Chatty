#include <iostream>
#include <cstdio> 
using namespace std;
int box[100][100]; //字符 D 代表方片 （1），字符 C 代表草花（2），字符 H 代表红桃（3），字符 S 代表黑桃（4） 
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	
	for (int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		
		int op;
		char a = s[0];
		if (a == 'D') op = 1; 
		if (a == 'C') op = 2; 
		if (a == 'H') op = 3; 
		if (a == 'S') op = 4; 
        
        int op2;
        char b = s[1];
        
        if (b <= '9' && b >= '2') op2 = int(b - '0');
        else if (b == 'A') op2 = 1;
        else if (b == 'T') op2 = 10;
        else if (b == 'J') op2 = 11;
        else if (b == 'Q') op2 = 12;
        else if (b == 'K') op2 = 13;
        box[op][op2]++;
	}
	int cnt = 0;
	for (int i = 1;i <= 4;i++)
	{
	    for (int j = 1;j <= 13;j++)
	    {
		    if (box[i][j] == 0) cnt++;
		}
	}
	cout << cnt << endl;
	fclose(stdin);
	fclose(stdout);
    return 0;
} 
