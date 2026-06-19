#include<iostream>
using namespace std;
int n,k;
struct poker
{
	char c1;
	char v;
};
int main() 
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	poker p1[55];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		k++;
		cin>>p1[k].c1>>p1[k].v;
		for(int j=1;j<k;j++)
			if(p1[j].c1==p1[k].c1 && p1[j].v==p1[k].v)
			{
				k--;
				break;
			}		
	}
	cout<<52-k<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
