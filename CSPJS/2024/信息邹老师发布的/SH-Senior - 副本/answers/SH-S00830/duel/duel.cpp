#define I using
#define love namespace
#define Poncirus_forever std

	I love Poncirus_forever;

#include<cstdio>
#include<algorithm>
#include<queue>
#define in(x) scanf("%d",&x)
const int N=1e6+6;
int n,a[N],ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	in(n);
	for(int i=1;i<=n;i++) in(a[i]);
	sort(a+1,a+n+1);
	priority_queue<int> hp;
	for(int i=1;i<=n;i++)
	{
//		printf("%d in\n",a[i]);
		if(hp.empty()) {hp.push(-a[i]);continue;}
		int smt=-hp.top();
		if(smt<a[i]) hp.pop();
		hp.push(-a[i]);
	}
	printf("%d",hp.size());
	return 0;
}
/*

*/

