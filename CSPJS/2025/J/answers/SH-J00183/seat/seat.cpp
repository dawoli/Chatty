#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int n,m,a[10005],xiaor,index,col,row;  //n,m行数列数，a为成绩，xiaor为小R成绩，index为排序后小R成绩下标，col,row为小R的座位位置（列、行） 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xiaor=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xiaor){
			index=i;
			break;
		}
	}
	col=ceil((double)index/n);
	if(col%2==0) row=n+1-(index%n);
	else row=((index%n)?(index%n):(n));
	cout<<col<<" "<<row;
	return 0;
}
