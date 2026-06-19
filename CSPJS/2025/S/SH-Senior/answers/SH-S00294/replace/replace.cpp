#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
string s1[N], s2[N];

signed main(){
    ignore = freopen("replace1.in","r",stdin);
    ignore = freopen("replace.out","w",stdout);
    int m, n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=n;i++){
        string t1, t2;
        int ans = 0;
        cin>>t1>>t2;
        string t=t1;
        for(int j = 1;j<=m;j++){
            if(t1.find(s1[j])){
                cout <<"*";
                for(int k=1;k<=s1[j].size();k++){
                    t1[t1.find(s1[j])+k]=s2[j][k];
                }
                if(t1==t2)ans++;
            }
            t1=t;
        }
        cout << ans<<endl;
    }

    return 0;
}
//g++ replace.cpp -Wall -std=c++14 -O2 -o replace
///home/cyez/D/SH-S00294sunheqi/replace/replacez/D/SH-S00294sunheqi/replace/replacez/D/SH-S00294sunheqi/replace/replacez/D/SH-S00294sunheqi/replace/replacez/D/SH-S00294sunheqi/replace/replacez/D/SH-S00294sunheqi/replace/replace