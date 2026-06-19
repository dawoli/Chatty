#include<bits/stdc++.h>
using namespace std;
#define ll long long
//ten year's OI all in vain , no long long see forefathers
int n , cr[100005] , cd[100005] , r , cnt;
int main(){
	freopen("duel.in" , "r" , stdin);
	freopen("duel.out" , "w" , stdout);
	cin >> n , cnt = n;
	for(int i = 0 ; i < n ; i++){
		cin >> r;
		cr[r]++ , cd[r]++;
	}
	int i = 0 , j = 1;
	for(int k = 0 ; k < 100005 ; k++){
		while(cr[i] == 0) i++;
		while((cd[j] == 0 || j == i ) && j <= 100001) j++;
		if(j > 100000) break;
		if(cr[i] >= cd[j]) cnt -= cd[j] , cr[i] -= cd[j] , cd[j] = 0 , j++;
		else cnt -= cr[i] , cd[j] -= cr[i] , cr[i] = 0 , i++;
	}
	cout << cnt;
}
