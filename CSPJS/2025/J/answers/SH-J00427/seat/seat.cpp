#include <iostream>
long long a[10000000],s[1000][1000];
bool ch=false;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,r;
	std::cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		std::cin>>a[i];
	}
	long long i=1;
	r=a[1];
	while(true){
		if(a[i]<a[i+1]){
			long long c=a[i];
			a[i]=a[i+1];
			a[i+1]=c;
			ch=true;
		}
		i++;
		if(i==n*m){
			i=1;
			if(!ch)break;
			else ch=false;
		}
	}
	long long num=1;
	for(long long i=1;i<=m;i++){
		if(i%2==0){
			for(long long j=n;j>=1;j--){
				if(a[num]==r){
					std::cout<<i<<' '<<j;
					return 0;
				}
				s[j][i]=a[num];
				num++;
			}
		}
		else{
			for(long long j=1;j<=n;j++){
				if(a[num]==r){
					std::cout<<i<<' '<<j;
					return 0;
				}
				s[j][i]=a[num];
				num++;
			}
		}
		
	}
	return 0;
}
