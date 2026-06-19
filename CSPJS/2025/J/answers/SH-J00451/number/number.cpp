#include<iostream>
#include<algorithm>
using namespace std;
//char s[1000005];
string s;
bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int i=0;
	int o=0;
	char a[1000005];
	cin>>s;
	while(s[i] != '\0'){
		if(s[i] >= '0' && s[i] <= '9'){
			a[o] = s[i];
			o++;
		}
		i++;
	}
	sort(a, a+o, cmp);
	cout << a;
	return 0;
}
