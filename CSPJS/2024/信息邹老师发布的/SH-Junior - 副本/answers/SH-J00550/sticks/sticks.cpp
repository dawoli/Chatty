#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t=0;
	string tt;
	cin>>tt; 
	for(int i=tt.size()-1;i>=0;i--){
		t+=(int(tt[i])-48)*pow(10,i);
	}
	int math[10]={6,2,5,5,4,5,6,3,7,6};
	for(int i=0;i<t;i++){
		int m=0;
	    string mm;
	    cin>>mm; 
	    for(int i=mm.size()-1;i>=0;i--){
	    	m+=(int(mm[i])-48)*pow(10,i);
	    }
	    for(int i=0;i<9;i++){
	    	if(m==math[i]){
	    		cout<<i<<endl;
			}
		}
	}
	return 0;
} 
