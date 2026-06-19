#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5005;
int changshu=998244353;
int a[maxn];
ll pailie(int a,int b)
{
	ll c=1;
	ll d=1;
	for(int i=b;i>=b-a+1;i--)
	{
		c=c*i%changshu;
	}
	for(int i=a;i>=1;i--)
	{
		d=d*i%changshu;
	}
	return c/d;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<0<<endl;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]) cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(a[n]==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=pailie(i,n)%changshu;
		}
		cout<<ans<<endl;
		return 0;
	}
	int d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13,d14,d15,d16,d17,d18,d19,d20;
	for(int i=3;i<=n;i++)
	{
		if(i==3)
		{
			for(d1=1;d1<=n-i+1;d1++)
			{
				for(d2=d1+1;d2<=n-i+2;d2++)
				{
					for(d3=d2+1;d3<=n;d3++)
					{
						if(a[d1]+a[d2]>a[d3]) ans++;
					}
					ans=ans%changshu;
				}
				ans=ans%changshu;
			}
			ans=ans%changshu;
		}
		if(i==4)
		{
			for(d1=1;d1<=n-i+1;d1++)
			{
				for(d2=d1+1;d2<=n-i+2;d2++)
				{
					for(d3=d2+1;d3<=n-i+3;d3++)
					{
						for(d4=d3+1;d4<=n-i+4;d4++)
						{
							if(a[d1]+a[d2]+a[d3]>a[d4]) ans++;
						}
						ans=ans%changshu;
					}
					ans=ans%changshu;
				}
				ans=ans%changshu;
			}
			ans=ans%changshu;
		}
		if(i==5)
		{
			for(d1=1;d1<=n-i+1;d1++)
			{
				for(d2=d1+1;d2<=n-i+2;d2++)
				{
					for(d3=d2+1;d3<=n-i+3;d3++)
					{
						for(d4=d3+1;d4<=n-i+4;d4++)
						{
							for(d5=d4+1;d5<=n-i+5;d5++)
							{
								if(a[d1]+a[d2]+a[d3]+a[d4]>a[d5]) ans++;
							}
							ans=ans%changshu;
						}
						ans=ans%changshu;
					}
					ans=ans%changshu;
				}
				ans=ans%changshu;
			}
			ans=ans%changshu;
		}
		if(i==6)
		{
			for(d1=1;d1<=n-i+1;d1++)
			{
				for(d2=d1+1;d2<=n-i+2;d2++)
				{
					for(d3=d2+1;d3<=n-i+3;d3++)
					{
						for(d4=d3+1;d4<=n-i+4;d4++)
						{
							for(d5=d4+1;d5<=n-i+5;d5++)
							{
								for(d6=d5+1;d6<=n-i+6;d6++)
								{
									if(a[d1]+a[d2]+a[d3]+a[d4]+a[d5]>a[d6]) ans++;
								}
								ans=ans%changshu;
							}
							ans=ans%changshu;
						}
						ans=ans%changshu;
					}
					ans=ans%changshu;
				}
				ans=ans%changshu;
			}
			ans=ans%changshu;
		}
		if(i==7)
		{
			for(d1=1;d1<=n-i+1;d1++)
			{
				for(d2=d1+1;d2<=n-i+2;d2++)
				{
					for(d3=d2+1;d3<=n-i+3;d3++)
					{
						for(d4=d3+1;d4<=n-i+4;d4++)
						{
							for(d5=d4+1;d5<=n-i+5;d5++)
							{
								for(d6=d5+1;d6<=n-i+6;d6++)
								{
									for(d7=d6+1;d7<=n-i+7;d7++)
									{
										if(a[d1]+a[d2]+a[d3]+a[d4]+a[d5]+a[d6]>a[d7]) ans++;
									}
									ans=ans%changshu;
								}
								ans=ans%changshu;
							}
							ans=ans%changshu;
						}
						ans=ans%changshu;
					}
					ans=ans%changshu;
				}
				ans=ans%changshu;
			}
			ans=ans%changshu;
		}
		if(i==8)
		{
			for(d1=1;d1<=n-i+1;d1++)
			{
				for(d2=d1+1;d2<=n-i+2;d2++)
				{
					for(d3=d2+1;d3<=n-i+3;d3++)
					{
						for(d4=d3+1;d4<=n-i+4;d4++)
						{
							for(d5=d4+1;d5<=n-i+5;d5++)
							{
								for(d6=d5+1;d6<=n-i+6;d6++)
								{
									for(d7=d6+1;d7<=n-i+7;d7++)
									{
										for(d8=d7+1;d8<=n-i+8;d8++)
										{
											if(a[d1]+a[d2]+a[d3]+a[d4]+a[d5]+a[d6]+a[d7]>a[d8]) ans++;
										}
										ans=ans%changshu;
									}
									ans=ans%changshu;
								}
								ans=ans%changshu;
							}
							ans=ans%changshu;
						}
						ans=ans%changshu;
					}
					ans=ans%changshu;
				}
				ans=ans%changshu;
			}
			ans=ans%changshu;
		}
		if(i==9)
		{
			for(d1=1;d1<=n-i+1;d1++)
			{
				for(d2=d1+1;d2<=n-i+2;d2++)
				{
					for(d3=d2+1;d3<=n-i+3;d3++)
					{
						for(d4=d3+1;d4<=n-i+4;d4++)
						{
							for(d5=d4+1;d5<=n-i+5;d5++)
							{
								for(d6=d5+1;d6<=n-i+6;d6++)
								{
									for(d7=d6+1;d7<=n-i+7;d7++)
									{
										for(d8=d7+1;d8<=n-i+8;d8++)
										{
											for(d9=d8+1;d9<=n-i+9;d9++)
											{
												if(a[d1]+a[d2]+a[d3]+a[d4]+a[d5]+a[d6]+a[d7]+a[d8]>a[d9]) ans++;
											}
											ans=ans%changshu;
										}
										ans=ans%changshu;
									}
									ans=ans%changshu;
								}
								ans=ans%changshu;
							}
							ans=ans%changshu;
						}
						ans=ans%changshu;
					}
					ans=ans%changshu;
				}
				ans=ans%changshu;
			}
			ans=ans%changshu;
		}
		if(i==10)
		{
			for(d1=1;d1<=n-i+1;d1++)
			{
				for(d2=d1+1;d2<=n-i+2;d2++)
				{
					for(d3=d2+1;d3<=n-i+3;d3++)
					{
						for(d4=d3+1;d4<=n-i+4;d4++)
						{
							for(d5=d4+1;d5<=n-i+5;d5++)
							{
								for(d6=d5+1;d6<=n-i+6;d6++)
								{
									for(d7=d6+1;d7<=n-i+7;d7++)
									{
										for(d8=d7+1;d8<=n-i+8;d8++)
										{
											for(d9=d8+1;d9<=n-i+9;d9++)
											{
												for(d10=d9+1;d10<=n-i+10;d10++)
												{
													if(a[d1]+a[d2]+a[d3]+a[d4]+a[d5]+a[d6]+a[d7]+a[d8]+a[d9]>a[d10]) ans++;
												}
												ans=ans%changshu;
											}
											ans=ans%changshu;
										}
										ans=ans%changshu;
									}
									ans=ans%changshu;
								}
								ans=ans%changshu;
							}
							ans=ans%changshu;
						}
						ans=ans%changshu;
					}
					ans=ans%changshu;
				}
				ans=ans%changshu;
			}
			ans=ans%changshu;
		}
		if(i==11)
		{
			for(d1=1;d1<=n-i+1;d1++)
			{
				for(d2=d1+1;d2<=n-i+2;d2++)
				{
					for(d3=d2+1;d3<=n-i+3;d3++)
					{
						for(d4=d3+1;d4<=n-i+4;d4++)
						{
							for(d5=d4+1;d5<=n-i+5;d5++)
							{
								for(d6=d5+1;d6<=n-i+6;d6++)
								{
									for(d7=d6+1;d7<=n-i+7;d7++)
									{
										for(d8=d7+1;d8<=n-i+8;d8++)
										{
											for(d9=d8+1;d9<=n-i+9;d9++)
											{
												for(d10=d9+1;d10<=n-i+10;d10++)
												{
													for(d11=d10+1;d11<=n-i+11;d11++)
													{
														if(a[d1]+a[d2]+a[d3]+a[d4]+a[d5]+a[d6]+a[d7]+a[d8]+a[d9]+a[d10]>a[d11]) ans++;
													}
													ans=ans%changshu;
												}
												ans=ans%changshu;
											}
											ans=ans%changshu;
										}
										ans=ans%changshu;
									}
									ans=ans%changshu;
								}
								ans=ans%changshu;
							}
							ans=ans%changshu;
						}
						ans=ans%changshu;
					}
					ans=ans%changshu;
				}
				ans=ans%changshu;
			}
			ans=ans%changshu;
		}
	}
	cout<<ans<<endl;
	return 0;
}
