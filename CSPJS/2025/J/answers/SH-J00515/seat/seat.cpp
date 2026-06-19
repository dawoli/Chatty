#include<bits/stdc++.h>
using namespace std;

bool cmp(long long a,long long b) {
	if(a > b)return true;
	else return false;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin >> m >> n ;
	int sum = m*n;
	vector<int> score(sum,0);
	for(int i = 0; i < sum; ++ i) {
		cin >> score[i];
	}
	int R = score[0];

	sort(score.begin(),score.end(),cmp);
	int _ans = 0;

	for(int i = 0; i < sum; ++ i) {
		if(score[i] == R) {
			_ans = i;
		}
	}
	int c = 1 + _ans / n;
	int r = 0;
	cout << c << ' ';
	switch(c % 2) {
		case 1:
			r = 1 + _ans % m;
			break;
		case 0:
			r = n - _ans % m;
	}
	cout << r << endl;
	return 0;
}

