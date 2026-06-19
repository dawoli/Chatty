#include<bits/stdc++.h>
using namespace std;
struct student{
	int score;
	bool isXiaoR;
};
bool cmp(const student&a,const student&b){
	if(a.score>b.score) return true;
	return false;
}
student a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		student temp;
		cin>>temp.score;
		if(i==1) temp.isXiaoR=true;
		else temp.isXiaoR=false;
		a[i]=temp;
	}
	sort(a+1,a+m*n+1,cmp);
	for(int y=1;y<=m;y++){
		for(int x_1=1,x_2=n;x_1<=n;x_1++,x_2--){
			int i=(y-1)*n+x_1;
			if(a[i].isXiaoR==true) cout<<y<<" "<<((y%2==1)?x_1:x_2);
		}
	}
	return 0;
}
