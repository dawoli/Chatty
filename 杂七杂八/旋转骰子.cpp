//
/*

左，右，下
 
 
*/

#include <iostream>
using namespace std;
//f记录前面的数值 ，u记录上面的数值，r记录右边的数值
int u=1;
int f=2;
int r=3;

//用于模拟旋转骰子 ,s=R向右滚动，s= L向左滚动，s=D向下滚动 
void rotate(char s) {
	if (s == 'R') {
		f = f;
		int temp = u;
		u = 7-r;
		r = temp;
	} else if (s == 'L') {
		f = f;
		int temp = u;
		u = r;
		r = 7-temp;
	} else if (s == 'D') {
		int temp = f;
		f = u;
		u = 7-temp;
		r = r;
	}
	return;
}

int main() {
	int R,C;
	cin>>R>>C;
	long long sum = 0;
	bool flag = true;//true表示从左往右，false表示从右往左
	for(int i=1;i<=R;i++) {
		sum += (C/4)*14;
		for(int j=1;j<C%4;j++) {
			sum += u;
			if (flag == true) { //从左往右 
				rotate('R');
			} else { //从右往左 
				rotate('L');
			}
		}
		flag = !flag;//换方向 
		sum += u;
		rotate('D');
	} 
	cout << sum << endl; 
	return 0;
}
