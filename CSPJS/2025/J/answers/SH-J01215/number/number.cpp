#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int k=0;
	cin>>s;
	int n=s.size();
	for(int i=0;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
