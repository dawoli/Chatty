#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
//int mapping[10]={6,2,5,5,4,5,6,3,7,6};
int reversed[8]={-1,-1,1,7,4,2,0,8};
int length;
int t(int sticksleft,int digitsleft,int tryn,int pre[]){
	int resarr[length];
	for(int i=0;i<length;i++){
		resarr[i]=pre[i];
	}
	int index=length-digitsleft;
	if((!sticksleft&&digitsleft)||(sticksleft&&!digitsleft))return -1;
	if(!sticksleft&&!digitsleft){
		sort(resarr,resarr+index);
		int i=0;
		while(resarr[i]==0&&i<index)i++;
		if(i==index)return -1;
		else swap(resarr[0],resarr[i]);
		int res=0;
		for(int i=0;i<index;i++){
			res=res*10+resarr[i];
		}
		return res;
	}
	if(tryn==1)return -1;
	for(int i=index;i<length;i++){
		resarr[i]=reversed[tryn];
	}
	int subres,res=-1;
	for(int number=0;number<=digitsleft&&number*tryn<=sticksleft;number++){
		subres=t(sticksleft-number*tryn,digitsleft-number,tryn-1,resarr);
		if(subres==-1)continue;
		if(res==-1)res=subres;
		else res=min(res,subres);
	}
	if(tryn==6){
		for(int i=index;i<length;i++){
			resarr[i]=6;
		}
		for(int number=0;number<=digitsleft&&number*tryn<=sticksleft;number++){
			subres=t(sticksleft-number*tryn,digitsleft-number,tryn-1,resarr);
			if(subres==-1)continue;
			if(res==-1)res=subres;
			else res=min(res,subres);
		}
	}
	return res;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int inquiry;
	cin>>inquiry;
	int sticks,digits;
	while(inquiry--){
		cin>>sticks;
		digits=ceil(sticks/7.0);
		int resarr[digits];
		length=digits;
		cout<<t(sticks,digits,7,resarr)<<endl;
	}
	return 0;
}

