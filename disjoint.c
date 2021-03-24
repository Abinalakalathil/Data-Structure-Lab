#include <stdio.h>
struct DisjSet {
    int parent[10];
    int rank[10]; //rank[i] is the height of the tree representing the set
    int n;
}dis;
    // Creates n single item sets
   void makeSet()
    {
        for (int i = 0; i < dis.n; i++) {
           dis.parent[i] = i;
           dis.rank[i]=0;
        }
    }
    //Displays Disjoint set
   void displaySet()
    {   printf("\nParent Array\n");
        for (int i = 0; i < dis.n; i++) {
           printf("%d ",dis.parent[i]); }
           printf("\nRank Array\n");
            for (int i = 0; i < dis.n; i++)
            {
                printf("%d ",dis.rank[i]);
            }
           printf("\n");
    }

    int find(int x)
    {

        if (dis.parent[x] != x) {


            dis.parent[x] = find(dis.parent[x]);


        }
        return dis.parent[x];
    }


int main()
{   int n,x,y;
    printf("How many elements ?");
    scanf("%d",&dis.n);
    makeSet();
      int ch,wish;

 do
  {
  printf("\n____MENU____\n");
  printf("1.Find\n2.Display\n");
  printf("enter choice\n");
  scanf("%d",&ch);

  switch(ch)
   {

     case 1: printf("Enter elements to check if connected components");
                  scanf("%d %d",&x,&y);
                  if (find(x) == find(y))
                  printf("Connected components\n") ;
                  else
                 printf("Not onnected components \n") ;
	    break;
     case 2: displaySet();
	    break;
   }
   printf("\nDo you wish to continue ?(1/0)\n");
   scanf("%d",&wish);
   }while(wish==1);
 return 0;
}
