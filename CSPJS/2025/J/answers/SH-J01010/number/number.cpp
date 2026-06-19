#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[a.size()];
	for(int i=0;i<a.size();i++){
		b[i]=-1;
		if(a[i]=='0'){
			b[i]=0;
		}
		if(a[i]=='1'){
			b[i]=1;
		}
		if(a[i]=='2'){
			b[i]=2;
		}
		if(a[i]=='3'){
			b[i]=3;
		}
		if(a[i]=='4'){
			b[i]=4;
		}
		if(a[i]=='5'){
			b[i]=5;
		}
		if(a[i]=='6'){
			b[i]=6;
		}
		if(a[i]=='7'){
			b[i]=7;
		}
		if(a[i]=='8'){
			b[i]=8;
		}
		if(a[i]=='9'){
			b[i]=9;
		}
	}
	int sum=0,mus=-1;
	while(1){
		if(b[mus+1]!=-1){
			sum+=1;
		}
		mus+=1;
		if(mus>=a.size()){
			break;
		}
	}
	for(int i=0;i<mus-1;i++){
		for(int j=i;j<mus;j++){
			if(b[i]==-1){
				break;
			}
			if(b[j]==-1){
				continue;
			}
			if(b[i]<b[j]){
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=0;i<mus;i++){
		if(b[i]!=-1){
			cout<<b[i];
		}
	}
}
