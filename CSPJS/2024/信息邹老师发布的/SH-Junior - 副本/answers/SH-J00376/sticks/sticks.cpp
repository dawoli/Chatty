#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;
#define int long long
int nums[] = {6,2,5,5,4,5,6,3,7,6};
vector<int> lst[101];

int deal(int n){
    if(n % 7 == 0){
        int ns = n / 7;
        string ans = "";
        while(ns--) ans+= "8";
        return stoi(ans);
    }
    if((n - 1) % 7 == 0 and n != 1){
        int ns = (n - 1) / 7;
        string ans = "10";
        ns--;
        while(ns--) ans+= "8";
        return stoi(ans);
    }
    return -2;
}



signed main(){
	freopen("sticks.out","w",stdout);
	freopen("sticks.in","r",stdin); 
	
	for(int i = 0; i <= 2000; i++){
       	int cnt = 0;
        string num = to_string(i);
        for(auto x : num){
           	cnt += nums[x - '0'];
        }
        lst[cnt].push_back(i);
   	}	
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        int t1 = deal(n);
        if(t1 != -2) {
            cout << t1 << endl;
        }else{
   			int minv = 2147483647;
   			auto vec = lst[n];
   			if(vec.size() == 0){
   				cout << -1 << endl;
   			}
   			else {
   				for(auto x: vec){
   				if(x < minv and minv != 0) minv = x;
   				}
				   cout << minv << endl;
   				
			}
			   
			
		}
    }
    return 0;
}
