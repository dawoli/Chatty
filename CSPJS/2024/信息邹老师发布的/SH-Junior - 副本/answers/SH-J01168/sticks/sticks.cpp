#include <bits/stdc++.h>
using namespace std;
int l[10]={6,2,5,5,4,5,6,3,7,6};
int n,f,nl[100010]={0},a=0;
void fun(int num,long long s){
	if(num==0){
		f=1;
		nl[++a]=s;
	}
	if(num<2){
		return;
	}
	if(num==n){
		for(int i=1;i<=9;i++){
			fun(num-l[i],s*10+i);
		}
	}else if(num<n && num>0){
		for(int i=0;i<=9;i++){
			fun(num-l[i],s*10+i);
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		fun(n,0);
		if(!f){
			cout<<-1<<endl;
		}else{
			long long b=1e50+9;
			for(int i=1;i<=a;i++){
				if(b>nl[i] && nl[i]!=0){
					b=nl[i];
				}
			}
			cout<<b<<endl;
			for(int i=1;i<=a;i++){
				nl[i]=0;
			}
		}
		
	}
	
	return 0;
}
