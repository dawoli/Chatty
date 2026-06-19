#include <bits/stdc++.h>
using namespace std;
int n,m,x,y=1;
bool w = false; //false-down,true-up
struct node{
	int id,sc;
};
node a[105];
bool cmp(node x,node y)
{
	return x.sc > y.sc;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int nu = n*m;
	for(int i = 1; i <= nu; i ++){
		scanf("%d",&a[i].sc);
		a[i].id= i;
	}
	sort(a+1,a+nu+1,cmp);
	for(int i = 1; i <= nu; i ++)
	{
		if(!w) {
			if((x+1) <= n) x ++;
			else {
				y ++;
				w = true;
			}
		}
		else
		{
			if((x-1) >= 1) x --;
			else {
				y ++;
				w = false;
			}
		}
		if(a[i].id == 1) break;
	}
	printf("%d %d",y,x);
	return 0;
}
