# include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[10006];
	cin >> a;
	int cnt = 1,i = 0;
	while(int(a[i]) > 0 && int(a[i]) <= 180){
		if(int(a[i]) >= 48 && int(a[i])<= 57){
			b[cnt] = int(a[i]) - 48;
			cnt++;
			i++;
		}
		else{
			i++;
		}
	}
	for(int j = 1;j <= cnt;j++){
		for(int k = j + 1;k <= cnt;k++){
			if(b[j] <= b[k]){
				swap(b[j],b[k]);
			}
		}
	}
	for(int j = 1;j < cnt;j++){
		cout << b[j];
	}
	return 0;
}
