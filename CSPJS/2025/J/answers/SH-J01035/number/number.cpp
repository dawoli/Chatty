#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int b[1000010],k;

bool check(int x, int y)
{
	return(x>y);
 } 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for (int i=0;i<n;i++)
	{
		a[i]=s[i];
		if (a[i]>='0' && a[i]<='9')
		{
			k++;
			b[k]=a[i]-'0';
		}
	}
	sort(b+1,b+k+1,check);
	for (int i=1;i<=k;i++)
	{
		cout<<b[i];
	} 
	return 0;
}
