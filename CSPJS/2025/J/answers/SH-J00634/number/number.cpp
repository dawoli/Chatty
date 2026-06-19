#include<cstdio>
int n[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	int i=9;
	while((c=getchar())!=EOF)
		if('0'<=c&&c<='8')
			n[c-'0']++;
		else if(c=='9')
			printf("9");
	while(i--)
		while(n[i])
		{
			if(n[i]<10)
			{
				while(n[i]--)
					printf("%d",i);
				break;
			}
			n[i]-=10;
			printf("%d%d%d%d%d%d%d%d%d%d",i,i,i,i,i,i,i,i,i,i);
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
