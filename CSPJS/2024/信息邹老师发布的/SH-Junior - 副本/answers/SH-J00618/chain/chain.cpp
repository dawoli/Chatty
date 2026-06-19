#include<iostream>
#include<cstdio>
struct Node{
	int s[10001];
	int len;
}a[10001];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++){
		int n,k,q;
		std::cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			std::cin>>a[i].len;
			for(int j=0;j<a[i].len;j++)
				std::cin>>a[i].s[j];
		}
		for(int i=1;i<=q;i++){
			int r,c;
			std::cin>>r>>c;
			bool b[10001];
			if(b[r]>0)std::cout<<"1"<<"\n";
			else std::cout<<"0"<<"\n";
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
