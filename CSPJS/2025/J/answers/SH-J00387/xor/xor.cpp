#include<bits/stdc++.h>
using namespace std;
int met=0,sum_[10000005],xor_[500005],n_,k_;
void dfs_(int left_,int right_,int num_,int s_)
{
	if(right_>=n_-1)
	{
		sum_[met]=num_;
		met++;
	}
	else
	{
		if(s_==-1)
		{
			for(int i=left_;i<n_;i++)
				dfs_(i,right_,num_,xor_[i]);
		}
		else
		{
			for(int i=left_;i<n_;i++)
			{
				if(i==left_)
				{
					if(xor_[left_]==k_)
						dfs_(left_+1,left_,num_+1,-1);
				}
				else
				{
					s_|=xor_[i];
					if(s_==k_)
					{
						dfs_(i+1,i,num_+1,-1);
						s_|=xor_[i];	
					}
				}
			}
		}
		
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n_>>k_;
    for(int i=0;i<n_;i++)
        cin>>xor_[i];
    dfs_(0,0,0,-1);
    sort(sum_,sum_+met);
    cout<<sum_[met-1];
	return 0;
} 
