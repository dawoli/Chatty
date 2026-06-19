#include <bits/stdc++.h>
using namespace std;
int num(string s)
{
	int re=0;
	if(s[0]=='S'){
		re+=13;
	}
	if(s[0]=='D'){
		re+=26;
	}
	if(s[0]=='C'){
		re+=39;
	}
	if(s[1]=='A'){
		re+=0;
	}
	if(s[1]=='K'){
		re+=12;
	}
	if(s[1]=='Q'){
		re+=11;
	}
	if(s[1]=='J'){
		re+=10;
	}
	if(s[1]=='T'){
		re+=9;
	}
	if(s[1]>='2'&&s[1]<='9'){
		re+=int(s[1]-49);
	}
	return re;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int a[60];
	long long m;
	for(int i=0;i<60;i++)
	{
		a[i]=0;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		string s;
		cin>>s;
		a[num(s)]=1;
	}
	int res=0;
	for(int i=0;i<=51;i++){
		if(a[i]==0){
			res+=1;
		}
	}
	cout<<res;
	return 0;
}
