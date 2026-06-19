#include<bits/stdc++.h>
using namespace std;
int n , x , b[114514] , tot;
priority_queue< int , vector<int> , greater<int> > q;
queue<int> que;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for ( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&x);
        if ( b[x] == 0 ) q.push(x);
        b[x]++;
    }
    if ( b[1] + b[2] == n ){
        printf("%d",b[2]);
    	fclose(stdin);
    	fclose(stdout);
        return 0;
    }
    que.push(q.top());
    q.pop();
    while ( !q.empty() ){
        if ( b[que.front()] > b[q.top()] ){
            b[que.front()] -= b[q.top()];
            tot += b[q.top()];
            que.push(q.top());
            q.pop();
        }
        else{
            tot += b[que.front()];
            que.push(q.top());
            que.pop();
            if ( que.empty() || que.front() >= q.top() ) q.pop();
        }
    }
    printf("%d",n-tot);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
