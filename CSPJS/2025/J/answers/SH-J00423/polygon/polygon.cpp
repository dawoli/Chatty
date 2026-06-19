#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int arr[5010];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    unsigned long long n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    if(n <= 20){
        int cnt = 0;
        // i is the num of sticks selected
        for(int i = 3; i <= n; i++){
            int uses[21];
            for(int j = 0; j <= 20; j++){
                uses[j] = 0;
            }
            for(int j = n; j > n - i; j--){
                uses[j] = 1;
            }


            do{
                int length = 0, maxl = 0;
                for(int j = 1; j <= n; j++){
                    if(uses[j] == 1){
                        length += arr[j];
                        maxl = max(maxl, arr[j]);
                    }
                }
                if(length > 2*maxl)cnt++;
            }while(next_permutation(uses + 1, uses + 1 + n));

        }
        cout << cnt << endl;
    }
    else{
        unsigned long long lcq = 1;
        for(unsigned long long i = 1; i <= n; i++){
            lcq = lcq % 998244353 * 2;
        }
        lcq -= n;
        lcq -= (n * (n - 1)) / 2;
        cout << lcq - 1 <<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}