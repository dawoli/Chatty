#include<bits/stdc++.h>
using namespace std;
int sum1_=0,sum_=0,number_[1000000];
string _s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>_s;
    for(int i=0;i<_s.size();i++)
    {
    	if(_s[i]>='0'&&_s[i]<='9')
    	{
    		number_[sum_]=_s[i]-'0';
    		sum_++;
		}
	}
	sort(number_,number_+sum_);
	for(int i=sum_-1;i>=0;i--)
	    sum1_=sum1_*10+number_[i];
	cout<<sum1_;
	return 0;
} 
