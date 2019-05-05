#include <simplecpp>
void splitBubbles(int x,int y,int a[][6],int sign)
{
    if(x==0&&y==0)
    {
        if(abs(a[x][y])>=2)
        {
            a[x+1][y]=(abs(a[x+1][y])+1)*sign;
            a[x][y+1]=(abs(a[x][y+1])+1)*sign;
            a[x][y]=0;
            splitBubbles(x+1,y,a,sign);
            splitBubbles(x,y+1,a,sign);

        }
        else
        {
            return;
        }
    }
    else if(x==8&&y==0)
    {
        if(abs(a[x][y])>=2)
        {
            a[x-1][y]=(abs(a[x-1][y])+1)*sign;
            a[x][y+1]=(abs(a[x][y+1])+1)*sign;
            a[x][y]=0;
            splitBubbles(x-1,y,a,sign);
            splitBubbles(x,y+1,a,sign);

        }
        else
        {
            return;
        }
    }
    else if(y==5&&x==0)
    {
        if(abs(a[x][y])>=2)
        {
            a[x+1][y]=(abs(a[x+1][y])+1)*sign;
            a[x][y-1]=(abs(a[x][y-1])+1)*sign;
            a[x][y]=0;
            splitBubbles(x+1,y,a,sign);
            splitBubbles(x,y-1,a,sign);

        }
        else
        {
            return;
        }
    }
    else if(x==0)
    {
        if(abs(a[x][y])>=3)
        {
            a[x+1][y]=(abs(a[x+1][y])+1)*sign;
            a[x][y+1]=(abs(a[x][y+1])+1)*sign;
            a[x][y-1]=(abs(a[x][y-1])+1)*sign;
            a[x][y]=0;
            splitBubbles(x+1,y,a,sign);
            splitBubbles(x,y+1,a,sign);
            splitBubbles(x,y-1,a,sign);

        }
        else
        {
            return;
        }
    }
    else if(y==0)
    {
        if(abs(a[x][y])>=3)
        {
            a[x+1][y]=(abs(a[x+1][y])+1)*sign;
            a[x][y+1]=(abs(a[x][y+1])+1)*sign;
            a[x-1][y]=(abs(a[x-1][y])+1)*sign;
            a[x][y]=0;
            splitBubbles(x+1,y,a,sign);
            splitBubbles(x,y+1,a,sign);
            splitBubbles(x-1,y,a,sign);

        }
        else
        {
            return;
        }
    }
    else if(x==8&&y==5)
    {
        if(abs(a[x][y])>=2)
        {
            a[x-1][y]=(abs(a[x-1][y])+1)*sign;
            a[x][y-1]=(abs(a[x][y-1])+1)*sign;
            a[x][y]=0;
            splitBubbles(x-1,y,a,sign);
            splitBubbles(x,y-1,a,sign);

        }
        else
        {
            return;
        }
    }
    else if(x==8)
    {
        if(abs(a[x][y])>=3)
        {
            a[x][y-1]=(abs(a[x][y-1])+1)*sign;
            a[x][y+1]=(abs(a[x][y+1])+1)*sign;
            a[x-1][y]=(abs(a[x-1][y])+1)*sign;
            a[x][y]=0;
            splitBubbles(x,y-1,a,sign);
            splitBubbles(x,y+1,a,sign);
            splitBubbles(x-1,y,a,sign);

        }
        else
        {
            return;
        }
    }
    else if(y==5)
    {
        if(abs(a[x][y])>=3)
        {
            a[x+1][y]=(abs(a[x+1][y])+1)*sign;
            a[x-1][y]=(abs(a[x-1][y])+1)*sign;
            a[x][y-1]=(abs(a[x][y-1])+1)*sign;
            a[x][y]=0;
            splitBubbles(x+1,y,a,sign);
            splitBubbles(x,y-1,a,sign);
            splitBubbles(x-1,y,a,sign);

        }
        else
        {
            return;
        }
    }
    else
    {
        if(abs(a[x][y])>=4)
        {
            a[x+1][y]=(abs(a[x+1][y])+1)*sign;
            a[x][y+1]=(abs(a[x][y+1])+1)*sign;
            a[x-1][y]=(abs(a[x-1][y])+1)*sign;
            a[x][y-1]=(abs(a[x][y-1])+1)*sign;
            a[x][y]=0;
            splitBubbles(x+1,y,a,sign);
            splitBubbles(x,y+1,a,sign);
            splitBubbles(x-1,y,a,sign);
            splitBubbles(x,y-1,a,sign);

        }
        else
        {
            return;
        }
    }
}

bool check(int a[][6])
{
    int positive,negative;
    positive=negative=0;
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<6; j++)
        {
            if(a[i][j]>=0)positive ++;
            if(a[i][j]<=0)negative ++;
        }
    }
    if(positive==54|| negative==54) return true;
    else return false;
}

main_program
{
    int a[9][6];
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<6; j++)
        {
            a[i][j]=0;
        }
    }
    int x,y,playerCount=1;
    cin >> x;
    while(true)
    {
        cin >> y;
        if(x==-1)
        {
            return 0;
        }
        else if(x>=0&&x<9&&y>=0&&y<6)
        {
            if(playerCount%2==1&&a[x][y]>=0)
            {
                a[x][y]++;
                playerCount++;
                splitBubbles(x,y,a,1);
                for(int i=0; i<9; i++)
                {
                    for(int j=0; j<6; j++)
                    {
                        cout << a[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else if(playerCount%2==0&&a[x][y]<=0)
            {
                a[x][y]--;
                playerCount++;
                splitBubbles(x,y,a,-1);
                for(int i=0; i<9; i++)
                {
                    for(int j=0; j<6; j++)
                    {
                        cout << a[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else
            {
                cout << "Illegal Move" << endl<<endl;
            }
        }

        else
        {
            cout <<"Illegal Move"<<endl<<endl;
        }
        if(playerCount>2 && check(a))

        {
            break;
        }
        cin >> x;
    }

    return 0;
}

