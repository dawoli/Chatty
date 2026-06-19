#include<bits/stdc++.h>
using namespace std;
const int stk[11]={6,2,5,5,4,5,6,3,7,6};
int nms[100005];
int q,nm;
int onenm(int tp){//ÉXÉm'sÂí·ä¹ý³óÇë¼ûÁÂ 
	if(tp>100000) return stk[tp/100000]+stk[(tp%=100000)/10000]+stk[(tp%=10000)/1000]+stk[(tp%=1000)/100]+stk[(tp%=100)/10]+stk[tp%=10];
	else if(tp>10000) return stk[tp/10000]+stk[(tp%=10000)/1000]+stk[(tp%=1000)/100]+stk[(tp%=100)/10]+stk[tp%=10];
	else if(tp>1000) return stk[tp/1000]+stk[(tp%=1000)/100]+stk[(tp%=100)/10]+stk[tp%=10];
	else if(tp>100) return stk[tp/100]+stk[(tp%=100)/10]+stk[tp%=10];
	else if(tp>10) return stk[tp/10]+stk[(tp%=10)];
	return stk[tp];
}
void prew(){
	for(int i=0;i<100001;i++){
		int ned=0,tp=i;
		ned+=onenm(tp);
		nms[i]=ned;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	prew();
	cin>>q;
	for(int i=0;i<q;i++){
		bool fl=0;
		cin>>nm;
		for(int j=1;j<100001;j++){
			if(nms[j]==nm) {
				cout<<j<<endl;
				fl=1;
				break;
			}
		}
		if(fl==0) cout<<"-1"<<endl;
	}
	return 0;
} 
