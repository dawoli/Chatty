#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}sort(a+1,a+n+1);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
