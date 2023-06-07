#include <iostream>

using namespace std;

int i, h, str, mst=0, compare=999, engine;


//rapid engine
int rapid(int highway[], bool trace[], int val)
{
    int engine=compare;
    int engine_index;

    for(i=0;i<val;i++)
    {
        if(trace[i]==false)
        {
            if (highway[i]<engine)
            {
                engine=highway[i];
                engine_index=i;
            }
        }

    }
    return engine_index;
}

//recon engine
int recon(int parent[], int path[7][7], int val)
{
    for(i=1;i<val;i++)
    {
        mst+=path[i][parent[i]];
    }

    return mst;
}

//main engine
void prim(int path[7][7], int val)
{
    int parent[7];
    int highway[7];
    bool trace[7];

    for(i=0;i<val;i++)
    {
        highway[i]=compare;
        trace[i]=false;
    }

    highway[0]=0;
    parent[0]=-1;

    for(str=0;str<val-1;str++)
    {
        h=rapid(highway, trace, val);
        trace[h]=true;

        for(i=0;i<val;i++)
        {
            if(path[h][i])
            {
                if(trace[i]==false)
                {
                    if(path[h][i]<highway[i])
                    {
                        parent[i]=h;
                        highway[i]=path[h][i];
                    }
                }
            }

        }
    }

    int mst=recon(parent, path, val);
    cout<<"MST: "<<mst<<endl;
}

int main()
{
    int path [7][7]={{0,2,4,1,0,0,0},
                     {2,0,0,3,10,0,0},
                     {4,0,0,2,0,5,0},
                     {1,3,2,0,7,8,4},
                     {0,10,0,7,0,0,6},
                     {0,0,5,8,0,0,1},
                     {0,0,0,4,6,1,0}};

    prim(path, 7);

    return 0;
}
