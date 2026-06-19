#include<bits/stdc++.h>
using namespace std;
string s,ans,an;
bool find(char num)
{
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]==num)
		{
			ans.erase(i);
			return 1;
		}
	}
	return 0;
}
bool finds(char num)
{
	for(int i=0;i<an.size();i++)
	{
		if(an[i]==num)
		{
			return 1;
		}
	}
	return 0;
}
void sort()
{
	while(1)
	{
		if(find('9')) an+='9';
		else break;
	}
	while(1)
	{
		if(find('8')) an+='8';
		else break;
	}while(1)
	{
		if(find('7')) an+='7';
		else break;
	}while(1)
	{
		if(find('6')) an+='6';
		else break;
	}while(1)
	{
		if(find('5')) an+='5';
		else break;
	}while(1)
	{
		if(find('4')) an+='4';
		else break;
	}while(1)
	{
		if(find('3')) an+='3';
		else break;
	}while(1)
	{
		if(find('2')) an+='2';
		else break;
	}while(1)
	{
		if(find('1')) an+='1';
		else break;
	}while(1)
	{
		if(find('0')) an+='0';
		else break;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>47 && s[i]<58) ans+=s[i];
	sort();
	if(finds('9')==0 && finds('8')==0 && finds('7')==0 && finds('6')==0 && finds('5')==0 && finds('4')==0 && finds('3')==0 && finds('2')==0 && finds('1')==0) an="0";
	cout<<an;
	return 0; 
}
//48~57
