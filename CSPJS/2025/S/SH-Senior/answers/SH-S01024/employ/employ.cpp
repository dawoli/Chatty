#include<bits/stdc++.h>
using namespace std;
const int MAXN=20;
int C[MAXN];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d\n",&n,&m);
	string s;
	getline(cin,s);
	s=" "+s;
	for(int i=1;i<=n;++i)
		scanf("%d",&C[i]);
	if(n==1)//m=1
	{
		if(s[1]=='0')
			printf("%d",0);
		if(s[1]=='1')
			printf("%d",1);
		return 0;
	}
	if(n==2)
		for(int a=1;a<=n;a++)
			for(int b=1;b<=n;b++)
				if(a!=b)
				{
					int p[n+1]={-1,a,b},pre[n+1]={0},k=0;
					bool vis[n+1];
					memset(vis,true,sizeof(vis));
					for(int z=1;z<=n;z++)
					{
						if(s[z]=='0')
						{
							vis[z]=false;
							pre[z+1]=pre[z]+1;
						}
						else
							pre[z+1]=pre[z];
		    		}
					for(int z=1;z<=n;z++)
						if(pre[z]>=C[p[z]])
						{
							if(vis[z])
								for(int y=z+1;y<=n;y++)
									pre[y]++;
							vis[z]=false;
						}
					for(int z=1;z<=n;z++)
			    		if(vis[z])
							k++;
					if(k>=m)
						ans++;
				}
	if(n==3)
		for(int a=1;a<=n;a++)
			for(int b=1;b<=n;b++)
				if(a!=b)
					for(int c=1;c<=n;c++)
						if(c!=a&&c!=b)
						{
							int p[n+1]={-1,a,b,c},pre[n+1]={0},k=0;
							bool vis[n+1];
							memset(vis,true,sizeof(vis));
							for(int z=1;z<=n;z++)
							{
								if(s[z]=='0')
								{
									vis[z]=false;
									pre[z+1]=pre[z]+1;
								}
								else
									pre[z+1]=pre[z];
				    		}
							for(int z=1;z<=n;z++)
								if(pre[z]>=C[p[z]])
								{
									if(vis[z])
										for(int y=z+1;y<=n;y++)
											pre[y]++;
									vis[z]=false;
								}
							for(int z=1;z<=n;z++)
								if(vis[z])
									k++;
							if(k>=m)
								ans++;
						}
	if(n==4)
		for(int a=1;a<=n;a++)
			for(int b=1;b<=n;b++)
				if(a!=b)
					for(int c=1;c<=n;c++)
						if(c!=a&&c!=b)
							for(int d=1;d<=n;d++)
								if(d!=a&&d!=b&&d!=c)
								{
									int p[n+1]={-1,a,b,c,d},pre[n+1]={0},k=0;
									bool vis[n+1];
									memset(vis,true,sizeof(vis));
									for(int z=1;z<=n;z++)
									{
										if(s[z]=='0')
										{
											vis[z]=false;
											pre[z+1]=pre[z]+1;
										}
										else
											pre[z+1]=pre[z];
						    		}
									for(int z=1;z<=n;z++)
										if(pre[z]>=C[p[z]])
										{
											if(vis[z])
												for(int y=z+1;y<=n;y++)
													pre[y]++;
											vis[z]=false;
										}
									for(int z=1;z<=n;z++)
										if(vis[z])
											k++;
									if(k>=m)
										ans++;
								}
	if(n==5)
		for(int a=1;a<=n;a++)
			for(int b=1;b<=n;b++)
				if(a!=b)
					for(int c=1;c<=n;c++)
						if(c!=a&&c!=b)
							for(int d=1;d<=n;d++)
								if(d!=a&&d!=b&&d!=c)
									for(int e=1;e<=n;e++)
										if(e!=a&&e!=b&&e!=c&&e!=d)
										{
											int p[n+1]={-1,a,b,c,d,e},pre[n+1]={0},k=0;
											bool vis[n+1];
											memset(vis,true,sizeof(vis));
											for(int z=1;z<=n;z++)
											{
												if(s[z]=='0')
												{
													vis[z]=false;
													pre[z+1]=pre[z]+1;
												}
												else
													pre[z+1]=pre[z];
								    		}
											for(int z=1;z<=n;z++)
												if(pre[z]>=C[p[z]])
												{
													if(vis[z])
														for(int y=z+1;y<=n;y++)
															pre[y]++;
													vis[z]=false;
												}
											for(int z=1;z<=n;z++)
												if(vis[z])
													k++;
											if(k>=m)
												ans++;
										}
	if(n==6)
		for(int a=1;a<=n;a++)
			for(int b=1;b<=n;b++)
				if(a!=b)
					for(int c=1;c<=n;c++)
						if(c!=a&&c!=b)
							for(int d=1;d<=n;d++)
								if(d!=a&&d!=b&&d!=c)
									for(int e=1;e<=n;e++)
										if(e!=a&&e!=b&&e!=c&&e!=d)
											for(int f=1;f<=n;f++)
												if(f!=a&&f!=b&&f!=c&&f!=d&&f!=e)
												{
													int p[n+1]={-1,a,b,c,d,e,f},pre[n+1]={0},k=0;
													bool vis[n+1];
													memset(vis,true,sizeof(vis));
													for(int z=1;z<=n;z++)
													{
														if(s[z]=='0')
														{
															vis[z]=false;
															pre[z+1]=pre[z]+1;
														}
														else
															pre[z+1]=pre[z];
										    		}
													for(int z=1;z<=n;z++)
														if(pre[z]>=C[p[z]])
														{
															if(vis[z])
																for(int y=z+1;y<=n;y++)
																	pre[y]++;
															vis[z]=false;
														}
													for(int z=1;z<=n;z++)
														if(vis[z])
															k++;
													if(k>=m)
														ans++;
												}
	if(n==7)
		for(int a=1;a<=n;a++)
			for(int b=1;b<=n;b++)
				if(a!=b)
					for(int c=1;c<=n;c++)
						if(c!=a&&c!=b)
							for(int d=1;d<=n;d++)
								if(d!=a&&d!=b&&d!=c)
									for(int e=1;e<=n;e++)
										if(e!=a&&e!=b&&e!=c&&e!=d)
											for(int f=1;f<=n;f++)
												if(f!=a&&f!=b&&f!=c&&f!=d&&f!=e)
													for(int g=1;g<=n;g++)
														if(g!=a&&g!=b&&g!=c&&g!=d&&g!=e&&g!=f)
														{
															int p[n+1]={-1,a,b,c,d,e,f,g},pre[n+1]={0},k=0;
															bool vis[n+1];
															memset(vis,true,sizeof(vis));
															for(int z=1;z<=n;z++)
															{
																if(s[z]=='0')
																{
																	vis[z]=false;
																	pre[z+1]=pre[z]+1;
																}
																else
																	pre[z+1]=pre[z];
															}
															for(int z=1;z<=n;z++)
																if(pre[z]>=C[p[z]])
																{
																	if(vis[z])
																		for(int y=z+1;y<=n;y++)
																			pre[y]++;
																	vis[z]=false;
																}
															for(int z=1;z<=n;z++)
																if(vis[z])
																	k++;
															if(k>=m)
																ans++;
														}
	if(n==8)
		for(int a=1;a<=n;a++)
			for(int b=1;b<=n;b++)
				if(a!=b)
					for(int c=1;c<=n;c++)
						if(c!=a&&c!=b)
							for(int d=1;d<=n;d++)
								if(d!=a&&d!=b&&d!=c)
									for(int e=1;e<=n;e++)
										if(e!=a&&e!=b&&e!=c&&e!=d)
											for(int f=1;f<=n;f++)
												if(f!=a&&f!=b&&f!=c&&f!=d&&f!=e)
													for(int g=1;g<=n;g++)
														if(g!=a&&g!=b&&g!=c&&g!=d&&g!=e&&g!=f)
															for(int h=1;h<=n;h++)
																if(h!=a&&h!=b&&h!=c&&h!=d&&h!=e&&h!=f&&h!=g)
																{
																	int p[n+1]={-1,a,b,c,d,e,f,g,h},pre[n+1]={0},k=0;
																	bool vis[n+1];
																	memset(vis,true,sizeof(vis));
																	for(int z=1;z<=n;z++)
																	{
																		if(s[z]=='0')
																		{
																			vis[z]=false;
																			pre[z+1]=pre[z]+1;
																		}
																		else
																			pre[z+1]=pre[z];
																	}
																	for(int z=1;z<=n;z++)
																		if(pre[z]>=C[p[z]])
																		{
																			if(vis[z])
																				for(int y=z+1;y<=n;y++)
																					pre[y]++;
																			vis[z]=false;
																		}
																	for(int z=1;z<=n;z++)
																		if(vis[z])
																			k++;
																	if(k>=m)
																		ans++;
																}
	if(n==9)
		for(int a=1;a<=n;a++)
			for(int b=1;b<=n;b++)
				if(a!=b)
					for(int c=1;c<=n;c++)
						if(c!=a&&c!=b)
							for(int d=1;d<=n;d++)
								if(d!=a&&d!=b&&d!=c)
									for(int e=1;e<=n;e++)
										if(e!=a&&e!=b&&e!=c&&e!=d)
											for(int f=1;f<=n;f++)
												if(f!=a&&f!=b&&f!=c&&f!=d&&f!=e)
													for(int g=1;g<=n;g++)
														if(g!=a&&g!=b&&g!=c&&g!=d&&g!=e&&g!=f)
															for(int h=1;h<=n;h++)
																if(h!=a&&h!=b&&h!=c&&h!=d&&h!=e&&h!=f&&h!=g)
																	for(int i=1;i<=n;i++)
																		if(i!=a&&i!=b&&i!=c&&i!=d&&i!=e&&i!=f&&i!=g&&i!=h)
																		{
																			int p[n+1]={-1,a,b,c,d,e,f,g,h,i},pre[n+1]={0},k=0;
																			bool vis[n+1];
																			memset(vis,true,sizeof(vis));
																			for(int z=1;z<=n;z++)
																			{
																				if(s[z]=='0')
																				{
																					vis[z]=false;
																					pre[z+1]=pre[z]+1;
																				}
																				else
																					pre[z+1]=pre[z];
																			}
																			for(int z=1;z<=n;z++)
																				if(pre[z]>=C[p[z]])
																				{
																					if(vis[z])
																						for(int y=z+1;y<=n;y++)
																							pre[y]++;
																					vis[z]=false;
																				}
																			for(int z=1;z<=n;z++)
																				if(vis[z])
																					k++;
																			if(k>=m)
																				ans++;
																		}
	if(n==10)
		for(int a=1;a<=n;a++)
			for(int b=1;b<=n;b++)
				if(a!=b)
					for(int c=1;c<=n;c++)
						if(c!=a&&c!=b)
							for(int d=1;d<=n;d++)
								if(d!=a&&d!=b&&d!=c)
									for(int e=1;e<=n;e++)
										if(e!=a&&e!=b&&e!=c&&e!=d)
											for(int f=1;f<=n;f++)
												if(f!=a&&f!=b&&f!=c&&f!=d&&f!=e)
													for(int g=1;g<=n;g++)
														if(g!=a&&g!=b&&g!=c&&g!=d&&g!=e&&g!=f)
															for(int h=1;h<=n;h++)
																if(h!=a&&h!=b&&h!=c&&h!=d&&h!=e&&h!=f&&h!=g)
																	for(int i=1;i<=n;i++)
																		if(i!=a&&i!=b&&i!=c&&i!=d&&i!=e&&i!=f&&i!=g&&i!=h)
																			for(int j=1;j<=n;j++)
																				if(j!=a&&j!=b&&j!=c&&j!=d&&j!=e&&j!=f&&j!=g&&j!=h&&j!=i)
																				{
																					int p[n+1]={-1,a,b,c,d,e,f,g,h,i,j},pre[n+1]={0},k=0;
																					bool vis[n+1];
																					memset(vis,true,sizeof(vis));
																					for(int z=1;z<=n;z++)
																					{
																						if(s[z]=='0')
																						{
																							vis[z]=false;
																							pre[z+1]=pre[z]+1;
																						}
																						else
																							pre[z+1]=pre[z];
																					}
																					for(int z=1;z<=n;z++)
																						if(pre[z]>=C[p[z]])
																						{
																							if(vis[z])
																								for(int y=z+1;y<=n;y++)
																									pre[y]++;
																							vis[z]=false;
																						}
																					for(int z=1;z<=n;z++)
																						if(vis[z])
																							k++;
																					if(k>=m)
																						ans++;
																				}
	if(n>10)
	{
		printf("0");
		return 0;
	}
	printf("%d",ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
