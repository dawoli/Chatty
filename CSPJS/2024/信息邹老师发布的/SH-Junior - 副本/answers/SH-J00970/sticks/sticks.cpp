#include<bits/stdc++.h>
using namespace std;

//               0   1   2   3   4   5   6   7   8   9 
int stick[10] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
//打表           0    1   2   3   4   5   6   7   8    9    10   11   12   13   14   15    16    17    18    19    20    21
int num[100] = {-1 , -1 , 1 , 7 , 4 , 2 , 6 , 8 , 10 , 18 , 23 , 20 , 28 , 68 , 88 , 108 , 188 , 200 , 208 , 288 , 688 , 888};

int main(){
	int T;
	freopen("sticks.in" , "r" , stdin);
	freopen("sticks.out" , "w" , stdout);
	cin >> T;
	for(int i = 1 ; i <= T ; i ++){
		int n;
		cin >> n;
		if(n <= 21) cout << num[n];
		else{
			//打表结论：往后接8保证位数最少 
		    cout << num[(n % 7) + 14];
		    for(int i = n ; i >= 21 ; i -= 7){
		    	cout << '8';
			}
		}
		cout << endl;
	}
	
	return 0;
}

