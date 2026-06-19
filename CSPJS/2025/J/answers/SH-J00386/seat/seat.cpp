#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int record=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	record=a[1];
	sort(a+1,a+n*m+1,cmp);
	int tip;
	for (int i=1;i<=n*m;i++){
		if (a[i]==record){
			tip=i;
			break;
		}
	}
	//cout<<tip<<"\n";
	int lie=(tip+m-1)/m;
	int hang=tip%m;
	if(hang==0) hang=m;
	if(lie%2==0) hang=m-hang+1;
	printf("%d %d",lie,hang);
	return 0;
}
