#include <bits/stdc++.h>
using namespace std;
#define int long long
using PII = pair<int,int>;
//bool cmp(vector<int> a , vector<int> b){
//    return max({a[0],a[1],a[2]}) > max({b[0],b[1],b[2]});
//}
void solve(){
    int n;
    cin >> n;
    int limit = n / 2;
    vector<vector<PII>> mem(n,vector<PII>(3));
    vector<PII> st;
    for(int id = 0; id < n; id++){
    	auto &i = mem[id];
        cin >> i[0].first >> i[1].first >> i[2].first;
        i[0].second = 0 , i[1].second = 1 , i[2].second = 2;
        sort(i.begin(),i.end(),greater<PII>());
        PII x;
        x.first = i[0].first - i[1].first;
        x.second = id;
        st.push_back(x);
    }
    sort(st.begin(),st.end(),greater<PII>());
    vector<int> club(3);
    int ans = 0;
    for(auto x : st){
    	int id = x.second;
    	int a = mem[id][0].first , b = mem[id][1].first;
    	int ia = mem[id][0].second , ib = mem[id][1].second;
    	if(club[ia] == limit){
//    		cout << ib << " f\n";
    		ans += b;
    		club[ib]++;
		}else{
			ans += a;
			club[ia]++;
		}
	}
    
    
    {//zhushi
//    for(auto &i : mem){
//    	auto a = i[0] , b = i[1] , c = i[2];
//    	if(i[0] > i[1] && i[0] > i[2]){
//    		if(club[0].size() < limit){
//    			club[0].push_back(id);
//    			ans += i[0];
//			}else{
//				if(i[1] > i[2]){
//					club[1].push_back(id);
//					ans += i[1];
//				}else{
//					club[2].push_back(id);
//					ans += i[2];
//				}
//			}
//		}else if(i[1] >= i[0] && i[1] >= i[2]){
//			if(club[1].size() < limit){
//    			club[1].push_back(id);
//    			ans += i[1];
//			}else{
//				if(i[0] > i[2]){
//					club[0].push_back(id);
//					ans += i[0];
//				}else{
//					club[2].push_back(id);
//					ans += i[2];
//				}
//			}
//		}else{
//			if(club[2].size() < limit){
//    			club[2].push_back(id);
//    			ans += i[2];
//			}else{
//				if(i[0] > i[1]){
//					club[0].push_back(id);
//					ans += i[0];
//				}else{
//					club[1].push_back(id);
//					ans += i[1];
//				}
//			}
//		}
//		id++;
//    }
	}
    cout << ans << endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
}
/*
对于每一个人，要使得最终的总和最大，我一定希望取到它的最大值
显然可以按照最大值排序
如果有一个部门人数超过了n/2末尾去另外两个扔到其他部门
*/
