#include <bits/stdc++.h>
using namespace std;
 
int n,q,s=0;
char st1[1000005],st2[1000005];
long long m=29113331,bes=1;
long long st4,st5;
struct jiegouti{
	long long startx;
	long long presentx;
}st3[2000005];

int main(){
 	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>st1>>st2;
		int llength=strlen(st1);
		int res=llength-1;
		for(int j=0;j<llength;j++){
			if(st1[j]==st2[j])res--;
			else{
				break;}
		}	
		for(int j=llength-1;j>0;j--){
			st4=(st4+st1[j]*bes)%m;
			st5=(st5+st2[j]*bes)%m;
			bes=bes*131%m;
		}
	}
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
