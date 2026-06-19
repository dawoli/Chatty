#include<bits/stdc++.h>
using namespace std;
const int N=14;
int visS[N],visH[N],visD[N],visC[N];
int n;
int cnt;
char co;
char nu;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>co>>nu;
    	int m;
    	if(nu<='9')m=nu-'0';
    	else{
    		if(nu=='T')m=10;
    		if(nu=='J')m=11;
    		if(nu=='Q')m=12;
    		if(nu=='K')m=13;
    		if(nu=='A')m=1;
		}
    	if(co=='S'){
    		visS[m]++;
    		if(visS[m]==1)cnt++;
		}
		if(co=='H'){
    		visH[m]++;
    		if(visH[m]==1)cnt++;
		}
		if(co=='D'){
    		visD[m]++;
    		if(visD[m]==1)cnt++;
		}
		if(co=='C'){
    		visC[m]++;
    		if(visC[m]==1)cnt++;
		}
	}
	cout<<52-cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
