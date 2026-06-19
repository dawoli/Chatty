#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long int cnt=0;
	if(n==3){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
						cnt++;
					}
				}
			}
		}
	}
	else if(n==4){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					for(int q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>max({a[i],a[j],a[k],a[q]})*2){
							cnt++;
						}
					}
				}
			}
		}
	}
	else if(n==5){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					for(int q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>max({a[i],a[j],a[k],a[q]})*2){
							cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int q=k+1;q<n;q++){
						for(int o=q+1;o<=n;o++){
							if(a[i]+a[j]+a[k]+a[q]+a[o]>max({a[i],a[j],a[k],a[q],a[o]})*2){
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	else if(n==6){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					for(int q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>max({a[i],a[j],a[k],a[q]})*2){
							cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int q=k+1;q<n;q++){
						for(int o=q+1;o<=n;o++){
							if(a[i]+a[j]+a[k]+a[q]+a[o]>max({a[i],a[j],a[k],a[q],a[o]})*2){
								cnt++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int q=k+1;q<n-1;q++){
						for(int o=q+1;o<n;o++){
							for(int p=o+1;p<=n;p++){
								if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]>max({a[i],a[j],a[k],a[q],a[o],a[p]})*2){
									cnt++;
								}
							}
						}
					}
				}
			}
		}
	}
	else if(n==7){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					for(int q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>max({a[i],a[j],a[k],a[q]})*2){
							cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int q=k+1;q<n;q++){
						for(int o=q+1;o<=n;o++){
							if(a[i]+a[j]+a[k]+a[q]+a[o]>max({a[i],a[j],a[k],a[q],a[o]})*2){
								cnt++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int q=k+1;q<n-1;q++){
						for(int o=q+1;o<n;o++){
							for(int p=o+1;p<=n;p++){
								if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]>max({a[i],a[j],a[k],a[q],a[o],a[p]})*2){
									cnt++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-5;i++){
			for(int j=i+1;j<n-4;j++){
				for(int k=j+1;k<n-3;k++){
					for(int q=k+1;q<n-2;q++){
						for(int o=q+1;o<n-1;o++){
							for(int p=o+1;p<n;p++){
								for(int l=p+1;l<=n;l++){
									if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l]})*2){
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
	else if(n==8){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					for(int q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>max({a[i],a[j],a[k],a[q]})*2){
							cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int q=k+1;q<n;q++){
						for(int o=q+1;o<=n;o++){
							if(a[i]+a[j]+a[k]+a[q]+a[o]>max({a[i],a[j],a[k],a[q],a[o]})*2){
								cnt++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int q=k+1;q<n-1;q++){
						for(int o=q+1;o<n;o++){
							for(int p=o+1;p<=n;p++){
								if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]>max({a[i],a[j],a[k],a[q],a[o],a[p]})*2){
									cnt++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-5;i++){
			for(int j=i+1;j<n-4;j++){
				for(int k=j+1;k<n-3;k++){
					for(int q=k+1;q<n-2;q++){
						for(int o=q+1;o<n-1;o++){
							for(int p=o+1;p<n;p++){
								for(int l=p+1;l<=n;l++){
									if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l]})*2){
										cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-6;i++){
			for(int j=i+1;j<n-5;j++){
				for(int k=j+1;k<n-4;k++){
					for(int q=k+1;q<n-3;q++){
						for(int o=q+1;o<n-2;o++){
							for(int p=o+1;p<n-1;p++){
								for(int l=p+1;l<n;l++){
									for(int e=l+1;e<=n;e++){
										if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e]})*2){
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
	else if(n==9){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					for(int q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>max({a[i],a[j],a[k],a[q]})*2){
							cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int q=k+1;q<n;q++){
						for(int o=q+1;o<=n;o++){
							if(a[i]+a[j]+a[k]+a[q]+a[o]>max({a[i],a[j],a[k],a[q],a[o]})*2){
								cnt++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int q=k+1;q<n-1;q++){
						for(int o=q+1;o<n;o++){
							for(int p=o+1;p<=n;p++){
								if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]>max({a[i],a[j],a[k],a[q],a[o],a[p]})*2){
									cnt++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-5;i++){
			for(int j=i+1;j<n-4;j++){
				for(int k=j+1;k<n-3;k++){
					for(int q=k+1;q<n-2;q++){
						for(int o=q+1;o<n-1;o++){
							for(int p=o+1;p<n;p++){
								for(int l=p+1;l<=n;l++){
									if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l]})*2){
										cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-6;i++){
			for(int j=i+1;j<n-5;j++){
				for(int k=j+1;k<n-4;k++){
					for(int q=k+1;q<n-3;q++){
						for(int o=q+1;o<n-2;o++){
							for(int p=o+1;p<n-1;p++){
								for(int l=p+1;l<n;l++){
									for(int e=l+1;e<=n;e++){
										if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e]})*2){
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
		for(int i=1;i<n-7;i++){
			for(int j=i+1;j<n-6;j++){
				for(int k=j+1;k<n-5;k++){
					for(int q=k+1;q<n-4;q++){
						for(int o=q+1;o<n-3;o++){
							for(int p=o+1;p<n-2;p++){
								for(int l=p+1;l<n-1;l++){
									for(int e=l+1;e<n;e++){
										for(int r=e+1;r<=n;r++){
											if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]+a[r]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e],a[r]})*2){
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
	else if(n==10){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					for(int q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>max({a[i],a[j],a[k],a[q]})*2){
							cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int q=k+1;q<n;q++){
						for(int o=q+1;o<=n;o++){
							if(a[i]+a[j]+a[k]+a[q]+a[o]>max({a[i],a[j],a[k],a[q],a[o]})*2){
								cnt++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int q=k+1;q<n-1;q++){
						for(int o=q+1;o<n;o++){
							for(int p=o+1;p<=n;p++){
								if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]>max({a[i],a[j],a[k],a[q],a[o],a[p]})*2){
									cnt++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-5;i++){
			for(int j=i+1;j<n-4;j++){
				for(int k=j+1;k<n-3;k++){
					for(int q=k+1;q<n-2;q++){
						for(int o=q+1;o<n-1;o++){
							for(int p=o+1;p<n;p++){
								for(int l=p+1;l<=n;l++){
									if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l]})*2){
										cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-6;i++){
			for(int j=i+1;j<n-5;j++){
				for(int k=j+1;k<n-4;k++){
					for(int q=k+1;q<n-3;q++){
						for(int o=q+1;o<n-2;o++){
							for(int p=o+1;p<n-1;p++){
								for(int l=p+1;l<n;l++){
									for(int e=l+1;e<=n;e++){
										if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e]})*2){
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
		for(int i=1;i<n-7;i++){
			for(int j=i+1;j<n-6;j++){
				for(int k=j+1;k<n-5;k++){
					for(int q=k+1;q<n-4;q++){
						for(int o=q+1;o<n-3;o++){
							for(int p=o+1;p<n-2;p++){
								for(int l=p+1;l<n-1;l++){
									for(int e=l+1;e<n;e++){
										for(int r=e+1;r<=n;r++){
											if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]+a[r]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e],a[r]})*2){
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
		for(int i=1;i<n-8;i++){
			for(int j=i+1;j<n-7;j++){
				for(int k=j+1;k<n-6;k++){
					for(int q=k+1;q<n-5;q++){
						for(int o=q+1;o<n-4;o++){
							for(int p=o+1;p<n-3;p++){
								for(int l=p+1;l<n-2;l++){
									for(int e=l+1;e<n-1;e++){
										for(int r=e+1;r<n;r++){
											for(int t=r+1;t<=n;t++){
												if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]+a[r]+a[t]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e],a[r],a[t]})*2){
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
	else if(n==11){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					for(int q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>max({a[i],a[j],a[k],a[q]})*2){
							cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int q=k+1;q<n;q++){
						for(int o=q+1;o<=n;o++){
							if(a[i]+a[j]+a[k]+a[q]+a[o]>max({a[i],a[j],a[k],a[q],a[o]})*2){
								cnt++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int q=k+1;q<n-1;q++){
						for(int o=q+1;o<n;o++){
							for(int p=o+1;p<=n;p++){
								if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]>max({a[i],a[j],a[k],a[q],a[o],a[p]})*2){
									cnt++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-5;i++){
			for(int j=i+1;j<n-4;j++){
				for(int k=j+1;k<n-3;k++){
					for(int q=k+1;q<n-2;q++){
						for(int o=q+1;o<n-1;o++){
							for(int p=o+1;p<n;p++){
								for(int l=p+1;l<=n;l++){
									if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l]})*2){
										cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-6;i++){
			for(int j=i+1;j<n-5;j++){
				for(int k=j+1;k<n-4;k++){
					for(int q=k+1;q<n-3;q++){
						for(int o=q+1;o<n-2;o++){
							for(int p=o+1;p<n-1;p++){
								for(int l=p+1;l<n;l++){
									for(int e=l+1;e<=n;e++){
										if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e]})*2){
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
		for(int i=1;i<n-7;i++){
			for(int j=i+1;j<n-6;j++){
				for(int k=j+1;k<n-5;k++){
					for(int q=k+1;q<n-4;q++){
						for(int o=q+1;o<n-3;o++){
							for(int p=o+1;p<n-2;p++){
								for(int l=p+1;l<n-1;l++){
									for(int e=l+1;e<n;e++){
										for(int r=e+1;r<=n;r++){
											if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]+a[r]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e],a[r]})*2){
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
		for(int i=1;i<n-8;i++){
			for(int j=i+1;j<n-7;j++){
				for(int k=j+1;k<n-6;k++){
					for(int q=k+1;q<n-5;q++){
						for(int o=q+1;o<n-4;o++){
							for(int p=o+1;p<n-3;p++){
								for(int l=p+1;l<n-2;l++){
									for(int e=l+1;e<n-1;e++){
										for(int r=e+1;r<n;r++){
											for(int t=r+1;t<=n;t++){
												if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]+a[r]+a[t]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e],a[r],a[t]})*2){
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
		for(int i=1;i<n-9;i++){
			for(int j=i+1;j<n-8;j++){
				for(int k=j+1;k<n-7;k++){
					for(int q=k+1;q<n-6;q++){
						for(int o=q+1;o<n-5;o++){
							for(int p=o+1;p<n-4;p++){
								for(int l=p+1;l<n-3;l++){
									for(int e=l+1;e<n-2;e++){
										for(int r=e+1;r<n-1;r++){
											for(int t=r+1;t<n;t++){
												for(int w=t+1;w<=n;w++){
													if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]+a[r]+a[t]+a[w]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e],a[r],a[t],a[w]})*2){
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
	else if(n==12){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
						cnt++;
					}
				}
			}
		}
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					for(int q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>max({a[i],a[j],a[k],a[q]})*2){
							cnt++;
						}
					}
				}
			}
		}
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int q=k+1;q<n;q++){
						for(int o=q+1;o<=n;o++){
							if(a[i]+a[j]+a[k]+a[q]+a[o]>max({a[i],a[j],a[k],a[q],a[o]})*2){
								cnt++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int q=k+1;q<n-1;q++){
						for(int o=q+1;o<n;o++){
							for(int p=o+1;p<=n;p++){
								if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]>max({a[i],a[j],a[k],a[q],a[o],a[p]})*2){
									cnt++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-5;i++){
			for(int j=i+1;j<n-4;j++){
				for(int k=j+1;k<n-3;k++){
					for(int q=k+1;q<n-2;q++){
						for(int o=q+1;o<n-1;o++){
							for(int p=o+1;p<n;p++){
								for(int l=p+1;l<=n;l++){
									if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l]})*2){
										cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<n-6;i++){
			for(int j=i+1;j<n-5;j++){
				for(int k=j+1;k<n-4;k++){
					for(int q=k+1;q<n-3;q++){
						for(int o=q+1;o<n-2;o++){
							for(int p=o+1;p<n-1;p++){
								for(int l=p+1;l<n;l++){
									for(int e=l+1;e<=n;e++){
										if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e]})*2){
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
		for(int i=1;i<n-7;i++){
			for(int j=i+1;j<n-6;j++){
				for(int k=j+1;k<n-5;k++){
					for(int q=k+1;q<n-4;q++){
						for(int o=q+1;o<n-3;o++){
							for(int p=o+1;p<n-2;p++){
								for(int l=p+1;l<n-1;l++){
									for(int e=l+1;e<n;e++){
										for(int r=e+1;r<=n;r++){
											if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]+a[r]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e],a[r]})*2){
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
		for(int i=1;i<n-8;i++){
			for(int j=i+1;j<n-7;j++){
				for(int k=j+1;k<n-6;k++){
					for(int q=k+1;q<n-5;q++){
						for(int o=q+1;o<n-4;o++){
							for(int p=o+1;p<n-3;p++){
								for(int l=p+1;l<n-2;l++){
									for(int e=l+1;e<n-1;e++){
										for(int r=e+1;r<n;r++){
											for(int t=r+1;t<=n;t++){
												if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]+a[r]+a[t]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e],a[r],a[t]})*2){
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
		for(int i=1;i<n-9;i++){
			for(int j=i+1;j<n-8;j++){
				for(int k=j+1;k<n-7;k++){
					for(int q=k+1;q<n-6;q++){
						for(int o=q+1;o<n-5;o++){
							for(int p=o+1;p<n-4;p++){
								for(int l=p+1;l<n-3;l++){
									for(int e=l+1;e<n-2;e++){
										for(int r=e+1;r<n-1;r++){
											for(int t=r+1;t<n;t++){
												for(int w=t+1;w<=n;w++){
													if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]+a[r]+a[t]+a[w]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e],a[r],a[t],a[w]})*2){
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
		for(int i=1;i<n-10;i++){
			for(int j=i+1;j<n-9;j++){
				for(int k=j+1;k<n-8;k++){
					for(int q=k+1;q<n-7;q++){
						for(int o=q+1;o<n-6;o++){
							for(int p=o+1;p<n-5;p++){
								for(int l=p+1;l<n-4;l++){
									for(int e=l+1;e<n-3;e++){
										for(int r=e+1;r<n-2;r++){
											for(int t=r+1;t<n-1;t++){
												for(int w=t+1;w<n;w++){
													for(int s=w+1;s<=n;s++){
														if(a[i]+a[j]+a[k]+a[q]+a[o]+a[p]+a[l]+a[e]+a[r]+a[t]+a[w]+a[s]>max({a[i],a[j],a[k],a[q],a[o],a[p],a[l],a[e],a[r],a[t],a[w],a[s]})*2){
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
	else{
		cout<<rand();
	}
	cout<<cnt;
	return 0;
}
