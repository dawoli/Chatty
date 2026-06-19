#include<bits/stdc++.h>
#define MAXN 1000001
using namespace std;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	char s;
	char tmp;
	int lens=0;
	int numbe=1;
	char a[MAXN];
	memset(a,'0',sizeof(a));
	scanf("%s",s);
	lens = strlen(s);
	for(int i=1;i<=lens;i++)
	{
		if(s<='9'&& s>='1')
		{
			a[numbe] = s;
			numbe++;
		}

	}
	
	for(int i=1;i<=numbe;i++)
	{
		for(int j=i+1;j<=numbe){
			if('a[i]' < 'a[j]'){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	for(int i=1;i<=numbe;i++)
	{
		printf("%c",a[i]);
	}
	return 0;
}
