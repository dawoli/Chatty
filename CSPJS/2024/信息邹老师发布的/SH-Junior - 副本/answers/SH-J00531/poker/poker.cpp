#include <bits/stdc++.h>
using namespace std;
int arr[10][20];
int huase(char c)
{
	if(c=='D') return 1;
	if(c=='C') return 2;
	if(c=='H') return 3;
	if(c=='S') return 4;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	int n;
	char c,num;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%c",&c);
		if(c!='D'&&c!='C'&&c!='H'&&c!='S')
		{
			i--;
			continue;
		}
		scanf("%c",&num);
		if(num>='2'&&num<='9')
			arr[huase(c)][num-'0']=1;
		if(num=='A') arr[huase(c)][1]=1;
		if(num=='T') arr[huase(c)][10]=1;
		if(num=='J') arr[huase(c)][11]=1;
		if(num=='Q') arr[huase(c)][12]=1;
		if(num=='K') arr[huase(c)][13]=1;
	}
	int cnt=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(!arr[i][j]) cnt++;
	printf("%d",cnt);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
