#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=100005;
int a[MAXN];
string l;
int k;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>l;
    k=0;
    for(int i=0;i<l.size();i++){
        char c;
        c=l[i];
        if(c>='0'&&c<='9'){
            a[k]=c-'0';
            k++;
        }

    }
    sort(a,a+k);
    for(int i=k-1;i>=0;i--)
        cout<<a[i];
    return 0;
}
