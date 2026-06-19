#include <bits/stdc++.h>
using namespace std;

bool solvee(int n,vector<int> &a)
{
	return false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	vector<int> a(n+1,0);
	for(int i = 1;i<= n;i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			for(int k = j+1;k <= n;k++){
				if((a[i]+a[j] + a[k]) > max(max(a[i],a[j]),a[k]) * 2){
					cnt++;
					//cout << a[i] << ' ' << a[j] << ' ' << a[k] << endl;
				} 
				if(n >= 4){
					for(int g = k+1;g <= n;g++){
					 	if(a[i]+a[j]+a[k] + a[g] > max(max(max(a[i],a[j]),a[k]),a[g]) * 2){
					 		cnt++;
						}
						if(n >= 5){
							for(int gg = g + 1;gg <= n;gg++){
								if(a[i] + a[j] + a[k] +a[g] + a[gg] > max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]) * 2){
									cnt++;
								}
								if(n >= 6){
									for(int ggg = gg + 1;ggg <= n;ggg++){
										if(a[i] + a[j] + a[k] +a[g] + a[gg] +a[ggg]> max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) * 2){
												cnt++;
										if(n >= 7){
											for(int gggg = ggg + 1;gggg <= n;gggg++){
												if(a[i] + a[j] + a[k] +a[g] + a[gg] +a[ggg] + a[gggg]> max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,a[gggg]) * 2){
													cnt++;
												}
												if(n >= 8){
													for(int s = gggg + 1;s <= n;s++){
														if(a[i] + a[j] + a[k] +a[g] + a[gg] +a[ggg] + a[gggg] + a[s]> max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])) * 2){
															cnt++;
														}
														if(n >= 9){
															for(int b = s+1;b <= n;b++){
																if(a[i] + a[j] + a[k] +a[g] + a[gg] +a[ggg] + a[gggg] + a[s] +a[b]> max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]) * 2){
																	cnt++;
																}	
																if(n >= 10){
																	for(int df = b+1;df <= n;df++){
																		if(a[i] + a[j] + a[k] +a[g] + a[gg] +a[ggg] + a[gggg] + a[s] +a[b] + a[df]> max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]),a[df]) * 2){
																			cnt++;
																		}
																		if(n >= 11){
																			for(int dfs = df+1;dfs <= n;dfs++){
																				if(a[i] + a[j] + a[k] +a[g] + a[gg] +a[ggg] + a[gggg] + a[s] +a[b] + a[df]+a[dfs]> max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]),a[df]),a[dfs]) * 2){
																					cnt++;
																				}
																				if(n >= 12){
																					for(int xmt = dfs+1;xmt <= n;xmt++)	{
																						if(a[i] + a[j] + a[k] +a[g] + a[gg] +a[ggg] + a[gggg] + a[s] +a[b] + a[df]+a[dfs]+a[xmt]> max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]),a[df]),a[dfs]) ,a[xmt])* 2){                                                                               
																							cnt++;
																						}
																						if(n >= 13){
																							for(int pp = xmt+1;pp <= n;pp++)	{
																								if(a[i] + a[j] + a[k] +a[g] +a[pp]+ a[gg] +a[ggg] + a[gggg] + a[s] +a[b] + a[df]+a[dfs]+a[xmt]> max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]),a[df]),max(a[pp],a[dfs]) ),a[xmt])* 2){                                                                               
																									cnt++;
																								}
																								if(n >= 14){
																									for(int ppp = pp+1;ppp <= n;ppp++)	{
																										if(a[i] + a[j] + a[k] +a[g] +a[ppp]+a[pp]+ a[gg] +a[ggg] + a[gggg] + a[s] +a[b] + a[df]+a[dfs]+a[xmt]> max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]),a[df]),max(a[pp],max(a[dfs], a[ppp]) )),a[xmt])* 2){                                                                               
																											cnt++;
																										}
																										if(n >= 15){
																											for(int pppp = ppp+1;pppp <= n;pppp++)	{
																												if(a[i] + a[j] + a[k] +a[g] +a[ppp] + a[pppp]+a[pp]+ a[gg] +a[ggg] + a[gggg] + a[s] +a[b] + a[df]+a[dfs]+a[xmt]> max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]),a[df]),max(a[pp],max(a[dfs], max(a[ppp],a[pppp]) )  )),a[xmt])* 2){                                                                               
																													cnt++;
																												}
																												if(n >= 16){
																													for(int ppppp = pppp+1;ppppp <= n;ppppp++)	{
																														if(a[i] + a[j] + a[k] +a[g] +a[ppp] +a[ppppp]+ a[pppp]+a[pp]+ a[gg] +a[ggg] + a[gggg] + a[s] +a[b] + a[df]+a[dfs]+a[xmt]> max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]),a[df]),max(a[pp],max(a[dfs], max(a[ppp],max(a[ppppp],a[pppp]) ) ) )),a[xmt])* 2){                                                                               
																															cnt++;
																														}
																														if(n >= 17){
																															for(int oppo = ppppp+1;oppo <= n;oppo++)	{
																																if(a[i] +a[oppo]+ a[j] + a[k] +a[g] +a[ppp] +a[ppppp]+ a[pppp]+a[pp]+ a[gg] +a[ggg] + a[gggg] + a[s] +a[b] + a[df]+a[dfs]+a[xmt]> max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]),a[df]),max(a[pp],max(a[dfs], max(a[ppp],max(a[ppppp],max(a[oppo],a[pppp])))))),a[xmt])* 2){                                                                               
																																	cnt++;
																																}
																																if(n >= 18){
																																	for(int opppo = oppo+1;opppo <= n;opppo++)	{
																																		if(a[i] +a[oppo]+ a[j] + a[k] +a[g] + a[opppo]+a[ppp] +a[ppppp]+ a[pppp]+a[pp]+ a[gg] +a[ggg] + a[gggg] + a[s] +a[b] + a[df]+a[dfs]+a[xmt]> max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]),a[df]),max(a[pp],max(a[dfs], max(a[ppp],max(a[ppppp],max(a[oppo],max(a[opppo],a[pppp]))))))),a[xmt])* 2){                                                                               
																																			cnt++;
																																		}
																																		if(n >= 19){
																																			for(int oppppo = opppo+1;oppppo <= n;oppppo++)	{
																																				if(a[i] +a[oppo]+a[oppppo]+ a[j] + a[k] +a[g] + a[opppo]+a[ppp] +a[ppppp]+ a[pppp]+a[pp]+ a[gg] +a[ggg] + a[gggg] + a[s] +a[b] + a[df]+a[dfs]+a[xmt]> max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]),a[df]),max(a[pp],max(a[dfs], max(a[ppp],max(a[ppppp],max(a[oppo],max(a[opppo],max(a[oppppo],a[pppp])))))))),a[xmt])* 2){                                                                               
																																					cnt++;
																																				}
																																				if(n >= 20){
																																					for(int opppppo = oppppo+1;opppppo <= n;opppppo++)	{
																																						if(a[i] +a[oppo]+a[oppppo]+ a[j] + a[k] +a[g] +a[opppppo]+ a[opppo]+a[ppp] +a[ppppp]+ a[pppp]+a[pp]+ a[gg] +a[ggg] + a[gggg] + a[s] +a[b] + a[df]+a[dfs]+a[xmt]> max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[g]),a[gg]),a[ggg]) ,max(a[gggg],a[s])),a[b]),a[df]),max(a[pp],max(a[dfs], max(a[ppp],max(a[ppppp],max(a[oppo],max(a[opppo],max(max(a[oppppo],a[opppppo]),a[pppp])))))))),a[xmt])* 2){                                                                               
																																							cnt++;
																																						}	
																																					}
																																				}
																																			}																																			
																																		}
																																	}																																	
																																}
																															}																															
																														}
																													}																														
																												}
																											}																											
																										}
																									}																									
																								}
																							}																							
																						}
																					}																					
																				}
																			}
																		}
																	}																								
																}
															}
														}											
													}
												}												
											}
										}
									}
								}
							}
						}
					}
				}
			 }
		}
	}
	}
	cout << cnt;
	return 0;
}


















/*********************************************************************************************************************************************************
||          			|       |																				| 		|                          0485000
            			|       |																				| 		|
						|		|																				| 		|
            			|       |																				| 		|
            			|       |																				| 		|
						|		|																				| 		|
            			|       |																				| 		|
            			|       |																				| 		|
						|		|																				| 		|
            			|       |																				|  		|
            			|       |																				|		|
						|		|																				|		|  	
            			|       |																				|		|
						|		|																				|		|
            			|       |																				|		|
            			|       |																				|		|
						|		|																				|		|
            			|       |																				|		|
            			|       |																				|		|
						|		|																				|		|
            			|       |																				|		|
            			|       |																				|		|
						|		|																				|		|
            			|       |																				|		|
            			|       |																				|		|
						|		|																				|		|
            			|       |																				|		|
            			|       |																				|		|
						|		|																				|		|
						---------																				---------

___________________________________________________________________________________________________________________________________________________________

dataerror                                                                                                                                          EZ LV.5
**********************************************************************************************************************************************************/
