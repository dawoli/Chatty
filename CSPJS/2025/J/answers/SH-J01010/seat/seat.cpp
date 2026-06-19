#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c=a*b;
	int d[c];
	for(int i=0;i<c;i++){
		cin>>d[i];
	}
	int e=0;
	for(int i=0;i<c-1;i++){
		for(int j=i+1;j<c;j++){
			if(d[j]>d[i]){
				if(i==e or j==e){
					if(i==e){
						e=j;
					}
					else{
						e=i;
					}
				}
				swap(d[i],d[j]);
			}
		}
	}
	e++;
	int f=e/a;
	if(e%a!=0){
		f++;
	}
	int g=b;
	int h=e-a*(f-1); 
	if(f%2==0){
		g=b-h+1;
	}
	else{
		g=h;
	}
	cout<<f<<" "<<g;
} 
