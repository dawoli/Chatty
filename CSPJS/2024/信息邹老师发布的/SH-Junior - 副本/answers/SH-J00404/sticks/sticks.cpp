#include<bits/stdc++.h>
using namespace std;
int t,n[100005]={0,-1,1,7,4,2,6,8},x,tong[100];
int main(){
	
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
    n[8]=10;
    n[9]=18;
    n[10]=22;
    n[11]=20;
    n[12]=28;
    n[13]=80;
    n[14]=88;
    n[15]=108;
    n[16]=188;
    n[17]=200;
    n[18]=208;
    n[19]=288;
    n[20]=808;
    n[21]=888;
    cin>>t;
    while(t--){
    	cin>>x;
    	if(n[x])cout<<n[x];
    	else if(x%7==0){//x=7k
    		for(int i=1;i<=x/7;i++)cout<<8;
		}
		else if((x-1)%7==0){//x=7k+1
			cout<<10;
			for(int i=1;i<=(x-8)/7;i++){
				cout<<8;
			}
		}
		else if((x-2)%7==0){//x=7k+2
			cout<<1;
			for(int i=1;i<=(x-2)/7;i++)cout<<8;
		}
		else if((x-3)%7==0){//x=7k+3
			cout<<200;
			for(int i=1;i<=(x-3)/7-2;i++)
			cout<<8;
		}
		else if((x-4)%7==0){//x=7k+4
			cout<<20;
			for(int i=1;i<=(x-4)/7-1;i++)
			cout<<8;
		}
		else if((x-5)%7==0){//x=7k+5
			cout<<2;
			for(int i=1;i<=(x-5)/7;i++)
			cout<<8;
		}
		else if((x-6)%7==0){//x=7k+6
			cout<<80;
			for(int i=1;i<=(x-6)/7-1;i++)
			cout<<8;
		}
		cout<<endl;
	}
    
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
