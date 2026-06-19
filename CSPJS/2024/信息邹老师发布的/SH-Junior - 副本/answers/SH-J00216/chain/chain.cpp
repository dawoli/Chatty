#include<iostream>
bool a[200001];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	std::cin>>t;
	for(int d=0;d<t;d++){
		int n,k,q;
		std::cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			int l;std::cin>>l;
			for(int j=0;j<l;j++){
				int x;
				std::cin>>x;
				a[x]=true;
			}
		}
		for(int i=0;i<q;i++){
			int c,x;
			std::cin>>c>>x; 
			if(a[x]==false)std::cout<<"0"<<"\n";
			else std::cout<<"1"<<"\n";
		}
	}
	return 0;
}
