#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b;
    printf("0:剪刀  1:石头  2:布\n");
    printf("A出：");    scanf("%d",&a);
    printf("B出：");    scanf("%d",&b);
    if(a==b) printf("相同");
    else {
		switch(a) {
			case 0: switch(b) {
						case 1: printf("B胜\n"); break;
                        case 2: printf("A胜\n"); break;
                    }; break;
			case 1: switch(b) {
						case 0: printf("A胜\n"); break;
                        case 2: printf("B胜\n"); break;
                    }; break;
			case 2: switch(b) {
						case 0: printf("B胜\n"); break;
                        case 1: printf("A胜\n"); break;
                    }; break;
        }
    }
	system("pause");
	return 0;
}
