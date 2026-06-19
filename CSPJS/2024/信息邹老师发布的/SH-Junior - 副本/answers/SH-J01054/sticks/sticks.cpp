#include <cstdio>
#include <algorithm>
using namespace std;
int T,n;
int s[8]={-1,-1,1,7,4,2,6,8},s2[7]={8,10,18,22,20,28,68};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	scanf("%d",&T);
    for (int Q=0;Q<T;Q++)
    {
    	scanf("%d",&n);
    	if (n<=7)
    	{
    		printf("%d\n",s[n]);
    		continue;
		}
    	printf("%d",s2[n%7]);
		for (int i=0;i<n/7-1;i++) printf("8"); 
		printf("\n"); 
	}
    return 0;
}
