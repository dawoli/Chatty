#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//½â×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int num=a[1],score=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			score=i;break;
		}
	}
	//cout<<score<<endl; 
	int nownum=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				nownum++;
				if(nownum==score){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>0;j--){
				nownum++;
				if(nownum==score){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
