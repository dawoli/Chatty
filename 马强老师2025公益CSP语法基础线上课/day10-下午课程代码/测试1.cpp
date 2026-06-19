#include<iostream>
#include<algorithm> //srot
using namespace std;
bool cmp(int x,int y){
	return x>y; //降序
}
int main(){
	int a[6]={3,1,2,5,4};
	sort(a+0,a+5,cmp); //顾头不顾尾
	for(int i=0;i<5;i++)
		cout<<a[i]<<' ';
	return 0;
}
