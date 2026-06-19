#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N=1e5+1;

int n;
int a[N];

int main () {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a+1, a+1+n);
	
	int p=1,q=1;
	while(q<=n){
		if(a[p]<a[q]){
			p++;
		}
		q++;
	}
	cout << n - p + 1 << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
