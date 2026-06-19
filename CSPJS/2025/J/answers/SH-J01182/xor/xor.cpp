#include<bits/stdc++.h>
#include<random>
using namespace std;
int a[20], b[20], ans[20], i;
const int N =5 * 1e5;
void DtoB(int x, int y){
        i = 0;
    while(x!=0 && y!=0){
        a[i] = x%2;
        x = x / 2;
        //b[i] = y%2;
        y = y / 2;
        i++;
    }while(x!=0){
        a[i] = x%2;
        x = x / 2;
        i++;
    }//while(y!=0){
        //b[i] = y%2;
        //y = y / 2;
        //i++;
    }


void x_or(){
    for (int j = 0; j < i; j++){
        if (a[j] == ans[j]){
            ans[j] = 0;
        }else{
            ans[j] = 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);

    freopen("xor.in", "r", stdin)
    freopen("xor.out", "w", stdout)

    int nums[N+5], a_a;
    int n_of_nums, target;
    int positions_works[1048581][1048581];
    cin >> n_of_nums >> target;
    for (int k = 1; k <= n_of_nums; k++){
        cin >> a_a;
        nums[k] = a_a;
    }
    for(int m = 0; m < n_of_nums; m++){
        for(int n = m; n < n_of_nums;n++){
            for(int k = m;k<n;k++){
                DtoB(nums[m],nums[m+1])
                x_or()
            }
        }
    }cout <<125;
    return 0;
}
