#include <bits/stdc++.h>
using namespace std;
int a[128];
int m;
int n;
int x=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            x++;
        }
    }
    if(x%n==0){
        if((x/n)%2!=0){
            cout<<x/n<<" "<<n;
        }else{
            cout<<x/n<<" "<<1;
        }
    }else{
        cout<<x/n+1<<" ";
        if((x/n+1)%2!=0){
            cout<<x%n;
        }else{
            cout<<n-(x%n)+1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
