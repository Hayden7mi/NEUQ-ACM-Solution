﻿#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+2;int c[N],a[N],b[N],n;
ll ans;
bool cmp(int x,int y){return a[x]<a[y];}
void add(int x)
{
	while(x<=n)
	{
		c[x]++;
		x+=(x&-x);
	}
	return;
}
int ask(int x)
{
	int s=0;
	while(x)
	{
		s+=c[x];
		x-=(x&-x);
	}
	return s;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);b[i]=i;
	}
	stable_sort(b+1,b+1+n,cmp);//排下标
	for(int i=1;i<=n;i++) a[b[i]]=i; 
	for(int i=n;i>=1;i--)
	{
		ans+=ask(a[i]-1);
		add(a[i]);
	}
	printf("%lld\n",ans); 
    return 0;
} 