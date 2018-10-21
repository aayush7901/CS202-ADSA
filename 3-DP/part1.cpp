#include <bits/stdc++.h>
using namespace std;

// Edit Distance (Sequence Alignment OR Levinshtein Distance)
// Space Complexity = O(m*n)
// Time Complexity = O(m*n)

#define UP 1
#define LEFT 2
#define DIAG 3

void align(const string& a, const string& b, int gp, int mp)
{
	int i,j,m=a.length(),n=b.length();
	int dp[m+1][n+1];	//stores cost to change a to b with removal, insertion or replacements
	int prev[m+1][n+1]; // stores what operation to perform to change a[i] to b[j]
	for (i=0;i<m+1;i++)
	{
		dp[i][0]=gp*i;
		prev[i][0]=UP;	//Remove
	}
	for (i=0;i<n+1;i++)
	{
		dp[0][i]=gp*i;
		prev[0][i]=LEFT;  //Insert
	}
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (a[i-1]==b[j-1])	// NO ACTION
			{
				dp[i][j]=dp[i-1][j-1];
				prev[i][j]=DIAG;
			}
			else
			{
				dp[i][j]=mp+dp[i-1][j-1];	//REPLACE
				prev[i][j]=DIAG;
				if (gp+dp[i-1][j]<dp[i][j])	//REMOVE
				{
					dp[i][j]=gp+dp[i-1][j];
					prev[i][j]=UP;
				}
				if (gp+dp[i][j-1]<dp[i][j])	//INSERT
				{
					dp[i][j]=gp+dp[i][j-1];
					prev[i][j]=LEFT;
				}
			}
		}
	}
	int tmp;
	i=m,j=n;
	string resa="",resb="";
	while (!(i==0 && j==0))
	{
		tmp=prev[i][j];
		if (tmp==DIAG) //REPLACE OR NO ACTION
		{
			resa=a[i-1]+resa;
			resb=b[j-1]+resb;
			i--,j--;
		}
		else if (tmp==LEFT) // INSERT (insert required char)
		{
			resa='-'+resa;
			resb=b[j-1]+resb;
			j--;
		}
		else if (tmp==UP)	//REMOVE (insert gap)
		{
			resa=a[i-1]+resa;
			resb='-'+resb;
			i--;
		}
	}
	cout<<resa<<'\n';
	cout<<resb<<'\n';
	cout<<"Cost = "<<dp[m][n]<<'\n';
}

int main(int argc, char* argv[])
{
	if (argc<=1)
	{
		cout<<"Please enter an argument.\n1 for (GP,MP)=(6,4)\n2 for (GP,MP)=(4,6)\n";
		exit(1);
	}
	string ar = argv[1];
	int gp,mp;
	if (ar=="1")
		gp=6, mp=4;
	else if (ar=="2")
		gp=4, mp=6;
	else if (ar=="3")
		cin>>gp>>mp;
	string a,b;
	cin>>a>>b;
	align(a,b,gp,mp);
	return 0;
}
