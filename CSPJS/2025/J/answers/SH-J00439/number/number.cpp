#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str1;
	int numbers[15] = {0};
	cin >> str1;
	for(int i=0;str1[i];i++){
		if(int(str1[i]) >= 48 && int(str1[i]) <= 57) numbers[int(str1[i])-48]++; //0~9:48~57;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<numbers[i];j++){
			cout << i;
		}
	}
	return 0;
}
