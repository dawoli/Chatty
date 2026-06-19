#include <bits/stdc++.h>
//Deus beat Azertiam
using namespace std;
struct Persona{
	int a,b,c;
	int fallback_secunda,optimum;
	char topia;
};
Persona etx[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int NSF;
	cin>>NSF;
	for(int NSTR=0;NSTR<NSF;NSTR++){
		int pls;
		cin>>pls;
		//cout<<pls<<endl;
		int optiumA=0,optiumB=0,optiumC=0;
		//cout<<"begin"<<endl;
		for(int i=0;i<pls;i++)
		{
			//cout<<i<<endl;
			cin>>etx[i].a>>etx[i].b>>etx[i].c;
			if(etx[i].a>etx[i].b&&etx[i].a>etx[i].c){//a maxium
				if(etx[i].b>etx[i].c){// b 2nd
					etx[i].fallback_secunda=etx[i].a-etx[i].b;
				}else{
					etx[i].fallback_secunda=etx[i].a-etx[i].c;
				}
				optiumA++;
				etx[i].optimum=etx[i].a;
				etx[i].topia='a';
			}else
			if(etx[i].b>etx[i].a&&etx[i].b>etx[i].c){//b maxium
				if(etx[i].c>etx[i].a){// c 2nd
					etx[i].fallback_secunda=etx[i].b-etx[i].c;
				}else{
					etx[i].fallback_secunda=etx[i].b-etx[i].a;
				}
				optiumB++;
				etx[i].optimum=etx[i].b;
				etx[i].topia='b';
			}else{//c maxium
				if(etx[i].b>etx[i].a){// b 2nd
					etx[i].fallback_secunda=etx[i].c-etx[i].b;
				}else{
					etx[i].fallback_secunda=etx[i].c-etx[i].a;
				}
				optiumC++;
				etx[i].optimum=etx[i].c;
				etx[i].topia='c';
			}
			//cout<<"A:"<<etx[i].a<<" B:"<<etx[i].b<<" C:"<<etx[i].c<<" optimum"<<etx[i].optimum<<" fallback"<<etx[i].fallback_secunda<<endl;
		}
		unsigned long long sum=0;
		for(int i=0;i<pls;i++){
			sum+=etx[i].optimum;
		}
		if(optiumA<=pls/2&&optiumB<=pls/2&&optiumC<=pls/2){
			//cout<<"perfect"<<endl;
			cout<<sum<<endl;
		}else if(optiumA>pls/2){
			//cout<<"a exceeded"<<endl;
			vector<int> excessex;
			for(int i=0;i<pls;i++){
				if(etx[i].topia=='a')
				excessex.push_back(etx[i].fallback_secunda);
			}
			sort(excessex.begin(),excessex.end());
			for(int i=0;i<optiumA-pls/2;i++){
				sum-=excessex[i];
				//cout<<"dropped"<<excessex[i]<<endl;
			}
			cout<<sum<<endl;
		}else if(optiumB>pls/2){
			//cout<<"b exceeded"<<endl;
			vector<int> excessex;
			for(int i=0;i<pls;i++){
				if(etx[i].topia=='b')
				excessex.push_back(etx[i].fallback_secunda);
			}
			sort(excessex.begin(),excessex.end());
			for(int i=0;i<optiumB-pls/2;i++){
				sum-=excessex[i];
				//cout<<"dropped"<<excessex[i]<<endl;
			}
			cout<<sum<<endl;
		}
		else if(optiumC>pls/2){
			//cout<<"c exceeded"<<endl;
			vector<int> excessex;
			for(int i=0;i<pls;i++){
				if(etx[i].topia=='c')
				excessex.push_back(etx[i].fallback_secunda);
			}
			sort(excessex.begin(),excessex.end());
			for(int i=0;i<optiumC-pls/2;i++){
				sum-=excessex[i];
				//cout<<"dropped"<<excessex[i]<<endl;
			}
			cout<<sum<<endl;
		}
	}
}
