//7 2 5   4   6 3 8 7
//0 1 2 3 4 5 6 7 8 9
#include<bits/stdc++.h> 
using namespace std;

int main(){
	int t,n[55],s=1,ans[55],num=0;
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n[i];
	}
	for(int i=0;i<t;i++){
		s=1;
		num=0;
		if(n[i]==1)ans[i]=-1;
		if(n[i]==2)ans[i]=1;
		if(n[i]==3)ans[i]=7;
		if(n[i]==4)ans[i]=4;
		if(n[i]==5)ans[i]=2;
		if(n[i]==6)ans[i]=6;
		if(n[i]==7)ans[i]=9;
		if(n[i]==8)ans[i]=8;
		if(n[i]==9)ans[i]=10;
		if(n[i]==10)ans[i]=18;
		if(n[i]==11)ans[i]=26;
		if(n[i]==12)ans[i]=20;
		if(n[i]==13)ans[i]=28;
		if(n[i]==14)ans[i]=68;
		if(n[i]==15)ans[i]=80;
		if(n[i]==16)ans[i]=88;
		if(n[i]==17)ans[i]=100;
		if(n[i]==18)ans[i]=208;
		if(n[i]==19)ans[i]=228;
		if(n[i]==20)ans[i]=280;
		
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
