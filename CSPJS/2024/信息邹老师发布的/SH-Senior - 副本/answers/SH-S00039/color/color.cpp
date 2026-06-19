#include <cstdio>
#include <iostream>
#define maxn 200010
using namespace std;
int T,n,num[maxn];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
    scanf("%d",&T);
    while(T--){
    	scanf("%d",&n);
    	for(int i=0;i<n;++i)scanf("%d",&num[i]);
    	int lr,lb,ans=-1,sum;
    	for(int k=0;k<1<<n;++k){
    		lr=-1,lb=-1;
    		sum=0;
    		for(int i=0;i<n;++i){
    			if(k&(1<<i)){
    				if(num[i]==lb)sum+=lb;
    				lb=num[i];
				}else{
					if(num[i]==lr)sum+=lr;
    				lr=num[i];
				}
			}ans=max(ans,sum);
		}printf("%d\n",ans);
	}
    
    fclose(stdin);
	fclose(stdout); 
    return 0;
}
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4

1
0
8

2
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
15
1 12 11 11 7 11 15 6 4 6 3 15 7 5 2
*/
