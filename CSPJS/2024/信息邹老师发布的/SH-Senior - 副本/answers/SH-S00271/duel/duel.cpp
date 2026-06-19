#include<iostream>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int a,b[1000],c=99999,d[1000],e=0;
	cin>>a;
	int r;
	r=a;
	for(int j=1;j<=a;j++){
			cin>>b[j];
		}
	e=0;
	for(int j=1;j<=a;j++){
			if(b[j]<=c){
				c=b[j];
				e++;
			}
		} 
	for(int j=1;j<=a;j++){
			if(b[j]>c){
				d[j]=b[j];
			}
		}
	int f=999999,g=0;
	for(int j=1;j<=a;j++){
		if(d[j]<=f){
			f=b[j];
			g++;
		}
	}
	if(g==e){
		a=a-e-g;
	}
	else{
		if(a>g){
			a=a-g-g;
		}
		else{
			a=a-e-e;
		}
	}
	cout<<a-1;
	return 0;
} 
