#include <iostream> 
#include <algorithm>
using namespace std;

short a[1000020];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0;
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++) {
		char x = s[i];
		if (x >= '0' && x <= '9') {
			k++;
			a[k] = (x-'0');		
		}
	}
	sort(a+1,a+k+1);
	
	for (int i=k;i>=1;i--) {
		cout << a[i];
	}
	return 0;
}
