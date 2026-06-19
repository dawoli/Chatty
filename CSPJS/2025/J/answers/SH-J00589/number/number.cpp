#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,a,b,c,k;
    scanf("%d",&n);
    if(n<10)
      printf("%d",n);
    else{
    	if(n<100)
    	{
    		b=n%10;
    		k=n-b;
    		a=k/10;
    		if(a>=b)
    		  c=a*10+b;
			else
			  c=b*10+a;
			printf("%d",c);
		}
		else
		  printf("%d",n);
	}
	return 0;
}
