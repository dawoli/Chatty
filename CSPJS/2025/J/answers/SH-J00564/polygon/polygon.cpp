#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int w=0;w<n-17;w++){
		for(int p=0;p<n-16;p++){
			for(int q=0;q<n-15;q++){
				for(int d=0;d<n-14;d++){
					for(int b=0;b<n-13;b++){
						for(int o=0;o<n-12;o++){
							for(int v=0;v<n-11;v++){
								for(int u=0;u<n-10;u++){
									for(int e=u+1;e<n-9;e++){
										for(int h=e+1;h<n-8;h++){
											for(int t=h+1;t<n-7;t++){
												for(int f=t+1;f<n-6;f++){
													for(int c=f+1;c<n-5;c++){
														for(int g=c+1;g<n-4;g++){
															for(int y=g+1;y<n-3;y++){
																for(int i=y+1;i<n-2;i++){
																	for(int j=i+1;j<n-1;j++){
																		for(int x=j+1;x<n;x++){
																			if(a[w]+a[p]+a[q]+a[c]+a[b]+a[o]+a[v]+a[u]+a[e]+a[h]+a[t]+a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[w],max(a[p],max(a[q],max(a[c],max(a[b],max(a[o],max(a[v],max(a[u],max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],max(a[f],max(a[t],max(a[e],a[h])))))))))))))))))){
																				ans++;
																				ans%=998244353;
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
	for(int p=0;p<n-16;p++){
		for(int q=0;q<n-15;q++){
			for(int d=0;d<n-14;d++){
				for(int b=0;b<n-13;b++){
					for(int o=0;o<n-12;o++){
						for(int v=0;v<n-11;v++){
							for(int u=0;u<n-10;u++){
								for(int e=u+1;e<n-9;e++){
									for(int h=e+1;h<n-8;h++){
										for(int t=h+1;t<n-7;t++){
											for(int f=t+1;f<n-6;f++){
												for(int c=f+1;c<n-5;c++){
													for(int g=c+1;g<n-4;g++){
														for(int y=g+1;y<n-3;y++){
															for(int i=y+1;i<n-2;i++){
																for(int j=i+1;j<n-1;j++){
																	for(int x=j+1;x<n;x++){
																		if(a[p]+a[q]+a[c]+a[b]+a[o]+a[v]+a[u]+a[e]+a[h]+a[t]+a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[p],max(a[q],max(a[c],max(a[b],max(a[o],max(a[v],max(a[u],max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],max(a[f],max(a[t],max(a[e],a[h]))))))))))))))))){
																			ans++;
																			ans%=998244353;
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
	for(int q=0;q<n-15;q++){
		for(int d=0;d<n-14;d++){
			for(int b=0;b<n-13;b++){
				for(int o=0;o<n-12;o++){
					for(int v=0;v<n-11;v++){
						for(int u=0;u<n-10;u++){
							for(int e=u+1;e<n-9;e++){
								for(int h=e+1;h<n-8;h++){
									for(int t=h+1;t<n-7;t++){
										for(int f=t+1;f<n-6;f++){
											for(int c=f+1;c<n-5;c++){
												for(int g=c+1;g<n-4;g++){
													for(int y=g+1;y<n-3;y++){
														for(int i=y+1;i<n-2;i++){
															for(int j=i+1;j<n-1;j++){
																for(int x=j+1;x<n;x++){
																	if(a[q]+a[c]+a[b]+a[o]+a[v]+a[u]+a[e]+a[h]+a[t]+a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[q],max(a[c],max(a[b],max(a[o],max(a[v],max(a[u],max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],max(a[f],max(a[t],max(a[e],a[h])))))))))))))))){
																		ans++;
																		ans%=998244353;
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
	for(int d=0;d<n-14;d++){
		for(int b=0;b<n-13;b++){
			for(int o=0;o<n-12;o++){
				for(int v=0;v<n-11;v++){
					for(int u=0;u<n-10;u++){
						for(int e=u+1;e<n-9;e++){
							for(int h=e+1;h<n-8;h++){
								for(int t=h+1;t<n-7;t++){
									for(int f=t+1;f<n-6;f++){
										for(int c=f+1;c<n-5;c++){
											for(int g=c+1;g<n-4;g++){
												for(int y=g+1;y<n-3;y++){
													for(int i=y+1;i<n-2;i++){
														for(int j=i+1;j<n-1;j++){
															for(int x=j+1;x<n;x++){
																if(a[c]+a[b]+a[o]+a[v]+a[u]+a[e]+a[h]+a[t]+a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[c],max(a[b],max(a[o],max(a[v],max(a[u],max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],max(a[f],max(a[t],max(a[e],a[h]))))))))))))))){
																	ans++;
																	ans%=998244353;
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
	for(int b=0;b<n-13;b++){
		for(int o=0;o<n-12;o++){
			for(int v=0;v<n-11;v++){
				for(int u=0;u<n-10;u++){
					for(int e=u+1;e<n-9;e++){
						for(int h=e+1;h<n-8;h++){
							for(int t=h+1;t<n-7;t++){
								for(int f=t+1;f<n-6;f++){
									for(int c=f+1;c<n-5;c++){
										for(int g=c+1;g<n-4;g++){
											for(int y=g+1;y<n-3;y++){
												for(int i=y+1;i<n-2;i++){
													for(int j=i+1;j<n-1;j++){
														for(int x=j+1;x<n;x++){
															if(a[b]+a[o]+a[v]+a[u]+a[e]+a[h]+a[t]+a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[b],max(a[o],max(a[v],max(a[u],max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],max(a[f],max(a[t],max(a[e],a[h])))))))))))))){
																ans++;
																ans%=998244353;
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
	for(int o=0;o<n-12;o++){
		for(int v=0;v<n-11;v++){
			for(int u=0;u<n-10;u++){
				for(int e=u+1;e<n-9;e++){
					for(int h=e+1;h<n-8;h++){
						for(int t=h+1;t<n-7;t++){
							for(int f=t+1;f<n-6;f++){
								for(int c=f+1;c<n-5;c++){
									for(int g=c+1;g<n-4;g++){
										for(int y=g+1;y<n-3;y++){
											for(int i=y+1;i<n-2;i++){
												for(int j=i+1;j<n-1;j++){
													for(int x=j+1;x<n;x++){
														if(a[o]+a[v]+a[u]+a[e]+a[h]+a[t]+a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[o],max(a[v],max(a[u],max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],max(a[f],max(a[t],max(a[e],a[h]))))))))))))){
															ans++;
															ans%=998244353;
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
	for(int v=0;v<n-11;v++){
		for(int u=0;u<n-10;u++){
			for(int e=u+1;e<n-9;e++){
				for(int h=e+1;h<n-8;h++){
					for(int t=h+1;t<n-7;t++){
						for(int f=t+1;f<n-6;f++){
							for(int c=f+1;c<n-5;c++){
								for(int g=c+1;g<n-4;g++){
									for(int y=g+1;y<n-3;y++){
										for(int i=y+1;i<n-2;i++){
											for(int j=i+1;j<n-1;j++){
												for(int x=j+1;x<n;x++){
													if(a[v]+a[u]+a[e]+a[h]+a[t]+a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[v],max(a[u],max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],max(a[f],max(a[t],max(a[e],a[h])))))))))))){
														ans++;
														ans%=998244353;
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
	for(int u=0;u<n-10;u++){
		for(int e=u+1;e<n-9;e++){
			for(int h=e+1;h<n-8;h++){
				for(int t=h+1;t<n-7;t++){
					for(int f=t+1;f<n-6;f++){
						for(int c=f+1;c<n-5;c++){
							for(int g=c+1;g<n-4;g++){
								for(int y=g+1;y<n-3;y++){
									for(int i=y+1;i<n-2;i++){
										for(int j=i+1;j<n-1;j++){
											for(int x=j+1;x<n;x++){
												if(a[u]+a[e]+a[h]+a[t]+a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[u],max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],max(a[f],max(a[t],max(a[e],a[h]))))))))))){
													ans++;
													ans%=998244353;
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
	for(int e=0;e<n-9;e++){
		for(int h=e+1;h<n-8;h++){
			for(int t=h+1;t<n-7;t++){
				for(int f=t+1;f<n-6;f++){
					for(int c=f+1;c<n-5;c++){
						for(int g=c+1;g<n-4;g++){
							for(int y=g+1;y<n-3;y++){
								for(int i=y+1;i<n-2;i++){
									for(int j=i+1;j<n-1;j++){
										for(int x=j+1;x<n;x++){
											if(a[e]+a[h]+a[t]+a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],max(a[f],max(a[t],max(a[e],a[h])))))))))){
												ans++;
												ans%=998244353;
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
	for(int h=0;h<n-8;h++){
		for(int t=h+1;t<n-7;t++){
			for(int f=t+1;f<n-6;f++){
				for(int c=f+1;c<n-5;c++){
					for(int g=c+1;g<n-4;g++){
						for(int y=g+1;y<n-3;y++){
							for(int i=y+1;i<n-2;i++){
								for(int j=i+1;j<n-1;j++){
									for(int x=j+1;x<n;x++){
										if(a[h]+a[t]+a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],max(a[f],max(a[t],a[h]))))))))){
											ans++;
											ans%=998244353;
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
	for(int t=0;t<n-7;t++){
		for(int f=t+1;f<n-6;f++){
			for(int c=f+1;c<n-5;c++){
				for(int g=c+1;g<n-4;g++){
					for(int y=g+1;y<n-3;y++){
						for(int i=y+1;i<n-2;i++){
							for(int j=i+1;j<n-1;j++){
								for(int x=j+1;x<n;x++){
									if(a[t]+a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],max(a[f],a[t])))))))){
										ans++;
										ans%=998244353;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int f=0;f<n-6;f++){
		for(int c=f+1;c<n-5;c++){
			for(int g=c+1;g<n-4;g++){
				for(int y=g+1;y<n-3;y++){
					for(int i=y+1;i<n-2;i++){
						for(int j=i+1;j<n-1;j++){
							for(int x=j+1;x<n;x++){
								if(a[f]+a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],max(a[c],a[f]))))))){
									ans++;
									ans%=998244353;
								}
							}
						}
					}
				}
			}
		}
	}
	for(int c=0;c<n-5;c++){
		for(int g=c+1;g<n-4;g++){
			for(int y=g+1;y<n-3;y++){
				for(int i=y+1;i<n-2;i++){
					for(int j=i+1;j<n-1;j++){
						for(int x=j+1;x<n;x++){
							if(a[c]+a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[x],max(a[j],max(a[i],max(a[y],max(a[g],a[c])))))){
								ans++;
								ans%=998244353;
							}
						}
					}
				}
			}
		}
	}
	for(int g=0;g<n-4;g++){
		for(int y=g+1;y<n-3;y++){
			for(int i=y+1;i<n-2;i++){
				for(int j=i+1;j<n-1;j++){
					for(int x=j+1;x<n;x++){
						if(a[g]+a[y]+a[i]+a[j]+a[x]>2*max(a[x],max(a[j],max(a[i],max(a[y],a[g]))))){
							ans++;
							ans%=998244353;
						}
					}
				}
			}
		}
	}
	for(int y=0;y<n-3;y++){
		for(int i=y+1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int x=j+1;x<n;x++){
					if(a[y]+a[i]+a[j]+a[x]>2*max(a[x],max(a[j],max(a[i],a[y])))){
						ans++;
						ans%=998244353;
					}
				}
			}
		}
	}
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int x=j+1;x<n;x++){
				if(a[i]+a[j]+a[x]>2*max(a[x],max(a[j],a[i]))){
					ans++;
					ans%=998244353;
				}
			}
		}
	}cout<<ans;
	return 0;
}
