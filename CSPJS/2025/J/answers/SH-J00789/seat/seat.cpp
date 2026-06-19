#include <bits/stdc++.h>
using namespace std;
const int N = 1007;
int n,m;
struct xue{
	int score;
	bool flag;
} a[N];
bool cmp(xue x,xue y){
	return x.score > y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	int sum = n*m;
	a[1].flag = 1;
	for(int i = 1;i <= sum;i++){
		cin >> a[i].score;
	}
	sort(a+1,a+sum+1,cmp);
	int x = 1,y = 1,addx = 1;
	for(int i = 1;i <= sum;i++){
		if(a[i].flag){
			printf("%d %d",y,x);
			return 0;
		}
		if(x == n&&addx == 1){
			y++;
			addx = -1;
		}else if(x == 1&&addx == -1){
			y++;
			addx = 1;
		}else x += addx;
	}
	return 0;
}
