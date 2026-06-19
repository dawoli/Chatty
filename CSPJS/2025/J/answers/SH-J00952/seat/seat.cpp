#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,pos;  //n行m列，即i<=n,j<=m 
//i控制竖，j控制横 
//输出先纵后横，即cout j,i 
struct stu{
	int sco,num;
}a[105];
bool cmp(stu x,stu y) {
	return x.sco>y.sco;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++) {
		cin >> a[i].sco;
		a[i].num = i;
	} 
	sort(a+1,a+m*n+1,cmp);
	for (int i=1;i<=n*m;i++) {
		if (a[i].num == 1) {
			pos = i;
			break;
		}
	}
	int dic = (pos/n+1)%2;  //所在的那一列的方向情况 
	if (pos%n == 0) {  //末尾还在这一列，不能往后 
		dic = (pos/n) %2;
	}
	//1=从前向后 ，2=从后向前
	int pi = pos%n;  //第几行 
	if (pi == 0) {  //0代表这一列末尾 
		pi = n;
	}
	if (dic == 0) {  //从后向前就反过来 
		pi = n-pi+1;
	}
	int pj = pos/n+1;  //第几列
	if (pos%n == 0) {  //这一列末尾还在这一列，不能过去 
		pj -= 1;
	}
	cout << pj << " " << pi; 
}
