#include<bits/stdc++.h>
using namespace std;
int T;
const int N = 1e5 + 10;
int a[N][13];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	int n;
	int s = 0;
	while(T --){
		cin >> n;
		s = 0;
		for(int i = 1; i <= n; i ++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(n == 2){
			for(int i = 1; i <= 3; i ++){
				for(int j = 1; j <= 3; j ++){
					if(i == j) continue;
					s = max(s,a[1][i] + a[2][j]);
				}
			}
			cout << s << endl;
			continue;
		}
		if(n == 4){
			int t = a[1][1] + a[2][2] + a[3][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[4][i]);
			t = a[1][1] + a[3][2] + a[2][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[4][i]);	
			t = a[2][1] + a[3][2] + a[1][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[4][i]);
			t = a[2][1] + a[1][2] + a[3][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[4][i]);
			t = a[3][1] + a[2][2] + a[1][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[4][i]);
			t = a[3][1] + a[1][2] + a[2][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[4][i]);
			t = a[1][1] + a[2][2] + a[4][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[3][i]);
			t = a[1][1] + a[4][2] + a[2][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[3][i]);
			t = a[2][1] + a[1][2] + a[4][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[3][i]);
			t = a[2][1] + a[4][2] + a[1][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[3][i]);
			t = a[4][1] + a[2][2] + a[1][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[3][i]);
			t = a[4][1] + a[1][2] + a[2][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[3][i]);
			t = a[1][1] + a[3][2] + a[4][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[2][i]);
			t = a[1][1] + a[4][2] + a[3][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[2][i]);
			t = a[4][1] + a[1][2] + a[3][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[2][i]);
			t = a[4][1] + a[3][2] + a[1][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[2][i]);
			t = a[3][1] + a[1][2] + a[4][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[2][i]);
			t = a[3][1] + a[4][2] + a[1][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[2][i]);
			t = a[2][1] + a[3][2] + a[4][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[1][i]);
			t = a[2][1] + a[4][2] + a[3][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[1][i]);
			t = a[3][1] + a[2][2] + a[4][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[1][i]);
			t = a[3][1] + a[4][2] + a[2][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[1][i]);
			t = a[4][1] + a[3][2] + a[2][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[1][i]);
			t = a[4][1] + a[2][2] + a[3][3];
			for(int i = 1; i <= 3; i ++)
				s = max(s,t + a[1][i]);
			cout << s << endl;
		}
	}
	return 0;
//I L U YX
} 
