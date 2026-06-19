#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
	return a > b;
}

int main(){
	string a, b[100005], c;
	
	freopen("number.in", "r", stdin); freopen("number.out", "w", stdout);
	cin >> a;

	int ind = 1;
	for(int i = 0; i <= a.length(); i++){
		if (a[i] <= '9' && a[i] >= '0'){
			b[ind] = a[i];
			ind++;
		}
	}
	sort(b + 1, b + ind, cmp);
	for (int i = 1; i < ind; i++){
		c += b[i];
	}
	cout << c;
}
