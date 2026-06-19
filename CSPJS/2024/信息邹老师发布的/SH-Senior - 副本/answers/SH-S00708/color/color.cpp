#include<bits/stdc++.h>
using namespace std;
char str[200005];
stack<char> col;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T,i,n,j;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		int ans=0;
		scanf("%d",&n);
		scanf("%s",str);
		for(j=0;j<n;j++)
		{
			col.push(str[i]);
		}
		while(!col.empty())
		{
			
		}
		printf("%d\n",ans)
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
