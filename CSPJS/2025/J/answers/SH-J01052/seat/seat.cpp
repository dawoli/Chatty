#include <bits/stdc++.h>
using namespace std;
struct stu{
	int cj;
	int seatx;
	int seaty;
	bool xi;
};
bool cmp2(stu a,stu b){
	return a.cj>b.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	stu a[1086];
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
		if(i==1){
			a[i].xi=true;
		}else{
			a[i].xi=false;
		}
	}
	sort(a+1,a+n*m+1,cmp2);
	int x=1,y=1;
	int cnt=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[cnt].seatx=i;
			a[cnt].seaty=j;
			cnt++;
		}
		i++;
		for(int j=n;j>=1;j--){
			a[cnt].seatx=i;
			a[cnt].seaty=j;
			cnt++;
			
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].xi){
			cout<<a[i].seatx<<" "<<a[i].seaty;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
