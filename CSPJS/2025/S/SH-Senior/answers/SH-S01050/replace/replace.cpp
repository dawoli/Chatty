#include<bits/stdc++.h>
using namespace std;
char shu[10000];
int main(){
	freopen("replace.cpp","r",stdin);
	freopen("replace.cpp","w",stdout);
	int q,n,count;
	char x1,x,y1,y,z1,z,d,d1;
	cin>>n>>q;
	for(int i = 0;i<n*2+1;i++){
		for(int j = 0;j<q;j++){
			cin>>d>>d1;
			char a;
			cin>>a;
			shu[j] = a;
		}
		for(int i = 0;i<n*2+1;i+=2){
			if(shu[i]==d && shu[i+1]==d1) count+=1;
		}
	}
	cout<<count<<endl;
	for(int i =0;i<q-1;i++){
		cout<<0;
	}
}
