#include<bits/stdc++.h>
using namespace std;
const int N=109;
int n,m,p;
struct Student{
	int id;
	int score;
} stu[N];
bool cmp(const Student&a,const Student&b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		stu[i].id=i;
		cin>>stu[i].score;
	}
	sort(stu+1,stu+1+n*m,cmp);
	//for(int i=1;i<=n*m;i++)cout<<stu[i].id<<" "<<stu[i].score<<endl;
	for(int i=1;i<=n*m;i++)if(stu[i].id==1){
		p=i;
		break;
	}
	int mR=(p%n?p/n+1:p/n);
	int nR=(mR%2?p%n:n-p%n+1);
	if(!nR)nR+=n;
	cout<<mR<<" "<<nR;
	return 0;
}
