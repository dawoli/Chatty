#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int l=1;l<=T;l++){
		int n;
		cin>>n;
		int k=n/42;
		n=n%42;
		if(k>0){
			if(n%7==1) cout<<"1088888";
			if(n%7==2) cout<<"1888888";
			if(n%7==3) cout<<"2288888";
			if(n%7==4) cout<<"2088888";
			if(n%7==5) cout<<"2888888";
			if(n%7==6) cout<<"6888888";
			int m=n/7;
			for(int i=1;i<=m;i++) cout<<"8";
			for(int i=1;i<k;i++) cout<<"888888";
		}
		else{
			if(n==1) cout<<"-1";
			if(n==2) cout<<"1";
			if(n==3) cout<<"7";
			if(n==4) cout<<"4";
			if(n==5) cout<<"2";
			if(n==6) cout<<"6";
			if(n==7) cout<<"8";
			if(n==8) cout<<"10";
			if(n==9) cout<<"18";
			if(n==10) cout<<"22";
			if(n==11) cout<<"20";
			if(n==12) cout<<"28";
			if(n==13) cout<<"68";
			if(n==14) cout<<"88";
			if(n==15) cout<<"108";
			if(n==16) cout<<"188";
			if(n==17) cout<<"200";
			if(n==18) cout<<"208";
			if(n==19) cout<<"288";
			if(n==20) cout<<"688";
			if(n==21) cout<<"888";
			if(n==22) cout<<"1088";
			if(n==23) cout<<"1888";
			if(n==24) cout<<"2008";
			if(n==25) cout<<"2088";
			if(n==26) cout<<"2888";
			if(n==27) cout<<"6888";
			if(n==28) cout<<"8888";
			if(n==29) cout<<"10888";
			if(n==30) cout<<"18888";
			if(n==31) cout<<"20088";
			if(n==32) cout<<"20888";
			if(n==33) cout<<"28888";
			if(n==34) cout<<"68888";
			if(n==35) cout<<"88888";
			if(n==36) cout<<"108888";
			if(n==37) cout<<"188888";
			if(n==38) cout<<"200888";
			if(n==39) cout<<"208888";
			if(n==40) cout<<"288888";
			if(n==41) cout<<"688888";
		}
		if(l!=T) cout<<endl;
	}
	return 0;
}
