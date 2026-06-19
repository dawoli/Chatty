#include<bits/stdc++.h>
using namespace std;
int search_,research_,seat_[105],sum_=0,n_,m_;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n_>>m_;
    for(int i=0;i<n_;i++)
    {
    	for(int j=0;j<m_;j++)
    	{
    		cin>>seat_[sum_];
    		sum_++;
    		if(sum_==1)
    		    research_=seat_[sum_-1];
		}
	}
	sort(seat_,seat_+sum_);
	for(int i=sum_-1;i>=0;i--)
	{
		if(seat_[i]==research_)
		    search_=sum_-i;
	}
    cout<<search_/(n_+1)+1<<" ";	
	if((search_/(n_+1)+1)%2==0)
	    cout<<m_-search_%n_+1;
	else
	    cout<<search_%(n_+1);
	return 0;
} 
