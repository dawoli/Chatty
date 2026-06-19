#include<bits/stdc++.h>
int Number[10] = {0,0,0,0,0,0,0,0,0,0};
long long answer = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std :: string a;
	std :: cin >> a;
	for(int i = 0;i < a.size();i++){
		if(a[i] <= '9' && a[i] >= '0'){
			Number[int(a[i]-'0')]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= Number[i];j++){
			std :: cout << i;
		}
	}
	std :: cout << answer;
	return 0;
}
