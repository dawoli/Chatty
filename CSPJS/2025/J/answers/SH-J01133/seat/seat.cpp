#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n,m;
struct node{
	int i,a;
}stu[maxn];
bool cmp(node x,node y){
	return x.a > y.a;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n * m;i ++){
		scanf("%d",&stu[i].a);
		stu[i].i = i;
	}
	sort(stu + 1,stu + (n * m) + 1,cmp);
	int x = 1,y = 0,s = 1;
	for(int i = 1;i <= n * m;i ++){
		y += s;
		if(y == n + 1 || y == 0){
			y -= s;
			x ++;	s *= -1;
		}
		if(stu[i].i == 1)	printf("%d %d\n",x,y);
	}
	return 0;
}
