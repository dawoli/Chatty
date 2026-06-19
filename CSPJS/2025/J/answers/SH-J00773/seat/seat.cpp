#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
	//begin
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	//input
	int n, m;
	cin >> n >> m;
	vector<int> inputs(n * m);
	for (int i = 0;i < n * m;i++){
		cin >> inputs[i];
	}
	//start
	int r = inputs[0];
	vector<vector<int>> seats(n, vector<int>(m));
	sort(inputs.begin(), inputs.end());
	int cnt = n * m;
	for (int i = 0;i < m;i++){
		if (i % 2 == 0){
			for (int j = 0;j < n;j++){
				seats[j][i] = inputs[--cnt];
			}
		}else{
			for (int j = n - 1;j >= 0;j--){
				seats[j][i] = inputs[--cnt];
			}
		}
	}
	//output
	for (int i = 0;i < n;i++){
		for (int j = 0;j < m;j++){
			//cout << seats[i][j] << " ";
			if (seats[i][j] == r){
				cout << j + 1 << " " << i + 1;
			}
		}
	}
	//end
	fclose(stdin);
	fclose(stdout);
	return 0;
}
