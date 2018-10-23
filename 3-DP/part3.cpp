#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Edit Distance (Sequence Alignment OR Hirschberg Algorithm) in Linear Space
// Space Complexity = O(m+n)
// Time Complexity = O(m*n)

ll gp,mpat,mpgc,mpac,mp; //gap penalty and mismatch penalties
int i,j;

void print(vector <int> v)
{
	for (i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
}

int casefnc(char a, char b)
{
	if ((a=='A' && b=='T')||(a=='T' && b=='A')||(a=='t' && b=='a')||(a=='a' && b=='t'))
		return 1;
	else if ((a=='G' && b=='C')||(a=='C' && b=='G')||(a=='g' && b=='c')||(a=='c' && b=='g'))
		return 2;
	else if ((a=='A' && b=='C')||(a=='C' && b=='A')||(a=='a' && b=='c')||(a=='c' && b=='a'))
		return 3;
	return 4; //other cases
}

vector <string> align(string x, string y)
{
	int xlen=x.length();
	int ylen=y.length();
	ll dp[ylen+1][xlen+1];
	ll diag,up,left;
	for (j=0;j<=xlen;j++)
		dp[0][j]=gp*j;
	for (i=0;i<=ylen;i++)
		dp[i][0]=gp*i;
	for (i=1;i<=ylen;i++)
	{
		for (j=1;j<=xlen;j++)
		{
			if (x[j-1]==y[i-1])
				diag=dp[i-1][j-1];
			else
			{
				if (casefnc(x[j-1],y[i-1])==1)
					diag=dp[i-1][j-1]+mpat;
				else if (casefnc(x[j-1],y[i-1])==2)
					diag=dp[i-1][j-1]+mpgc;
				else if (casefnc(x[j-1],y[i-1])==3)
					diag=dp[i-1][j-1]+mpac;
				else
					diag=dp[i-1][j-1]+mp;
			}
			left=dp[i][j-1]+gp;
			up=dp[i-1][j]+gp;
			dp[i][j]=min(diag,min(up,left));
		}
	}

	vector <string> v(2);
	v[0]="",v[1]="";
	while (xlen>0 && ylen>0)
	{
		ll s=dp[ylen][xlen];
		ll sup=dp[ylen-1][xlen];
		ll sleft=dp[ylen][xlen-1];
		if (s==sleft+gp)
		{
			v[1]+='-';
			v[0]+=x[--xlen];
		}
		else if (s==sup+gp)
		{
			v[1]+=y[--ylen];
			v[0]+='-';
		}
		else
		{
			v[1]+=y[--ylen];
			v[0]+=x[--xlen];
		}
	}
	while (xlen>0)
	{
		v[1]+='-';
		v[0]+=x[--xlen];
	}
	while (ylen>0)
	{
		v[1]+=y[--ylen];
		v[0]+='-';
	}
	for (i=0;i<2;i++)
		reverse(v[i].begin(),v[i].end());
	return v;
}

vector <ll> getlast(string x, string y)
{
	int xlen=x.length();
	int ylen=y.length();
	ll dp[2][xlen+1];
	ll diag,up,left;
	for (j=0;j<=xlen;j++)
		dp[0][j]=gp*j;
	for (i=1;i<=ylen;i++)
	{
		dp[1][0]=gp*i;
		for (j=1;j<=xlen;j++)
		{
			if (x[j-1]==y[i-1])
				diag=dp[0][j-1];
			else
			{
				if (casefnc(x[j-1],y[i-1])==1)
					diag=dp[0][j-1]+mpat;
				else if (casefnc(x[j-1],y[i-1])==2)
					diag=dp[0][j-1]+mpgc;
				else if (casefnc(x[j-1],y[i-1])==3)
					diag=dp[0][j-1]+mpac;
				else
					diag=dp[0][j-1]+mp;
			}
			left=dp[1][j-1]+gp;
			up=dp[0][j]+gp;
			dp[1][j]=min(diag,min(up,left));
		}
		for (j=0;j<=xlen;j++)
			dp[0][j]=dp[1][j];
	}

	vector <ll> v(xlen+1);
	for (i=0;i<=xlen;i++)
		v[i]=dp[0][i];
	return v;
}

ll getres(string x, string y)
{
	int xlen=x.length();
	int ylen=y.length();
	ll dp[2][xlen+1];
	ll diag,up,left;
	for (j=0;j<=xlen;j++)
		dp[0][j]=gp*j;
	for (i=1;i<=ylen;i++)
	{
		dp[1][0]=gp*i;
		for (j=1;j<=xlen;j++)
		{
			if (x[j-1]==y[i-1])
				diag=dp[0][j-1];
			else
			{
				if (casefnc(x[j-1],y[i-1])==1)
					diag=dp[0][j-1]+mpat;
				else if (casefnc(x[j-1],y[i-1])==2)
					diag=dp[0][j-1]+mpgc;
				else if (casefnc(x[j-1],y[i-1])==3)
					diag=dp[0][j-1]+mpac;
				else
					diag=dp[0][j-1]+mp;
			}
			left=dp[1][j-1]+gp;
			up=dp[0][j]+gp;
			dp[1][j]=min(diag,min(up,left));
		}
		for (j=0;j<=xlen;j++)
			dp[0][j]=dp[1][j];
	}
	return dp[0][xlen];
}

ll getmin(vector<ll> upscore, vector<ll> downscore)
{
	ll mini=LONG_MAX,res;
	for (i=0,j=downscore.size()-1;i<upscore.size();i++,j--)
	{
		if (upscore[i]+downscore[j]<mini)
		{
			mini=upscore[i]+downscore[j];
			res=i;
		}
	}
	return res;
}

vector <string> concatfnc(vector <string> v1, vector<string> v2)
{
	for (i=0;i<v1.size();i++)
		v1[i]+=v2[i];
	return v1;
}

vector <string> hirschberg(string x, string y)
{
	vector <string> v(2);
	v[0]="",v[1]="";
	if (x.length()==0)
	{
		for (i=0;i<y.length();i++)
		{
			v[0]+='-';
			v[1]+=y[i];
		}
	}
	else if (y.length()==0)
	{
		for (i=0;i<x.length();i++)
		{
			v[0]+=x[i];
			v[1]+='-';
		}
	}
	else if (x.length()==1 || y.length()==1)
	{
		v=align(x,y);
	}
	else
	{
		int ylen=y.length();
		int midy=ylen/2;
		vector <ll> upscore=getlast(x,y.substr(0,midy));
		string xrev=x;
		reverse(xrev.begin(),xrev.end());
		string yrev=y.substr(midy,y.length());
		reverse(yrev.begin(),yrev.end());
		vector <ll> downscore=getlast(xrev,yrev);
		ll minix=getmin(upscore,downscore);
		v=concatfnc(hirschberg(x.substr(0,minix),y.substr(0,midy)),hirschberg(x.substr(minix,x.length()),y.substr(midy,y.length())));
	}
	return v;
}

int main(int argc, char* argv[])
{
	if (argc<=5)
	{
		cout<<"Please enter arguments GP, MPAT, MPGC, MPAC, MP before execution.\n";
		exit(1);
	}
	gp=atoll(argv[1]);
	mpat=atoll(argv[2]);
	mpgc=atoll(argv[3]);
	mpac=atoll(argv[4]);
	mp=atoll(argv[5]);
	string x,y;
	cin>>x>>y;
	vector <string> v=hirschberg(x,y);
	cout<<v[0]<<"\n"<<v[1]<<"\n";
	cout<<"Cost = "<<getres(x,y)<<"\n";
	return 0;
}
