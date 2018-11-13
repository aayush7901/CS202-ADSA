#include <iostream>
#include <fstream>
#include "queue.hpp"
using namespace std;
using namespace queuehelp;

#define MAX 1000

char arr[MAX][MAX];
int res[MAX][MAX];

int row=0,col=0;

int rows[] = {-1,0,1,0};
int cols[] = {0,1,0,-1};

class qnode
{
	private:
		int i,j,dist;
	public:
		qnode()
		{
			i=0;j=0;dist=0;
		}
		qnode(int x, int y, int d)
		{
			i=x;
			j=y;
			dist=d;
		}
		int geti()
		{
			return i;
		}
		int getj()
		{
			return j;
		}
		int getdist()
		{
			return dist;
		}
};

bool isvalid(int i, int j)
{
	return !(i<0 || j<0 || i>=row || j>=col);
}

bool issafe(int i, int j)
{
	return !(arr[i][j]!='O' || res[i][j]!=-1);
}

void findSoln()
{
	int i,j;
	queue <qnode> q;
	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
			res[i][j]=-1;
			if (arr[i][j]=='G')
			{
				res[i][j]=0;
				qnode tmp(i,j,res[i][j]);
				q.push(tmp);
			}
		}
	}
	while (!q.empty())
	{
		qnode cur=q.front();
		int i,j,x=cur.geti(), y=cur.getj(), dist=cur.getdist();
		for (i=0;i<4;i++)
		{
			if (isvalid(x+rows[i],y+cols[i]) && issafe(x+rows[i],y+cols[i]))
			{
				res[x+rows[i]][y+cols[i]]=dist+1;
				qnode tmp(x+rows[i],y+cols[i],dist+1);
				q.push(tmp);
			}
		}
		q.pop();
	}
	ofstream f("output1.out");
	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
			f<<res[i][j]<<" ";
		f<<"\n";
	}
}

int main()
{
	int i,j;
	string str;
	ifstream f("input1.in");
	while (getline(f, str))
	{
		col=0;
		for (i=0;i<str.length();i++)
		{
			if (str[i]=='O'||str[i]=='W'||str[i]=='G')
			{
				arr[row][col]=str[i];
				col++;
			}
		}
		row++;
	}
	findSoln();
	return 0;
}
