#include<bits/stdc++.h>

using namespace std;

char a[1000001];
int ans_find[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s", a);
	int n = strlen(a);
	for(int i = 0; i < n; ++i){
		int b = a[i] - '0';
		if(b >= 0 && b <= 9){
			ans_find[b]++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= ans_find[i]; ++j){
			cout << i;
		}
	}
	return 0;
}
