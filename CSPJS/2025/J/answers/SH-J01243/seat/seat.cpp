#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],pos;
int hang,lie;
bool cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int all=n*m;
	for(int i=1;i<=all;i++)	cin>>a[i];
	int R=a[1];
	sort(a+1,a+1+all,cmp);
	for(int i=1;i<=all;i++){
		if(a[i]==R){
			pos=i;
		}
	}
	if(pos%n!=0){
		hang=pos/n+1;
	}
	else{
		hang=pos/n;
	}
	if(hang%2==0)
	{
		lie=m-(pos-(hang-1)*n)+1;
	}
	else
	{
		lie=pos-(hang-1)*n;
	}
	cout<<hang<<' '<<lie<<endl;
	return 0;
}
