#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string n; 
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	for(int i = 0;i <= n.size()-1;i++){
		if(n[i]<='9'&&n[i]>='0'){
			a[n[i]-48]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		if(a[i]){
			for(int j = 1;j <= a[i];j++){
				cout << i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
