#include<bits/stdc++.h>
using namespace std;
string p[52];
int main(){
	cin.tie(0);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,l=0;
	bool c;
	string t;
	cin>>n;
	for (int i=0;i<n;i++){
		c=0;
		cin>>t;
	    for(int j=0;j<l;j++){
	    	if(p[j]==t){
	    		c=1;
			}
		}
		if(!c){
		    p[l]=t;
		    l++;
		}
		
	}
	cout<<(52-l);
	return 0;
}
