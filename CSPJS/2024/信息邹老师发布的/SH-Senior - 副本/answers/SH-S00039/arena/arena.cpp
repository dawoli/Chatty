#include <cstdio>
#include <iostream>
#define maxn 100010
using namespace std;
int n,m;
long long sum=0;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	
    scanf("%d%d",&n,&m);
    for(int i=1,u;i<=n;++i){
    	scanf("%d",&u);
    	sum+=u;
	}printf("%lld\n",sum);
    
    fclose(stdin);
	fclose(stdout); 
    return 0;
}
/*

*/
