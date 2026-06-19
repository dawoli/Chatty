#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int k = 1;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {

			a[k] = s[i] - '0';
			//cout << a[k] << " " << s[i]<< endl;
			k++;
		}

	}
	//cout << k << endl;
	k--;
	sort(a+1,a+1+k,greater<int>());
	for(int i =1; i <= k; i++) {
		cout << a[i] ;
	}
	cout << endl;
	//cout << (int)'1' << (int)'9';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
