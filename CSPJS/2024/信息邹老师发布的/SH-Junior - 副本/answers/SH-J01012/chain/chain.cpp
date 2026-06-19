#include <iostream>
using namespace std;
#define MAXN 100000
#define MAXK 200000
int f(){
    int n,k,q;
    cin>>n>>k>>q;
    int l[MAXN]
    for (int j=0; j<n; j++) {
        cin>>l[j];
        if(l[i]>k){
            return 0;
        }
        int s;
        for(int a=0; a<l[j]; a++){
            cin>>s;
        }
    }
    for (int i=0; i<q; i++) {
        int r,c;
        cin>>r>>c;
        if(c==1){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    for (int i=0; i<T; i++) {
        cout<<f();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}