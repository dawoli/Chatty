#include<bits/stdc++.h>
using namespace std;
map<pair<char,char>,int> m;
char str[5];
char fir[]={"0DCHS"};
char sec[]={"0A23456789TJQK"};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		m[make_pair(str[0],str[1])]=1;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(!m.count(make_pair(fir[i],sec[j])))
				ans++;
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
