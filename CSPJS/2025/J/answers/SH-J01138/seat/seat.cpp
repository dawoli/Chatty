#include<iostream>
using namespace std;
int main()
{
	int n,m,r,temp,count=1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<(n*m);i++)
	{
		cin>>temp;
		if(temp>r)
			count++;
	}
	if(count==1)
	{
		cout<<"1 1"<<endl;
		return 0;
	}
	int ans_column=1,tmp=1;
	temp=0;
	while(1)
	{
		temp++;
		if(temp==n)
		{
			temp=0;
			ans_column++;
		}
		tmp++;
		if(tmp==count)
			break;
	}
	if(ans_column%2==0)
	{
		cout<<ans_column<<" "<<ans_column*n-count+1;
	}
	else
	{
		cout<<ans_column<<" "<<count-((ans_column-1)*n);
	}
	cout<<endl;
	return 0;
}
