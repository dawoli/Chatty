#include <bits/stdc++.h>
using namespace std;
int l[100];
int cnt;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string s="SAHACADAS2H2C2D2S3H3C3D3S4H4C4D4S5H5C5D5S6H6C6D6S7H7C7D7S8H8C8D8S9H9C9D9STHTCTDTSJHJCJDJSQHQCQDQSKHKCKDK";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string a;
		cin>>a;
		for(int j=0;j<=300;j+=2)
		{
			if(a[0]==s[j]&&a[1]==s[j+1]&&l[j]==0&&l[j+1]==0)
			{
				cnt++;
				l[j]=1;
				l[j+1]=1;
				break;
			}
		}
	}
	cout<<52-cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
