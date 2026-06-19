#include<bits/stdc++.h>
using namespace std;

int T , n , m , L , V , tot;
int x, v0[114514] , a[114514] , detectpoint[114514] , overspeedpoint[114514];
priority_queue< int , vector<int> , greater<int> > x0;
priority_queue<int> x1;


int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    for ( int tt = 0 ; tt < 1 ; tt++ ){
        scanf("%d",&n);
        for ( int i = 1 ; i <= n ; i++ ){
        	scanf("%d%d%d%d",&n,&m,&L,&V);
            scanf("%d%d%d",&x,&v0[i],&a[i]);
            if ( a[i] <= 0 && v0[i] > V ) x1.push(x);
            if ( a[i] > 0 && v0[i] > V ) x0.push(x);
        }
        for ( int i = 1 ; i <= m ; i++ ){
            scanf("%d",&detectpoint[i]);
        }
        if( a[1] == 0 ){
            while ( overspeedpoint[m] <= x1.top() ) x1.pop();
            printf("%d 1\n",x1.size());
        }
        if( a[1] >= 0 ){
        	while ( overspeedpoint[m] <= x0.top() ) x0.pop();
        	printf("%d 1\n",x0.size());
		}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
