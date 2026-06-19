#include <bits/stdc++.h> 
using namespace std;

char ch;
int a[500];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	while(cin >> ch){
		if(isdigit(ch)){
			a[ch]++;
		}
	}
	for(char i='9';i >= '0';i--){
		while(a[i]){
			cout << i;
			a[i]--;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
