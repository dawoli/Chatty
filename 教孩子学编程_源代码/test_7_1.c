#include <stdio.h>
#include <stdlib.h>
int main(){
    int i=1, ans=0;
//    for(i=1; i<=99; i+=2)
//        ans += i;
/*     while(i<=99){
		ans += i;
        i += 2;
    } */
    do{
		ans += i;
        i += 2;
    }while(i<=99);
    printf("%d\n",ans);
    system("pause");
    return 0;
}
