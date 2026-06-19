#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[10]={6,2,5,5,4,5,6,3,7,5},e,d,c; 
void find(int s){
	int x=s/7+1,y=s;
	for(int i=1;i<=n;i++){
		y-=b[i];
		if(y>(x-1)*7){
			continue;
		}else{
			if((y-(x-1)*7)==1){
				continue;
			}else{
				e=b[i];
				d=y-7;
				c=7;
			}
		}
	}
	return a,b,c;
}
int main(){
	//freopen("sticks.in","r",stdin);
	//freopen("sticks.out","r",stdout);
	freopen("sticks1.in","r",stdin);
	freopen("sticks1.out","r",stdout);
	cin>>n;
	for(int i=1;i<+n;i++){
		cin>>a[i];
		if(a[i]==1){
			cout<<"-1"<<endl;
		}else if(a[i]==2){
			cout<<"1"<<endl;
		}else if(a[i]==3){
			cout<<"7"<<endl;
		}else if(a[i]==4){
			cout<<"4"<<endl;
		}else if(a[i]==5){
			cout<<"2"<<endl;
		}else if(a[i]==6){
			cout<<"6"<<endl;
		}else if(a[i]==7){
			cout<<"8"<<endl;
		}else{
			find(a[i]);
			cout<<e<<' '<<d<<' '<<c<<endl;
		}
		
	}
	system("fc explore1.ans explore1.out\n")
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
