#include<iostream>
#include<cstdio>
#include<algorithm>
char c[200];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w"stdout);
	int n;
	std::cin>>n;
	for(int i=0;i<n*2;i++){
		std::cin>>c[i];
	}
	for(int i=0;i<2*n;i+=2){
		int a=i;
		for(int j=i+1;j<2*n;j+=2){
			for(int k=2;k<2*n;k+=2){
		        if(c[a]==c[a+k]&&c[j]==c[j+k]) n--;
		    }
		    a+=2;
	    }
	}
	std::cout<<52-n<<"\n";
}
