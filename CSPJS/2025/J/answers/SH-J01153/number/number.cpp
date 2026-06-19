#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
普及- 
输出只有0-9 共10种字符 
*/

string s;
int n;//s.length();
const int MaxN = 1e6;
int a[16]={0};//a[i]表示 数字i有几个 

bool comp(int x, int y)
{
	return x>y;
}


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int n= 0;
	for(int i = 0; i < s.length(); i++)//1e6
	{
		if(s[i] >= 'a' and s[i] <= 'z')//isnot number
		{
			continue;
		}
//		cout << "read:"<< s[i] << endl;
//		n++;
		int num = s[i]-'0';
		a[num]++;
//		a[n] = s[i]-'0';
	}
//	cout << "\nNOW n="<<n<<endl;
//	sort(a,a+n,comp);
	for(int i = 9; i >= 0; i--)//9
	{
		for(int j = 1; j <= a[i]; j++)//
		{
			if(a[i]-j>12)
			{
				printf("%d%d%d%d%d%d",i,i,i,i,i,i);
				printf("%d%d%d%d%d%d",i,i,i,i,i,i);
				j+=12;
			}
			if(a[i]-j>5)
			{
				printf("%d%d",i,i);
				printf("%d%d",i,i);
				printf("%d",i);
				j+=5;
			}
			if(a[i]-j>2)
			{
				printf("%d%d",i,i);
				j+=2;
			}
			printf("%d",i);
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/* OLD OLD   老的题目 
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

普及- 


string s;
int n;//s.length();
const int MaxN = 1e6;
int a[MaxN];

bool comp(int x, int y)
{
	return x>y;
}


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int n= 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] >= 'a' and s[i] <= 'z')//isnot number
		{
			continue;
		}
//		cout << "read:"<< s[i] << endl;
		n++;
		a[n] = s[i]-'0';
	}
//	cout << "\nNOW n="<<n<<endl;
	sort(a,a+n,comp);
	for(int i = 0; i < n; i++)
	{
		printf("%d",a[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
