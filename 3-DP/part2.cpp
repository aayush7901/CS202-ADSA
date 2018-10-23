#include <bits/stdc++.h>
using namespace std;

// Edit Distance (Sequence Alignment OR Hirschberg Algorithm) in Linear Space
// Space Complexity = O(m+n)
// Time Complexity = O(m*n)

int gp,mp; //gap penalty and mismatch penalty
int i,j;

void print(vector <int> v)
{
	for (i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
}

vector <string> align(string x, string y)		// Simple align
{
	int xlen=x.length();
	int ylen=y.length();
	int dp[ylen+1][xlen+1];
	int diag,up,left;
	for (j=0;j<=xlen;j++)
		dp[0][j]=gp*j;
	for (i=0;i<=ylen;i++)
		dp[i][0]=gp*i;
	for (i=1;i<=ylen;i++)
	{
		for (j=1;j<=xlen;j++)
		{
			if (x[j-1]==y[i-1])			//No action
				diag=dp[i-1][j-1];
			else
				diag=dp[i-1][j-1]+mp;
			left=dp[i][j-1]+gp;
			up=dp[i-1][j]+gp;
			dp[i][j]=min(diag,min(up,left));		// Min of replace, insert, remove
		}
	}

	vector <string> v(2);			// for constructing the alignment
	v[0]="",v[1]="";
	while (xlen>0 && ylen>0)
	{
		int s=dp[ylen][xlen];
		int sup=dp[ylen-1][xlen];
		int sleft=dp[ylen][xlen-1];
		if (s==sleft+gp)			// Remove
		{
			v[1]+='-';
			v[0]+=x[--xlen];
		}
		else if (s==sup+gp)			// Insert
		{
			v[1]+=y[--ylen];
			v[0]+='-';
		}
		else						// Replace or do nothing
		{
			v[1]+=y[--ylen];
			v[0]+=x[--xlen];
		}
	}
	while (xlen>0)			// Add remaining letters of x
	{
		v[1]+='-';
		v[0]+=x[--xlen];
	}
	while (ylen>0)			// Add remaining letters of y
	{
		v[1]+=y[--ylen];
		v[0]+='-';
	}
	for (i=0;i<2;i++)		// Reverse the final alignments to get them in correct order
		reverse(v[i].begin(),v[i].end());
	return v;
}

vector <int> getlast(string x, string y)		// Returns the last line of the dp array in O(m) space
{
	int xlen=x.length();
	int ylen=y.length();
	int dp[2][xlen+1];
	int diag,up,left;
	for (j=0;j<=xlen;j++)
		dp[0][j]=gp*j;
	for (i=1;i<=ylen;i++)
	{
		dp[1][0]=gp*i;
		for (j=1;j<=xlen;j++)
		{
			if (x[j-1]==y[i-1])			// No action
				diag=dp[0][j-1];
			else
				diag=dp[0][j-1]+mp;
			left=dp[1][j-1]+gp;
			up=dp[0][j]+gp;
			dp[1][j]=min(diag,min(up,left));	// Minimum of insert, replace, remove
		}
		for (j=0;j<=xlen;j++)
			dp[0][j]=dp[1][j];
	}

	vector <int> v(xlen+1);
	for (i=0;i<=xlen;i++)	// copy the last line to a vector which is returned
		v[i]=dp[0][i];
	return v;
}

int getres(string x, string y)	// Returns the alignment cost of strings x and y in O(m) space
{
	int xlen=x.length();
	int ylen=y.length();
	int dp[2][xlen+1];
	int diag,up,left;
	for (j=0;j<=xlen;j++)
		dp[0][j]=gp*j;
	for (i=1;i<=ylen;i++)
	{
		dp[1][0]=gp*i;
		for (j=1;j<=xlen;j++)
		{
			if (x[j-1]==y[i-1]) 	// No action
				diag=dp[0][j-1];
			else
				diag=dp[0][j-1]+mp;
			left=dp[1][j-1]+gp;
			up=dp[0][j]+gp;
			dp[1][j]=min(diag,min(up,left));  // Minimum of insert, replace, remove
		}
		for (j=0;j<=xlen;j++)
			dp[0][j]=dp[1][j];
	}
	return dp[0][xlen];
}

int getmin(vector<int> upscore, vector<int> downscore)		// Returns the minimum column value to be selected for n/2 in divide and conquer
{
	int mini=INT_MAX,res;
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

vector <string> concatfnc(vector <string> v1, vector<string> v2)	// joins strings in v1 and v2
{
	for (i=0;i<v1.size();i++)
		v1[i]+=v2[i];
	return v1;
}

vector <string> hirschberg(string x, string y)		// Hirschberg alignment algo
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
	else if (x.length()==1 || y.length()==1)		// Standard Align takes O(m) or O(n) space
	{
		v=align(x,y);
	}
	else
	{
		int ylen=y.length();
		int midy=ylen/2;
		vector <int> upscore=getlast(x,y.substr(0,midy));	// space efficient forward
		string xrev=x;
		reverse(xrev.begin(),xrev.end());
		string yrev=y.substr(midy,y.length());
		reverse(yrev.begin(),yrev.end());
		vector <int> downscore=getlast(xrev,yrev);			// space efficient backward
		int minix=getmin(upscore,downscore);				//calculate shortest cost path node
		v=concatfnc(hirschberg(x.substr(0,minix),y.substr(0,midy)),hirschberg(x.substr(minix,x.length()),y.substr(midy,y.length())));   // use d&c to calculate all nodes and join the alignments to get result
	}
	return v;
}

int main(int argc, char* argv[])
{
	if (argc<=1)
	{
		cout<<"Please enter an argument.\n1 for (GP,MP)=(6,4)\n2 for (GP,MP)=(4,6)\n";
		exit(1);
	}
	string ar = argv[1];
	if (ar=="1")
		gp=6, mp=4;
	else if (ar=="2")
		gp=4, mp=6;
	string x,y;
	cin>>x>>y;
	vector <string> v=hirschberg(x,y);
	cout<<v[0]<<"\n"<<v[1]<<"\n";
	cout<<"Cost = "<<getres(x,y)<<"\n";
	return 0;
}
