#include <bits/stdc++.h>
using namespace std;
int cnst[]={6,2,5,5,4,5,6,3,7,6};
long long getMinimum(long long baseNumber,int sticks){
	if(sticks==0){
		return baseNumber;
	}
	baseNumber*=10;
	int startN=1;
	int minimum=-1;
	if(baseNumber!=0)startN--;
	for(;startN<10;startN++){
		if(sticks<cnst[startN]){
			continue;
		}
		int minix=getMinimum(baseNumber+startN,sticks-cnst[startN]);
		if(minix!=-1){
			if(minimum==-1){
				minimum=minix;
			}else{
				minimum=min(minimum,minix);
			}
		} 
	}
	return minimum;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int os;
		cin>>os;
		cout<<getMinimum(0,os)<<endl;
	}
	return 0; 
}
