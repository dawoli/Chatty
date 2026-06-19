#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,i,cnt=0;
	string t;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		getline(cin,t);
		if(!m[t])
		{
			cnt++;
			m[t]=1;
		}
	}
	printf("%d",52-cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
