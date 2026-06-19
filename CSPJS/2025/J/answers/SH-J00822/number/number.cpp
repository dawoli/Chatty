#include <bits/stdc++.h>
using namespace std;
char s[1000001];
char b[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=0,i;
	for(i=1;i<=1000001;i++)
		s[i]='Q';
	long long int ans=0;
	cin>>s;
	i=0;
	while(s[i]!='Q')
	{
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
		{
			b[j]=s[i];
			j++;
		}
		i++;
	}
	j--;
	sort(b,b+j+1);
	int z;
	for(int i=0;i<j/2;i++)
	{
		z=b[i];
		b[i]=b[j-i];
		b[j-i]=z;
	}
	cout<<b;
	return 0;
}
