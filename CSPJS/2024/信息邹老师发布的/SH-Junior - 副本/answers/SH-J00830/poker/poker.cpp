// QUESTION: is the string lines required?
#include<bits/stdc++.h>
using namespace std;
char s[60][5];
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>s[i];
	}
	cout<<52-n<<endl;
	return 0;
}
