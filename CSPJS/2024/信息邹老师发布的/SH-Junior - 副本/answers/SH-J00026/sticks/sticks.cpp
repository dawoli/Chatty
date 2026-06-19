#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}
int main(){
    pair<int,int> num[10] = {{6,0},{2,1},{5,2},{5,3},{4,4},{5,5},{6,6},{3,7},{7,8},{6,9}};
    sort(num,num + 10,cmp);
    for(int i = 0;i < 10;i ++) cout  << num[i].first << " " << num[i].second << endl;
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        if(n == 1){
        	cout << -1 << endl;
        	continue;
		}
        int digit = 0,ans[1001] = {},lans = 0,start;
        while(n){
            for(int i = 0;i < 10;i ++){
            	if(digit == 0 && num[i].second == 0) continue;
            	while(n >= num[i].first){
                    ans[lans ++] = num[i].second;
                    n -= num[i].first;            		
				}
            }
            digit ++;
        }
		sort(ans,ans + lans);
        for(int i = 0;i < lans;i ++) cout << ans[i];
        cout << endl;
    }
    return 0;
}
