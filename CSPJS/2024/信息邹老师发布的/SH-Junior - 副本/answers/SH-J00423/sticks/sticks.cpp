#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("sticks.in","r",stdin);
	//freopen("sticks.out","w",stdout);
	int myt,myn;
	cin>>myt;
	for(int i=0;i<myt;i++){
		cin>>myn;
		if(myn==1){
			cout<<-1;
			continue;
		}
		if(myn==6){
			cout<<0;
			continue;
		}
		int myl=0;
		if(myn%7>4||myn==0){
			myl=myn/7;
		}else if(myn%7<=4){
			myl=myn/7-1;
		}
		vector<int> mya;
		if(myl>0) mya.resize(myl,8);
		myn-=myl*7;
		if(myn<14){
			if(myn==5) mya.push_back(2);
			if(myn==6) mya.push_back(14);
			if(myn==7) mya.push_back(8);
			if(myn==8) mya.push_back(10);
			if(myn==9) mya.push_back(18);
			if(myn==10) mya.push_back(22);
			if(myn==11) mya.push_back(20);
		}
		int newl=mya.size();
		for(int i=newl-1;i>=0;i--) cout<<mya[i];
	}
	return 0;
}
