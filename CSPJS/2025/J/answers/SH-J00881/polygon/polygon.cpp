#include<iostream>
using namespace std;
const int mod=998244353;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		int mx=max(a[1],max(a[2],a[3]));
		if(sum>2*mx)cout<<1;
		else cout<<0;
		fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){//1
		for(int j=i+1;j<=n;j++){//2
			for(int k=j+1;k<=n;k++){//3
				int sum=a[i]+a[j]+a[k];
				int mx=max(a[i],max(a[j],a[k]));
				if(sum>2*mx)ans++;
				ans%=mod;
				for(int q=k+1;q<=n;q++){//4
					int sum=a[i]+a[j]+a[k]+a[q];
					int mx=max(a[i],max(a[j],max(a[k],a[q])));
					if(sum>2*mx)ans++;
					ans%=mod;
					for(int p=q+1;p<=n;p++){//5
						int sum=a[i]+a[j]+a[k]+a[q]+a[p];
						int mx=max(a[i],max(a[j],max(a[k],max(a[q],a[p]))));
						if(sum>2*mx)ans++;
						ans%=mod;
						for(int o=p+1;o<=n;o++){//6
							int sum=a[i]+a[j]+a[k]+a[q]+a[p]+a[o];
							int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],a[o])))));
							if(sum>2*mx)ans++;
							ans%=mod;
							for(int b=o+1;b<=n;b++){//7
								int sum=a[i]+a[j]+a[k]+a[q]+a[p]+a[o]+a[b];
								int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],a[b]))))));
								if(sum>2*mx)ans++;
								ans%=mod;
								for(int c=b+1;c<=n;c++){//8
									int sum=a[i]+a[j]+a[k]+a[q]+a[p]+a[o]+a[b]+a[c];
									int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],a[c])))))));
									if(sum>2*mx)ans++;
									ans%=mod;
									for(int d=c+1;d<=n;d++){//9
										int sum=a[i]+a[j]+a[k]+a[q]+a[p]+a[o]+a[b]+a[c]+a[d];
										int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],a[d]))))))));
										if(sum>2*mx)ans++;
										ans%=mod;
										for(int e=d+1;e<=n;e++){//10
											int sum=a[i]+a[j]+a[k]+a[q]+a[p]+a[o]+a[b]+a[c]+a[d]+a[e];
											int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],a[e])))))))));
											if(sum>2*mx)ans++;
											ans%=mod;
											for(int f=e+1;f<=n;f++){//11
												int sum=a[i]+a[j]+a[k]+a[q]+a[p]+a[o]+a[b]+a[c]+a[d]+a[e]+a[f];
												int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],a[f]))))))))));
												if(sum>2*mx)ans++;
												ans%=mod;
												for(int g=f+1;g<=n;g++){//12
													int sum=a[i]+a[j]+a[k]+a[q]+a[p]+a[o]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g];
													int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],a[g])))))))))));
													if(sum>2*mx)ans++;
													ans%=mod;
													for(int h=g+1;h<=n;h++){//13
														int sum=a[i]+a[j]+a[k]+a[q]+a[p]+a[o]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h];
														int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],a[h]))))))))))));
														if(sum>2*mx)ans++;
														ans%=mod;
														for(int l=h+1;l<=n;l++){//13
															int sum=a[i]+a[j]+a[k]+a[q]+a[p]+a[o]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l];
															int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],a[l])))))))))))));
															if(sum>2*mx)ans++;
															ans%=mod;
															for(int m=l+1;m<=n;m++){//14
																int sum=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]+a[l]+a[m]+a[q]+a[o]+a[p];
																int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],a[m]))))))))))))));
																if(sum>2*mx)ans++;
																ans%=mod;
																for(int r=m+1;r<=n;r++){//15
																	int sum=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]+a[l]+a[m]+a[q]+a[o]+a[p]+a[r];
																	int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],a[r])))))))))))))));
																	if(sum>2*mx)ans++;
																	ans%=mod;
																	for(int s=r+1;s<=n;s++){//16
																		int sum=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]+a[l]+a[m]+a[q]+a[o]+a[p]+a[r]+a[s];
																		int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[r],a[s]))))))))))))))));
																		if(sum>2*mx)ans++;
																		ans%=mod;
																		for(int t=s+1;t<=n;t++){//17
																			int sum=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]+a[l]+a[m]+a[q]+a[o]+a[p]+a[r]+a[s]+a[t];
																			int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[r],max(a[s],a[t])))))))))))))))));
																			if(sum>2*mx)ans++;
																			ans%=mod;
																			for(int u=t+1;u<=n;u++){//18
																				int sum=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]+a[l]+a[m]+a[q]+a[o]+a[p]+a[r]+a[s]+a[t]+a[u];
																				int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[r],max(a[s],max(a[t],a[u]))))))))))))))))));
																				if(sum>2*mx)ans++;
																				ans%=mod;
																				for(int v=u+1;v<=n;v++){//19
																					int sum=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]+a[l]+a[m]+a[q]+a[o]+a[p]+a[r]+a[s]+a[t]+a[u]+a[v];
																					int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[r],max(a[s],max(a[t],max(a[u],a[v])))))))))))))))))));
																					if(sum>2*mx)ans++;
																					ans%=mod;
																					for(int w=v+1;w<=n;w++){//20
																						int sum=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]+a[l]+a[m]+a[q]+a[o]+a[p]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w];
																						int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[r],max(a[s],max(a[t],max(a[u],max(a[v],a[w]))))))))))))))))))));
																						if(sum>2*mx)ans++;
																						ans%=mod;
																						for(int x=w+1;x<=n;x++){//21
																							int sum=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]+a[l]+a[m]+a[q]+a[o]+a[p]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x];
																							int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[r],max(a[s],max(a[t],max(a[u],max(a[v],max(a[w],a[x])))))))))))))))))))));
																							if(sum>2*mx)ans++;
																							ans%=mod;
																							for(int y=x+1;y<=n;y++){//22
																								int sum=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]+a[l]+a[m]+a[q]+a[o]+a[p]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y];
																								int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[r],max(a[s],max(a[t],max(a[u],max(a[v],max(a[w],max(a[x],a[y]))))))))))))))))))))));
																								if(sum>2*mx)ans++;
																								ans%=mod;
																								for(int z=y+1;z<=n;z++){//23
																								    int sum=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z];
																								    int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[r],max(a[s],max(a[t],max(a[u],max(a[v],max(a[w],max(a[x],max(a[y],a[z])))))))))))))))))))))));
																									if(sum>2*mx)ans++;
																									ans%=mod;
																									for(int zzy=z+1;zzy<=n;zzy++){//24 Ð´²»¶¯ÁË 
																										int sum=a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[zzy];
																								    	int mx=max(a[i],max(a[j],max(a[k],max(a[q],max(a[p],max(a[o],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[r],max(a[s],max(a[t],max(a[u],max(a[v],max(a[w],max(a[x],max(a[y],max(a[z],a[zzy]))))))))))))))))))))))));
																										if(sum>2*mx)ans++;
																										ans%=mod;
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
	cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
