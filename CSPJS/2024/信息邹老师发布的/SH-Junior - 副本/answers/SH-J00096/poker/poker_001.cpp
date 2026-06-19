#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int pok[5][14],needing=52;
	memset(pok,0,sizeof(pok));
	string a;
	char hs,sz;
	int h,s;
	for(int i=1;i<=n;i++){
		cin>>a;
		hs=a[0];
		sz=a[1];
		if(int(sz)>=48&&int(sz)<=57){
			s=sz-'0';
		}else switch(sz){
			case 'A':{
				s=1; 
				break;
			}
			case 'T':{
				s=10;
				break;
			}
			case 'J':{
				s=11;
				break;
			}
			case 'Q':{
				s=12;
				break;
			}
			case 'K':{
				s=13;
				break;
			}
		}
		switch(hs){
			case 'D':{//·½Æ¬ 
				h=1; 
				break;
			}
			case 'C':{//²Ý»¨ 
				h=2;
				break;
			}
			case 'H':{//ºìÌÒ 
				h=3;
				break;
			}
			case 'S':{//ºÚÌÒ 
				h=4;
				break;
			}
		}
		if(pok[h][s]==0){
			pok[h][s]++;
			needing--;
		}
	}
	cout<<needing;
	return 0;
}
