//
/*
123
246
369
a[10] = {1,2,3,2,4,6,3,6,9}
判断a数组当中是否有相同的数字，同时不能有0 

a[10] = {0}
a[i]=1;
 
123 
246
369
a[10] = {0,0,0,0,0,0,0,0,0}
a[10] = {1,0,1,0,0,1,0,0,0}
*/
#include <iostream>
using namespace std;
int a[10] = {0};

// 不能有0，x的每个位数都在a数组中标记为0 
bool f(int x) {
	while(x) {
		if (x%10==0) {
			return false;
		}
		if (a[x%10]==1) {
			return false;
		}
		//标记这个数字已经被使用 
		a[x%10]=1;
		x /= 10;
	} 
	return true; 
}
int main(){

	for(int i=123;i<=333;i++) {
		int j=i*2;
		int k=i*3;
		if (f(i) && f(j) && f(k)) {
			cout<<i<<" "<<j<<" "<<k<<endl;
		}
		for(int i=0;i<10;i++) {
			a[i]=0;
		}
	}

	return 0;
}
//#腾讯会议：670-4386-8611
