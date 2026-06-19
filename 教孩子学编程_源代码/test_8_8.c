#include <stdio.h>
#include <stdlib.h>
#define maxN 100
int is0Or1(int r,int c,int v[maxN][maxN])
{
	int i, j;
    for(i=1; i<=r; ++i)
		for(j=1; j<=c; ++j)
			if(v[i][j]!=0 && v[i][j]!=1) return 0;
    return 1;
}
int main()
{
	int n, m, i, j, list[maxN][maxN];
    printf("输入矩阵的行数和列数（<100）:\n");
    scanf("%d %d",&n,&m);
    printf("输入%d个数（0~9）:\n",n*m);
    for(i=1; i<=n; ++i)
		for(j=1; j<=m; ++j)
			scanf("%d",&list[i][j]);
	if(is0Or1(n,m,list)==1)
        printf("yes\n");
    else
		printf("no\n");
	for(i=1; i<=n; ++i){
		for(j=1; j<=m; ++j)
			printf("%d ",list[i][j]);
        printf("\n");
    }
    system("pause");
	return 0;
}
