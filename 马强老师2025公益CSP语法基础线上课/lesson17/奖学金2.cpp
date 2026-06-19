/*
  
 */
#include<bits/stdc++.h>
using namespace std;
struct stu{
	int sum,num,c,m,e;
}a[301];
int n;
bool cmp(stu x,stu y){
	if(x.sum!=y.sum)
		return x.sum>y.sum;
	if(x.c!=y.c)
		return x.c>y.c;
	return x.num<y.num;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].m>>a[i].e;
		a[i].sum=a[i].c+a[i].m+a[i].e;
		a[i].num=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=5;i++)
		cout<<a[i].num<<' '<<a[i].sum<<endl;
	return 0;
}
