#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n, q;
string s[N][3];
string t[N][3];

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++){
        cin >> s[i][1] >> s[i][2];
    }

    for(int i = 1; i <= q; i++){
        cin >> t[i][1] >> t[i][2];


        int sum = 0;
        for(int j = 1; j <= n; j++){
            string ss = t[i][1];
            int find1 = ss.find(s[j][1]);
            if(find1 > ss.length()){
                continue;
            }
            ss.replace(find1, s[j][1].length(), s[j][2]);
            if(ss == t[i][2]){
                sum++;
            }

        }
        printf("%d\n", sum);
    }




    return 0;
}
