#include<bits/stdc++.h>
using namespace std;
string a[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		for(int j = 1;j < i;j++){
			if(a[j] == a[i]){
				cnt++;
				break;
			}
		}
	}
	cout << 52 - n + cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
