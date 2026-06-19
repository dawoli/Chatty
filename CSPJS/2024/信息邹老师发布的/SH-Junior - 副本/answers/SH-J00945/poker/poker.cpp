#include<bits/stdc++.h>
using namespace std;

int n, cnt;
string k[100];

bool cmp1(string a, string b){
	return a[1] < b[1];
}

bool cmp2(string a,string b){
	return a[0] < b[0] and a[1]==b[1];
}

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> k[i];
	sort(k,k+n,cmp1);
	sort(k,k+n,cmp2);
//	for (int i = 0; i < n; i++)cout << k[i] << endl;
	for (int i = 0; i < n; i++) {
		cnt++;
		while (k[i+1]==k[i] and i+1 < n)i++;
	}
	cout << 52-cnt;
	return 0;
}
