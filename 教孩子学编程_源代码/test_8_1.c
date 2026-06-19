#include <stdio.h>
#include <stdlib.h>
void invert(int number){
	while(number)    {
		printf("%d", number % 10);
        number /= 10;
    }
}
int main(){
	int x = 6790;
    invert(x);
	system("pause");
	return 0;
}
