#include "bits/stdc++.h"
using namespace std;
set <string> s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        string str;
        cin>>str;
        s.insert(str);
    }
    cout<<52-(s.size())<<"\n";



    return 0;
}
