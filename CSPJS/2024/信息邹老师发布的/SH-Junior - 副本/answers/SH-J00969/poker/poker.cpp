#include<bits/stdc++.h>
using namespace std;
struct poker{
	char num;
}p[14];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52,a[60]={};
	for(int i=2;i<=9;i++){
		p[i].num=i;
	}
	p[1].num='A';
	p[10].num='T';
	p[11].num='J';
	p[12].num='Q';
	p[13].num='K';
	cin>>n;
	for(int i=1;i<=n;i++){
		char tmp[10];
		cin>>tmp;
		for(int i=1;i<=13;i++){
			if(p[i].num==tmp[1]){
				int sum;
				if(tmp[0]='D'){
					sum=i;
				}
				else if(tmp[0]='C'){
					sum=i+13;
				}
				else if(tmp[0]='H'){
					sum=i+26;
				}
				else if(tmp[0]='S'){
					sum=i+39;
				}
				a[sum]=1; 
			}
		}
	}
	for(int i=1;i<=52;i++){
		ans-=a[i];
	}
	cout<<ans;
	return 0;
}
