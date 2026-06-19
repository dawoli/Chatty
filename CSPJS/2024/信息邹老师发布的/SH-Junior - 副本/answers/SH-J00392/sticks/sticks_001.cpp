#include <iostream>
//#define int long long
using namespace std;



const int numsticks[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int n,t;
bool first;



int main() {

    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n;
        if(n<2){
            cout << -1 << endl;
            continue;
        }
        //int minn=9999999;
        for(int i=0;i<=2147483647;i++){
            int j = i;
            int cnt=0;
            while(j>0){
                cnt += numsticks[j%10];
                j /= 10;
                if(cnt > n)break;
            }
            if(cnt==n){
                cout << i << endl;
                break;
            }
        }

    }
    return 0;
}
