#include <bits/stdc++.h>
using namespace std;
int n;


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> n;
    while (n > 0){
        int a;
        cin >> a;
        int maxp = a/2;
        int alist[a][3];
        int amax[a];
        int amin[a];
        for(int i = 0;i<=a-1;i++)
        {

            cin >> alist[i][0] >> alist[i][1] >> alist[i][2];
            amax[i] = max(max(alist[i][0],alist[i][1]),alist[i][2]);
            amin[i] = min(min(alist[i][0],alist[i][1]),alist[i][2]);
        }
    }
    return 0;
}
