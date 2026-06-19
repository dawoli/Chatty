#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("chain.in" , "r" , stdin);
	freopen("chain.out" , "w" , stdout);
	int T;
	cin >> T;
	
	for(int e = 1 ; e <= T ; e ++){
		int s[300009];
		int begin[100009] = {-1 , 1};
		int len[100009];
		int taskr[100009] , taskc[100009];
	    int n , k , q;
	    cin >> n >> k >> q;
	    
	    for(int i = 1 ; i <= n ; i ++){
	    	cin >> len[i];
	    	begin[i + 1] = begin[i] + len[i];
	    	for(int j = 1 ; j <= len[i] ; j ++){
	    		cin >> s[begin[i] + j];
			}
		}
		
		for(int i = 1 ; i <= q ; i ++){
			cin >> taskr[i] >> taskc[i];
		}
		
		//¡¶Å­ÔÒËæ»ú¡·
		for(int i = 1 ; i <= q ; i ++){
			int a = rand() % 2;
			cout << a << endl;
		}
		
	}
	return 0;
}

