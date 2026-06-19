#include <bits/stdc++.h>
using namespace std;
struct student{
	bool tf;
	char sss;
}st[201];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int num=0;
	cin>>num;
	int chongfu=0;
	cin>>st[0].sss>>st[1].sss;
	for(int i=3;i<num*2;i+=2){
		cin>>st[i-1].sss>>st[i].sss;
		st[i-1].tf=false;
		st[i].tf=false;
		for(int j=1;j<i-1;j++){
			if(st[i].sss==st[j].sss&&st[i-1].sss==st[j-1].sss){
				if(st[j-1].tf&&st[j].tf){
					break;
				}
				else if(st[j-1].tf==false&&st[j].tf==false){
					chongfu++;
					st[j-1].tf=true;
					st[j].tf=true;
					break;
				}
			}
		}
	}
	cout<<52-num+chongfu;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
