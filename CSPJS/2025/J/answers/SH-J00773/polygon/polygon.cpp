#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> sticks;
int n, cnt;

void f(int point, int sum, int mx, int num){
	if (num >= 3 && sum > mx * 2){
		cnt ++;
		cnt %= 998244353;
	}
	for (int i = point + 1;i < n;i++){
		f(i, sum + sticks[i], max(mx, sticks[i]), num + 1);
	}
}

int main(){
	//begin
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	//input
	cin >> n;
	sticks.resize(n);
	for (int i = 0;i < n;i++) cin >> sticks[i];
	//start
	f(-1, 0, 0, 0);
	cout << cnt;
	//end
	fclose(stdin);
	fclose(stdout);
	return 0;
}
