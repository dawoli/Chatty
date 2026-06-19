#include <stdio.h>
#include <stdlib.h>
int isPrime(int num){
	int i;
    if(num<2) return 0;
    if(num<4) return 1;
    for(i=2; i*i<=num; ++i)
		if(num%i==0) return 0;
    return 1;
}
void twinPrime(int num)
{
	int i;
    for(i=5; i<=num; ++i)
		if(isPrime(i-2) && isPrime(i))
            printf("%d %d\n",i-2,i);
}
int main(){
	int N;
    scanf("%d",&N);
    twinPrime(N);
	system("pause");
	return 0;
}
