#include <bits/stdc++.h>
using namespace std;

string a;
int total, arr[1000005];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for (int i = 0, j = 0; i < a.size(); i ++){
		if (a[i] >= '0' && a[i] <= '9') arr[j] = a[i] - '0', j ++;
		total = j;
	}
	sort(arr, arr + total, cmp);
	for (int i = 0; i < total; i ++){
		cout << arr[i];
	}
	return 0;
}
