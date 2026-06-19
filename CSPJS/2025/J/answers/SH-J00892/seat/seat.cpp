#include<cstdio>
#include<algorithm>
using namespace std;

int a[110];

bool cmp(int x , int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    int n , m;
    scanf("%d%d" , &n , &m);
    for (int i = 1; i <= n * m; i++)
    {
        scanf("%d" , &a[i]);
    }
    int val = a[1];
    sort(a + 1 , a + n * m + 1 , cmp);
    int pos = 0;
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i] == val)
        {
            pos = i;
            break;
        }
    }
    int c = (pos - 1) / n + 1;
    //printf("c=(%d-1)/%d+1=%d\n" , pos , n , c);
    int r = (c & 1) ? ((pos - 1) % n + 1) : (n - (pos - 1) % n);
    //if (c & 1) printf("r=%d-(%d-1)mod%d=%d\n" , n , pos , n , r);
    //else printf("r=(%d-1)mod%d+1=%d\n" , pos , n , r);
    printf("%d %d\n" , c , r);
    return 0;
}
