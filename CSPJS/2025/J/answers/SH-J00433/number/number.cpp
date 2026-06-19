#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int num[1000005];
bool cmp(int a,int b)
{
	return a > b; 
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int number = 0;
	for(int i = 0 ; i < s.length() ; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			num[number] = s[i] - '0';
			number++; 
		}
	}
	sort(num,num+1+number,cmp);
	for(int i = 0 ; i < number ; i++) cout << num[i]; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
