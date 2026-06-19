#include<bits/stdc++.h>
using namespace std; 
string s,ans;
int a[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int sum=0;
	cin >> s;
	for(int i = 0;i < s.size();i ++)
	{
		if(0<=s[i]-'0'<=9)
		{
			a[i+1]=s[i]-'0';
			sum++;
		}
	}
	sort(a+1,a+1+sum,cmp);
	for(int i = 1;i <= sum;i ++)
	{
		if(a[i]>9)continue;
		cout << a[i];
	}
	return 0;
 } 
