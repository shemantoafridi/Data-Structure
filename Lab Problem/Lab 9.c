#include<stdio.h>
#include<string.h>
int graph[100][100]= {0},node;
void create(int node);
void add();
void Del();
int main()
{
    int cho;
    while(cho!=7)
    {
        printf("            Menu\n");
        printf("-----------------------------\n");
        printf("1. Create Graph\n");
        printf("2. Add new Vertex and Edge\n");
        printf("3. Delete Vertex\n");
        printf("4. Print Graph\n");
        printf("5. Depth First Traversal\n");
        printf("6. Breath First Traversal\n");
        printf("7. Exit\n");
        printf("-----------------------------\n");
        printf("Choose What You Want to Do?: ");
        scanf("%d",&cho);
        if(cho==1)
        {
            printf("Enter the Number of Nodes in Graph: ");
            scanf("%d",&node);
            create(node);
        }
        if(cho==2) add();
        if(cho==3) Del();
        if(cho==4) print(node);
    }
}
void create(int node)
{

    printf("Enter the Edges (x,y) = (source , Destination) use (,)comma\nto separate the Edge: Example: (a,b),(c,d),(e,f),......\n");
    EnterEdge();
}
void add()
{
    printf("Enter the New Edge (x,y) = (source , Destination): ");
    node++;
    EnterEdge();
}
void EnterEdge()
{
    int enter;
    char s[500];
    scanf("%d",&enter);
    gets(s);
    int count=0;
    for(int i=0; i<strlen(s); i++)
    {
        int x,y;
        if(s[i]!='('&&s[i]!=')'&&s[i]!=','&&s[i]!=' ')
        {
            count++;
            if(count==1)
            {
                x=s[i];
            }
            if(count==2)
            {
                y=s[i];
                graph[x-48][y-48]=1;
                graph[y-48][x-48]=1;
                count=0;
            }
        }
    }
}
void Del()
{
    printf("Enter the Vertex to Delete: ");
    int ver;
    scanf("%d",&ver);
    for(int i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
        {
            if(i==ver||j==ver)
            {
                graph[i][j]=0;
                graph[j][i]=0;
            }
        }
    }
}
void print(int node)
{
    printf("    Graph Matrix\n");
    printf("----------------------\n\n");
    for(int i=0;i<node;i++){
    printf("    (%d)",i);
    }
    printf("\n\n");
    for(int i=0; i<node; i++)
    {
        printf("(%d) ",i);
        for(int j=0; j<node; j++)
        {
            printf(" %d     ",graph[i][j]);
        }
        printf("\n\n");
    }
}
