#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],tmp;
bool cmp(const int b,const int c)
{
	return b>c;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	//É¸³ıËùÓĞ×ÖÄ¸ 
	for(int i=0,j=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			//cout<<1;
			a[j]=int(s[i]-'0');
			j++;
		}
		tmp=j;
	}
	sort(a,a+tmp,cmp);
	for(int i=0;i<tmp;i++)
	{
		cout<<a[i];
	}
	return 0;
}

