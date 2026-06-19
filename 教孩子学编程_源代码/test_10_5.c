#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void swap(int *q1, int *q2){
	int *p;
    p = q1;  q1 = q2;  q2 = p;
}
int main(){
	int *p1, *p2;
    p1 = malloc(sizeof(int));
    p2 = malloc(sizeof(int));
    *p1 = 100;
    *p2 = 200;
    if(*p1 < *p2) swap(p1,p2);
    printf("%d %d\n",*p1,*p2);
	system("pause");
	return 0;
}
