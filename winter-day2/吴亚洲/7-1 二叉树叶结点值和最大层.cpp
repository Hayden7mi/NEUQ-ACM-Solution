#include<bits/stdc++.h>
using namespace std;
int sum[105];
int N;
struct Node
{
	int date;
	int level;
	Node *left;
	Node *right;
};
void creat(Node *&node,int level)
{
	int date;
	cin>>date;
	if(date==0)
	{
		node=NULL;
		return ;
	}
	else
	{
		node=new Node;
		node->date=date;
		node->level=level;
		N=max(N,level);
		creat(node->left,level+1);
		creat(node->right,level+1);
	}
}
void search(Node *&node)
{
	if(node==NULL)
	return ;
	if(node->left==NULL&&node->right==NULL)
	sum[node->level]+=node->date;
	else
	{
		search(node->left);
		search(node->right);
	}
}
int main()
{
	Node *t;
	creat(t,0);
	search(t);
	int M=-0x7ffffff,ans;
	for(int i=0;i<=N;i++)
	if(sum[i]>=M)
	{
		M=sum[i];
		ans=i;
	}
	cout<<ans;
}
