#include<iostream>
using namespace std;

long long N; 
long long n;
long long a[1000006];
long long an;
int main(){
	
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>N;
	while(N--){	
		cin>>n;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			a[x]++;
		}
		for(int i=1;i<1000006;i++){
			if(a[i]>=2){
				an=an+(a[i]-1)*i;
			}
		}
		cout<<an<<endl;
		for(int i=1;i<1000006;i++){
			a[i]=0;
		}
		an=0;
	}
	return 0;
} 
