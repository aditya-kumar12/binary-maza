#include <bits/stdc++.h>
using namespace std;
int shortestPathBinaryMaze(int maze[21][21],int m,int n,int destX,int destY)
{
    if(maze[0][0]==0)
     return -1;
    if(destX==0 && destY==0)
     return 0;
    int visited[21][21]={};
    int finalAns=INT_MAX;
    queue< pair< pair<int,int>,int> > q;
    pair< pair<int,int>,int >p;
    p.first.first=p.first.second=p.second=0;
    q.push(p);
    visited[0][0]=1;
    while(!q.empty())
    {
      pair< pair<int,int>,int > f = q.front();
      q.pop();

      //index of element currently front of queue
      int x=f.first.first;
      int y=f.first.second;
      
      //current distance from source
      int d=f.second;

      //adjacent elements
      pair<int,int> up=make_pair(x-1,y);
      pair<int,int> down=make_pair(x+1,y);
      pair<int,int> left=make_pair(x,y-1);
      pair<int,int> right=make_pair(x,y+1);

      //We'll check three things for each adjacent point-
      //1.It is in range i.e. it is not outside the maze
      //2.It is not already visited
      //3.It is reachable i.e. not marked as # in maze

      if(up.first>=0 && up.first<m && up.second>=0 && up.second<n && maze[up.first][up.second]!=0  && visited[up.first][up.second]!=1)
      {
        if(up.first==destX && up.second==destY)
        {
            finalAns=d+1;
            break;
        } 
        else
        {
             q.push(make_pair(up,d+1));
             visited[up.first][up.second]=1;
        }
      }
      if(down.first>=0 && down.first<m && down.second>=0 && down.second<n && maze[down.first][down.second]!=0  && visited[down.first][down.second]!=1)
      {
        if(down.first==destX && down.second==destY)
        {
            finalAns=d+1;
            break;
        } 
        else
        {
             q.push(make_pair(down,d+1));
             visited[down.first][down.second]=1;
        }
      }
      if(left.first>=0 && left.first<m && left.second>=0 && left.second<n && maze[left.first][left.second]!=0  && visited[left.first][left.second]!=1)
      {
        if(left.first==destX && left.second==destY)
        {
            finalAns=d+1;
            break;
        } 
        else
        {
             q.push(make_pair(left,d+1));
             visited[left.first][left.second]=1;
        }
      }
      if(right.first>=0 && right.first<m && right.second>=0 && right.second<n && maze[right.first][right.second]!=0  && visited[right.first][right.second]!=1)
      {
        if(right.first==destX && right.second==destY)
        {
            finalAns=d+1;
            break;
        } 
        else
        {
             q.push(make_pair(right,d+1));
             visited[right.first][right.second]=1;
        }
      }
    }
    return finalAns==INT_MAX?-1:finalAns;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int m,n,maze[21][21],x,y;
        cin>>m>>n;
        for(int i=0;i<m;i++)
         for(int j=0;j<n;j++)
          cin>>maze[i][j];
        cin>>x>>y;
        cout<<shortestPathBinaryMaze(maze,m,n,x,y)<<endl;
    }
}
