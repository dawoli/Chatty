/*
双重循环
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int cnt=0;
	for(int i=1;i<=60;i++){//i等于分钟数
		for(int j=1;j<=60;j++){
			cnt++;
			
			cout<<i<<' '<<j<<' '<<cnt<<endl;
			//system("pause");
		}
			
	}
	cout<<cnt<<endl;
	return 0;
}
