#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i = a;i < b;i++)
int T,forcnt;
int a[30];
int c[30],color[30],r=0,b=0; 
int fr(int x,bool co){
	if(x == 0)return 0;
	if(co == false){
		if(r == a[x]){
			a[x] = 0;
			if(c[x] > r){
				return 0;
			}
			r = c[x];
		}else{
			a[x] = 0;
			if(c[x] > b){
				return 0;
			}
			b = c[x];
		} 
	}¡¢ 
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	f(forcnt,1,T+1){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
	}
	
	return 0;
}
