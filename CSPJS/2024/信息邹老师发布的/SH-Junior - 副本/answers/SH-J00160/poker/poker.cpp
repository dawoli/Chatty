#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[5][14];


int main(){
    
    //freopen("poker.in","w",stdin);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    
    int n;
    cin >> n;
    int res = 52;
    memset(a,0,sizeof(a));
    for (int i = 1;i <= n;i++){
        string s;
        cin >> s;
        int p,q;
        if (s[0] == 'D') p = 1;
        else if (s[0] == 'C') p = 2;
        else if (s[0] == 'S') p = 3;
        else if (s[0] == 'H') p = 4;
        if (s[1] == 'A') q = 1;
        else if (s[1] == 'T') q = 10;
        else if (s[1] == 'J') q = 11;
        else if (s[1] == 'Q') q = 12;
        else if (s[1] == 'K') q = 13;
        else q = s[1]-'0';
        if (a[p][q] == 0){
            res--;
        }
        a[p][q]++;
    }
    cout << res << "\n";
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
