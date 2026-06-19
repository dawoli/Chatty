#include <bits/stdc++.h>
//freopen("poker.in","r","stdin");
//freopen("poker.out","w","stdout");
using namespace std;
int main(){
	int n,cnt=0,h=1;
	cin>>n;
	string a[109];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			for(int j=1;j<i;j++){
				if(a[j]==a[i]){
					h=0;
				}
			}
			if(h==0){
				cnt+=0;
				h=1;
			}else{
				cnt+=1;
			}
		}else{
		    cnt+=1;
		}
	}
	cout<<52-cnt;
	return 0;
}
