#include <stdio.h>
#include <stdlib.h>



int gd(int x, int y)
{
	if(x<y){
		int t;
		t = x; x = y; y = t;
    }
    if(x%y == 0) return y;
    return gd(y,x%y);
}

int main()
{
	int N = 36, M = 240;
    printf("%d\n", gd(N,M));
	system("pause");
	return 0;
}
