#include<iostream>
using namespace std;
const int MAXN=1005;
int n,m;
int a[MAXN];
int cnt=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%d",&a[1]);
    for(int i=2;i<=n*m;i++){
        scanf("%d",&a[i]);
        if(a[i]>a[1]){
            cnt++;
        }
    }
    int col=cnt/n;
    int row=0;
    if(col%2==0){
        row=cnt%n;
    }else{
        row=(n-1)-(cnt%n);
    }
    col++;
    row++;
    printf("%d %d",col,row);
    return 0;
}
