#include <bits/stdc++.h>
using namespace std;
int n,m,now=1,nowx=1,nowy,on=1,rp;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	rp++;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)now=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(on==1){
			nowy++;
			if(nowy==n)on++;
		}
		else if(on==2){
			nowx++;
			on++;
		}
		else if(on==3){
			nowy--;
			if(nowy==1)on++;
		}
		else if(on==4){
			nowx++;
			on=1;
		}
		//cout<<a[i]<<" "<<nowx<<" "<<nowy<<endl;
		if(a[i]==now){
			cout<<nowx<<" "<<nowy<<endl;
			break;
		}
	}
	return 0;
} 
