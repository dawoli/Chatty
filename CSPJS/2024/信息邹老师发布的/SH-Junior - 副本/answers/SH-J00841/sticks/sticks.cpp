#include<bits/stdc++.h>
using namespace std;
#define int long long

int T,n;

int book[]={6,2,5,5,4,5,6,3,7,6};

bool big(string a,string b){
	if (b.length() > a.length())
		return 1;
	else
		return a < b;
}

string maker(int num){
	if(num == 1)
		return "-1";
	else if (num == 2)
		return "1";
	else if (num == 3)
		return "7";
	else if (num == 4)
		return "4";
	else if (num == 5)
		return "2";
	else if (num == 6)
		return "6";
	else if (num == 7)
		return "8";
	else if (num == 8)
		return "10";
	string ms="9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
	for (int i=1 ; i<=9 ; i++)
	{
		int numm=num-book[i];
		string s="";
		s+=(char)(48+i);
		while(numm>=8)
		{
			numm-=6;
			s+='0';
		}
		if (numm==2)
		{
			s+='1';
		}
		else if (numm == 3)
		{
			s+='7';
		}
		else if (numm == 4)
		{
			s+='4';
		}
		else if (numm == 5)
		{
			s+='2';
		}
		else if (numm == 6)
		{
			s+='0';
		}
		else if (numm == 7)
		{
			s+='8'; 
		}
		if (big(s,ms))
			ms=s;
	}
	return ms;
}

signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		cout<<maker(n)<<endl;
	}
	return 0;
} 
