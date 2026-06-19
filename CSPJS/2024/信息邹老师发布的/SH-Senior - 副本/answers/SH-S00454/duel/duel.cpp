#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int ans=n;
	int i;
	int m_list[n+1];
	bool att_list[n+1];
	int max; 
	bool is1=true,is2=true,both12=true;
	for(i=1;i<=n;i++)
	{
		cin>>m_list[i];
		if(m_list[i]!=1)
		{
			is1=false;
			//both12=false;
		}
		if(m_list[i]!=2)
		{
			is2=false;
			//both12=false;
		}
		if((m_list[i]!=1)&&(m_list[i]!=2))
		{
			both12=false;
		}
		if(max<m_list[i])
		{
			max=m_list[i];
		}
		att_list[i]=true;
	}//cin part
	max+=1;//find the biggest
	if((is1==true)||(is2==true))
	{
		cout<<n;
		return 0;
	}
	if(both12==true)
	{
		int num1=0,num2=0;
		for(i=1;i<=n;i++)
		{
			if(m_list[i]==1)
			{
				num1+=1;
			}
			if(m_list[i]==2)
			{
				num2+=1;
			}
		}
		if(num2>=num1)
		{
			cout<<num2;
		}
		else
		{
			cout<<num1;
		}
		return 0;
	}
	
	
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	if(n==2)
	{
		if(m_list[1]==m_list[2])
		{
			cout<<2;
		}
		else
		{
			cout<<1;
		}
	}
	//special thing 2
	
	
	while(true)//main part
	{
		int min1_num,min2_num;
		int min1_val,min2_val;
		min1_num=n+1;
		min2_num=n+1;
		min1_val=max;
		min2_val=max;
		//define
		
		
		
		for(i=1;i<=n;i++)
		{
			if(min1_val>m_list[i])
			{
				/*if(att_list[i]==true)
				{
					min2_val=min1_val;
					min2_num=min1_num;
				}*/
				min1_val=m_list[i];
				min1_num=i;
			}
			/*if((att_list[i]==true)&&(m_list[i]==min1_val+1))
			{
				min2_val=m_list[i];
				min2_num=i;
			}*/
		}
		//find 最小 
		for(i=1;i<=n;i++)
		{
			if(att_list[i]==false)
			{
				continue;
			}
			if(min2_val<=m_list[i])
			{
				continue;
			}
			if(m_list[i]<=min1_val)
			{
				continue;
			}
			min2_val=m_list[i];
			min2_num=i;
			if(min2_val==min1_val+1)
			{
				break;
			}
		}
		//find 第二小 
		
		//找最小和第二小
		
		
		
		 
		if(min2_val==max)
		{
			break;
		}
		/*if(att_list[min1_num]==true)
		{
			ans-=1;
		}*/
		ans-=1;
		att_list[min1_num]=false;
		att_list[min2_num]=false;
		m_list[min1_num]=max;
	}
	cout<<ans;
	
	return 0;
}
