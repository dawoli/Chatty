#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define int unsigned long long

int arr[200010];
bool used[200010];

signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n, k1; cin >> n >> k1;
    for(int i = 1; i <= n ; i++){
        cin >> arr[i];
    }
    int rescnt = 0;
        // one-length area
        for(int i = 1; i <= n; i++){
            //cout << "TRYING I = " << i;
            if(arr[i] == k1){
                //cout << " RESCNT++ = " << rescnt + 1;
                rescnt++;
                used[i] = true;
            }
            //cout << endl;
        }

        // i is the length of area
        for(int i = 2; i <= n; i++){

            // j is beginning position of area
            for(int j = 1; j + i - 1 <= n; j++){
                int areaend = j + i - 1;
                int xorcnt = arr[j];
                bool failflag = false;
                if(used[j] == true){
                    continue;
                }
                //cout << "TRYING I = " << i << " J = " << j << " AREAEND = " <<areaend;
                for(int k = j + 1; k <= areaend; k++){
                    //cout << " K = " << k;
                    if(used[k] == true){
                        failflag = true;
                        break;
                    }
                    xorcnt = xorcnt ^ arr[k];
                }
                if(failflag == true) {
                    //cout << "FAILED \n";
                    continue;
                }
                else if(xorcnt == k1) {
                    //cout << " RESCNT++ = " << rescnt + 1;
                    rescnt++;
                    for(int k = j + 1; k <= areaend; k++){
                        used[k] = true;
                    }
                }
                //cout << " XORCNT = " <<xorcnt;
                //cout << endl;
            }
        }

        cout << rescnt << endl;


    fclose(stdin);
    fclose(stdout);
    return 0;
}