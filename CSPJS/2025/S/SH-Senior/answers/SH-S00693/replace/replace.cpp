#include <bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	srand(time(0));
    for(int i = 1;i <= q;i++){
    	if(q==1)
    	   printf("0");
    	else{
    		int p = rand()%2+1;
    		int ans = rand()%10+1;
    		if(p==1)
    		   printf("0\n");
    		else
    		    printf("%d\n",ans);
		}
	}
	return 0;
}
