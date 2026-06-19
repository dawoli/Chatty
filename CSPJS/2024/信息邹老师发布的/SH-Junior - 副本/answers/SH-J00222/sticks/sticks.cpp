#include<bits/stdc++.h>
using namespace std;
int arr[10]={6,2,5,5,4,5,6,3,7,6};
//           0 1 2 3 4 5 6 7 8 9
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int c;
		cin>>c;
		if(c==1)cout<<-1;
		else if(c==2)cout<<1;
		else if(c==3)cout<<7;
		else if(c==4)cout<<4;
		else if(c==5)cout<<2;
		else if(c==6)cout<<6;
		else if(c==7)cout<<8;
		else{
			int beishu=c/7;
			int yushu=c%7;
			if(yushu==0)cout<<8;
			if(yushu==1)cout<<10;
			if(yushu==2)cout<<18;
			if(yushu==3)cout<<22;
			if(yushu==4)cout<<20;
			if(yushu==5)cout<<28;
			if(yushu==6)cout<<80;
			for(int i=0;i<beishu-1;i++)cout<<8;
		}
		cout<<endl;
	} 
	return 0;
}
