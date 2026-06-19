#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R,hang=1,lie=1,shu;
bool d=1; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	shu=n*m;
	for(int i=1;i<=shu;i++){
		cin>>a[i];
		if(i==1)R=a[i];
	}
	sort(a+1,a+shu+1);
	while(1){
		if(a[shu]==R)break;
		shu--;
		if(hang==1&&lie%2==0){
			lie+=1;
			d=1;
		}
		else if(hang==n&&lie%2==1){
			lie+=1;
			d=0;
		}
		else if(d)hang+=1;
		else if(!d)hang-=1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
