#include <iostream>
using namespace std;
unsigned long long sum;
string d;
int c[1005];
int avail;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]!=0){
            avail++;
        }
    }
    unsigned long long ans=1;
    for(int i=1;i<=avail;i++){
        ans=((ans%998244353)*i%998244353)%998244353;
    }
    cout<<ans%998244353;
}
