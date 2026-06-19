#include <bits/stdc++.h>
using namespace std;

int t;
int main(){
    freopen("coffee.in", "r", stdin);
    freopen("coffee.out", "w", stdout);
    cin >> t;
    while(t--){
        int c[7];
        long long n, m, z = 0;
        for(int i = 0;i<5;i++){
            int mc = 0;
            for(int j = 0;j<8;j++){
                string tmp;
                cin >> tmp;
                if(tmp == "math"){
                    mc++;
                }
            }
            c[i] = mc;
            //cout << mc << endl;
            z += mc;
        }
        //cout << z << endl;
        c[5] = 0;
        c[6] = 0;
        cin >> n >> m;

        int ans = n/7*z;

        n = n%7;

        //cout << ans << " " << n << endl;
        while(n){
            n--;
            ans += c[m-1];
            m++;
			if (m==8) m=1; 
        }
        cout << ans << endl;
    }
}



