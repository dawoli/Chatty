#include <bits/stdc++.h>
using namespace std;

int num[200009];
int h[1000009];

int find_pair(int v , int l , int r){
	for(int i = l ; i <= r ; i ++){
		if(num[i] == v) return i;
	} 
	return r + 1;
}

long long solve(int pos , int end){
	if(end - pos <= 1) return 0;
	int ans = 0;
	if(h[num[pos]] == 1) solve(pos + 1 , end);
	else{
	    int mid = find_pair(num[pos] , pos + 1 , end);
	    if(mid == end + 1){
	    	return solve(pos + 1 , end);
		}
		else{
			if(solve(pos + 1 , mid) == 0) return num[pos];
			else return solve(pos + 1 , mid) + solve(mid + 1 , end);
		}
	}
}

int main(){
    freopen("color.in" , "r" , stdin);
	freopen("color.out" , "w" , stdout);
    int T;
    cin >> T;
    for(int e = 1 ; e <= T ; e ++){
    	memset(h , 0 , sizeof(h));
    	int n;
    	cin >> n;
    	for(int i = 1 ; i <= n ; i ++){
    		cin >> num[i];
    		h[num[i]] ++;
		}
    	cout << solve(1 , n) << endl;
	}
    

	return 0;
}

