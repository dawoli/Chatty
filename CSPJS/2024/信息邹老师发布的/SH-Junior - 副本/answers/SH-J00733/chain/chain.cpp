#include <bits/stdc++.h>
using namespace std;

int n,k,q;
int r;
string c;
int num[1010];
string s[1010][2010];

namespace first_point{
    int MAIN(){
        for(int i = 1;i <= n;i++){
            int lent = 0;
            for(int j = 1;j <= num[j];j++){
                lent+=s[j].length();
                if(lent > k) break;
                if(s[j] == c){
                    printf("1\n");
                    return 0;
                }
            }
        }

        printf("0\n");
        return 0;
    }
}

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++){
            scanf("%d",&num[i]);
            for(int j = 1;j <= num[i];j++){
                cin >> s[i][j];
            }
        }
        for(int i = 1;i <= q;i++){
            cin >> r >> c;
            if(r == 1) first_point::MAIN();
        }
    }
    return 0;
}