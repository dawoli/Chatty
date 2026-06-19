/***********
 * T1: 拼数 number 
 * 估分: 100
 * author: CB_X2_Jun (Luogu UID 1219707)
 * 到此一游 
 ***********/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string z;
vector<char> n;
bool cmp(char a, char b)
{
	return a>b;
}
int main()
{
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> z;
	for(int i=0; i<z.length(); i++)
	{
		if(z[i]>='0'&&z[i]<='9')n.push_back(z[i]);
	}
	sort(n.begin(),n.end(),cmp);
	for(char i:n)cout << i;
	return 0;
}
