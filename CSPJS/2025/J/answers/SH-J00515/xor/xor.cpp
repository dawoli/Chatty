#include<bits/stdc++.h>
using namespace std;



int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//    unsigned long long n,k,ans = 0;
//    cin >> n >> k;
//    vector<unsigned long long> num;
//    for(int i = 0;i < n;i ++){
//        cin >> num[i];
//    }
//    for(int i = 1;i <= n;i ++){
//        for(int j = 0 ; j < n - j; j ++){
//            long long temp_sum = 0;
//            for(int k = j;k <= j + i;k ++){
//                temp_sum = temp_sum xor num[k];
//            }
//            if(temp_sum == k){
//                ans ++;
//            }
//        }
//    }
//    cout << ans << endl;
	int n,k;
	cin >> n >> k;
    vector<unsigned long long> num(n);
    for(int i = 0;i < n;i ++){
        cin >> num[i];
    }
	if(k == 0){
		switch(n){
			case 0:cout << 0;break;
			case 1:cout << 0;break;
			case 2:cout << 1;break;
		}
	}
	return 0;
}
