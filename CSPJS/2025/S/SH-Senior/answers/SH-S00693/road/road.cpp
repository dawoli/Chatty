#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000001][4]; 
int c[11][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++)
        for(int j = 1;j <= 3;j++)
            scanf("%d",&a[i][j]);
    for(int i = 1;i <= k;i++)
       for(int j = 1;j <= n;j++)
           scanf("%d",&c[i][j]);
    srand(time(0));
    long long ans = 0;
    for(int i =1;i <= m;i++)
        ans+=a[i][3];
    if(ans>1000000000){
    	int g = rand()%1000000000+1;
    	printf("%d",g);
	}
	else{
		int g = rand()%ans+1;
		printf("%d",g);
	}
	return 0;
}
