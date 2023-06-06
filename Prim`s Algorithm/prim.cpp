#include <iostream>
#include <array>

using namespace std;

int main()
{
    int i, j, h=0, y=0, observer, a=0, b=0, c;
    int path [7][7]={{0,2,4,1,0,0,0},
                     {2,0,0,3,10,0,0},
                     {4,0,0,2,0,5,0},
                     {1,3,2,0,7,8,4},
                     {0,10,0,7,0,0,6},
                     {0,0,5,8,0,0,1},
                     {0,0,0,4,6,1,0}};
    int prim [7][7];
    int comparator;


    //neutralize prim array
    for (h=0;h<7;h++)
    {
        for(y=0;y<7;y++)
        {
            prim[h][y]=0;
        }
    }

    for(c=0;c<7;c++)
                path[c][0]=0;


    //main engine
    i=0;
        for(observer=0;observer<7;observer++)
        {
            comparator=999;
            for(j=0;j<7;j++)
            {
                if (i!=j)
                {
                    if (path[i][j]!=0)
                    {
                        if (comparator>path[i][j])
                        {
                            comparator=path[i][j];
                            y=j;
                            h=i;
                        }
                    }
                }
            }
            prim[h][y]=1;

            for(c=0;c<7;c++)
                path[c][y]=0;

            i=y;
        }


    //checking section
     for (i=0;i<7;i++)
    {
        for (j=0;j<7;j++)
        {
            cout<<prim[i][j]<<" ";
        }
        cout<<"\n";
    }
    

    //final result projector

    cout<<"MST:\n";

    i=0;

    for (j=0;j<7;j++)
    {
        if (prim[i][j]==1)
        {
            cout<<i+1<<" -> "<<j+1;
            break;
        }
    }
    

    h=j;

    for (i=2;i<7;i++)
    {
        y=0;
        for (j=0;j<7;j++)
        {
            if (prim[h][y]==1)
            {
                cout<<" -> "<<j+1;
                h=y;
                break;
            }
            y++;

        }
    }

    


    return 0;
}

