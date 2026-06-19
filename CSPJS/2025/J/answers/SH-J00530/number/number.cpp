#include <bits/stdc++.h>
using namespace std;
int n;
char inp[10000000];
int nums[12];
int temp;
 
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.ans", "w", stdout);
	scanf("%s", &inp);
	for (int i=0;i<=sizeof(inp);i++){
//		cout << inp[i]-48 << endl;
		temp = inp[i]-48;
//		cout << temp << endl;
		if (temp>=0 &&temp <=9){
			nums[temp]++;
		}
	}
	for(int i=9;i>=0; i--){
		for(int j=1;j<=nums[i];j++){
			cout << i;
		}
	}
	return 0;
}
