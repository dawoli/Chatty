#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int n, r[111111], t[111111], c;

int main(){
	freopen("deul.in", "i", stdin);
	freopen("deul.out", "o", stdout);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> r[i];
	}
	for(int i=0; i<n; i++){
		t[r[i]]++;
	}
	for(int i=1; i<100001; i++){
		c=max(0, c-t[i]);
		c+=t[i]; 
	}
	cout << c << endl;
	return 0;
} 
