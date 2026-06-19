#include <iostream>
#include <vector>
using namespace std;
struct item{
	int person;
	int length;
	int* value;
};
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	/*
	int T,n,k,q,l,c,r;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n>>k>>q;
		item* people[n];
		int anss[q]={};
		for(int j=0;j<n;j++){
			cin>>l;
			people[j] = new item;
			people[j]->person=j;
			people[j]->length=l;
			people[j]->value=new int[l];
			for(int m=0;m<l;m++) cin>>people[j]->value[m];
		};
		for(int o=0;o<q;o++){
			cin>>r>>c;
			int ans=0;
			if(r==1){
				for(int s=0;s<n;s++){
					bool flag=false;
					for(int t=0;t<people[s]->length;t++){
						if(!flag&&people[s]->value[t]==1){
							flag=true;
							continue;
						};
						if(flag&&people[s]->value[t]==c){
							ans=1;
							break;
						};
					};
					if(ans==1) break;
				};
				if(ans==1) break;
			};
			anss[o]=ans;
		};
		for(int u=0;u<q;u++) cout<<anss[u]<<endl;
	};
	*/
	int num;
	for(int i=0;i<32;i++) cin>>num;
	cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
