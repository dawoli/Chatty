#include<bits/stdc++.h>
using namespace std;
int a[109*109],p=1,seat[109][109],n,m,r,c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			p++;
		}
	}
	int cnt=1,l=1,mode=1;
	for(int i=1;i<p;i++){
		if((mode==1&&cnt==n)||(mode==-1&&cnt==1)){
			l++;
			if(l%2==0){
				mode=-1;
			}else{
				mode=1;
			}
		}else{
			cnt+=mode;
		}
		seat[cnt][l]=a[i];
	}
	cout<<l<<' '<<cnt;
}

