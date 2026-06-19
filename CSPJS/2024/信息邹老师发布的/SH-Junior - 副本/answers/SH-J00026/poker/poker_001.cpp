#include <bits/stdc++.h>
using namespace std;
string a[53],b[53];
int lb;
bool cmp(string a,string b){
	return a < b;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}
	if(n == 1){
		cout << 51 << endl;
		return 0;
	}
	sort(a,a + n,cmp);
	for(int i = 0;i < n - 1;i ++){
		if(a[i] != a[i + 1]){
			b[lb ++] = a[i]; 
		}
	}
	if(a[n - 1] != a[n - 2]) lb ++;
	cout << 52 - lb;
	return 0;
} 
/*
4
DQ
H3
DQ
DT
*/ 
