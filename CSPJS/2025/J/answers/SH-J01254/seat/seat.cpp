#include<bits/stdc++.h>
using namespace std;
struct stu{
	int s,id;
};
bool cmp(stu a,stu b){
	return a.s>b.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,mc=0;
	cin>>n>>m;
	stu a[n*m+1];
	for(int i=1;i<n*m+1;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<n*m+1;i++){
		if(a[i].id==1){
			mc=i;
			break;
		}
	}
	int l=mc/n;
	if(mc%n!=0){
		l+=1;
	}
	cout<<l<<" ";
	if(l%2==0){
		cout<<m-mc+(l-1)*n+1;
	}
	else{
		cout<<mc-((l-1)*n);
	}
	return 0;
}




