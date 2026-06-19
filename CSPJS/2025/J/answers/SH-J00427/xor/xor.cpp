#include <iostream>
int a[10000000],b[10000][10000];
bool c[10000][10000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	std::cin>>n>>k;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=i;j<=n;j++){
	//		b[i][j] = a[i] xor a[j];
	//	}
	//}
	int est=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int result=0;
			for(int i=l;i<=r;i++){
				result=result xor a[i];
			}
			if(result==k){
				est++;
				//std::cout << l << " " << r;
				l=r; 
				break;
			}
		}
	}
	std::cout<<est;
}
