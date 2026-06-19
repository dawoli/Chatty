#include <iostream>
using namespace std;
#define MAX 60
struct p{
    char h[2];
};
p a[MAX];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i].h[0]>>a[i].h[1];
    }
    int ans=52-n;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i].h[0]==a[j].h[0] && a[i].h[1]==a[j].h[1]) {
                ans++;
                a[j].h[0]='0';
                a[j].h[1]='0';
            }
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}