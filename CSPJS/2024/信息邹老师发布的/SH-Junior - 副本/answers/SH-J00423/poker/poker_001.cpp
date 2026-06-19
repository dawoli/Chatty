#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int myn;
	cin>>myn;
	string mystr[100];
	int mycnt=myn;
	for(int i=0;i<myn;i++){
		cin>>mystr[i];
		 for(int j=i-1;j>=0;j--){
		 	if(mystr[i]==mystr[j]){
		 		mycnt--;
		 		break;
			 }
		 }
	}
	 cout<<52-mycnt;
	 return 0;
}
