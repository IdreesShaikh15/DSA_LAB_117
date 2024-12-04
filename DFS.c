#include<stdio.h>
#include<conio.h>

void dfs(int);
int n,i,j,a[10][10],vis[10],parent[10],cycle3 = 0;

void main()
{
 
   printf("enter the number of vertices\n");
   scanf("%d",&n);
   printf("enter the adjacency matrix\n");
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       scanf("%d",&a[i][j]);
     }
     vis[i]=0;
     parent[i] = -1;
    }
    printf("dfs traversal\n");
    for(i=1;i<=n;i++)
    {
      if(vis[i]==0)
       dfs(i);
    }
    if(cycle == 1)
        printf("\nGraph contains a cycle.\n");
    else
        printf("\nNo cycle detected in the graph.\n");
    
    for(i=1;i<=n;i++)
    {
        if(vis[i] == 0)
        {
            printf("\nGraph is not connected.\n");
            return;
        }
    }
    printf("\nGraph is connected.\n");
    getch();
}

void dfs(int v)
{
   vis[v]=1;
   printf("%d ",v);
   for(j=1;j<=n;j++)
   {
       if(a[v][j]==1 && vis[j]==0)
       {
           parent[j] = v;
           dfs(j);
       }
       else if(a[v][j]==1 && parent[v] != j)
       {
           cycle = 1;
       }
    }
}
