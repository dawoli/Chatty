#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;

int numbers[1500005];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string in;
	cin>>in;
	int cnt=0;
	for(int i=0;i<in.length();i++)
	{
		if(in[i]>='0'&&in[i]<='9')
		{
			numbers[cnt]=int(in[i])-48;
			cnt++;
		}
	}
	sort(numbers,numbers+cnt,greater<int>());
	for(int i=0;i<cnt;i++) cout<<numbers[i];
	return 0;
}
