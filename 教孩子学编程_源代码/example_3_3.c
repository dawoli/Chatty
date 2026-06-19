#include <stdio.h>
int main()
{
    int A=18,B=10;
    int C;
    C=A;
    A=B;
    B=C;
    printf("A=%d,B=%d",A,B);
    system("pause");
    return 0;
}
