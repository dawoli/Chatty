#include<iostream>
using namespace std;
int main(){
	int sum=15; //已经排好的座位
	int m=15; //当前排的座位数量
	for(int i=1;sum<=312;i++){ //i:行号
		cout<<i<<' '<<m<<' '<<sum<<endl;
		m+=2; //每排增加2个座位
		sum+=m;
	}
	return 0;
}
