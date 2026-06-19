#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	char m;
	cin >> n;
	for(int i = 0;i < n;i ++) cin >> m;
	cout << 52 - n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
