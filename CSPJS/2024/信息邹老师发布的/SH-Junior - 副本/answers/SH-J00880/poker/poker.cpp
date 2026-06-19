#include<iostream>
#include<string>
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	std::cin>>n;
	int b=0;
	std::string a[53];
	for(int i=0;i<n;i++){
		std::cin>>a[i];
    }  
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]==a[j]&&i!=j&&a[j]!="0"&&a[i]!="0"){
				b++;
				a[j]="0";	
			}
		}
	}
	std::cout<<52-n+b;
    return 0;
}
