#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int M,N,Cnt=0;
	cin>>N>>M;
	long long a=M*N;
	int s[a];
	for(int i=1;i<a;i++){
		cin>>s[i];
	}
	for(int i=2;i<a;i++){
		if(s[i]>s[1]){
			Cnt++;
		}
	}
	Cnt++;
	int h=N*2,g=Cnt/N;
	if(Cnt%h==0){
		cout<<g<<" "<<1;
	}
	else if(Cnt%h==N){
		cout<<g<<" "<<N;
	}
	else if(Cnt%h>N){
		cout<<g+1<<" "<<(h-Cnt%h);
	}
	else cout<<g+1<<" "<<Cnt%N;
	return 0;	
	
}
