#include<bits/stdc++.h>
using namespace std;
int sum1_=0,sum_=0,n_,l_[5005];
void dfs_(int num_,int start_,int num1_,int max_)
{
	if(num1_==num_)
	{
		if(sum1_>max_*2)
			sum_++;	
	}
	else
	{
		for(int i=start_;i<n_;i++)
	    {
			sum1_+=l_[i];
	    	if(l_[i]>max_)
	    	    dfs_(num_,i+1,num1_+1,l_[i]);
	    	else
	    	    dfs_(num_,i+1,num1_+1,max_);
	    	sum1_-=l_[i];
	    }	
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n_;
    for(int i=0;i<n_;i++)
        cin>>l_[i];
    for(int i=3;i<=n_;i++)
    {
        sum1_=0;
		dfs_(i,0,0,0);
	}
    cout<<sum_%998244353;
	return 0;
} 
