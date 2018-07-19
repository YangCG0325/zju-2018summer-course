#include "model.h"

Model::Model()
{
    sp_Matrix = std::make_shared<SquareMatrix>();
}

Model::~Model()
{

}

std::shared_ptr<SquareMatrix> Model::getMatrix()
{
    return sp_Matrix;
}

void Model::newLayout(int mode)
{

    if(mode==1)
    {
        sp_Matrix->ResetMoode1();
    }
    if(mode==2)
    {
        sp_Matrix->setChildNumber(2,0,1);
    }
}

void Model::DirectionChange(int dir)
{
    int i, j, k, l, x, y;
    int flag;
    int array[4];

    if(dir==1)  //down
    {
        flag = 0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                array[j]=0;
            k=0;

            for(j=0;j<4;j++)  //get all the number not equal to 0
            {
                if(sp_Matrix->getChildNumber(3-j,i)!=0)
                    array[k++]=sp_Matrix->getChildNumber(3-j,i);
            }

            if(k==0)
            {
                ;
            }
            else if(k==1)
            {
                if(sp_Matrix->getChildNumber(3,i)==0)  //just one brick not equal to 0, can move only when end brick is 0
                    flag=1;
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(3-j,i,array[j]);         
            }
            else
            {
                for(j=0;j<3;j++)
                {
                    if(array[j]==array[j+1]&&array[j]!=0)  //more than 2 bricks, has near two equal, can move
                    {
                        flag=1;
                        array[j]=array[j]*2;
                        sp_Matrix->changeScore(array[j]);
                        for(l =j+1;l<3;l++)
                            array[l]=array[l+1];
                        array[3]=0;
                    }
                }
                if(k==2&&(sp_Matrix->getChildNumber(3,i)==0||sp_Matrix->getChildNumber(2,i)==0))
                    flag=1;
                if(k==3&&(sp_Matrix->getChildNumber(3,i)==0||sp_Matrix->getChildNumber(2,i)==0||sp_Matrix->getChildNumber(1,i)==0))
                    flag=1;

                for(j=0;j<4;j++)  //assign new number
                    sp_Matrix->setChildNumber(3-j,i,array[j]);
            }
        }

        if(flag==1)  //can move, then add new number to the matrix
        {
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
            x=qrand()%4;
            y=qrand()%4;
            while(sp_Matrix->getChildNumber(x,y)!=0)
            {
                x=qrand()%4;
                y=qrand()%4;
            }
            sp_Matrix->setChildNumber(x, y,2);
        }
    }

    if(dir==2)  //up
    {
        flag=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                array[j]=0;
            k=0;

            for(j=0;j<4;j++)
            {
                if(sp_Matrix->getChildNumber(j,i)!=0)
                    array[k++]=sp_Matrix->getChildNumber(j,i);
            }

            if(k==0)
                ;
            else if(k==1)
            {
                if(sp_Matrix->getChildNumber(0,i)==0)  //just one brick not equal to 0, can move only when end brick is 0
                    flag=1;
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(j,i,array[j]);              
            }
            else
            {
                for(j=0;j<3;j++)
                {
                    if(array[j]==array[j+1]&&array[j]!=0)
                    {
                        flag=1;
                        array[j]=array[j]*2;
                        sp_Matrix->changeScore(array[j]);
                        for(l =j+1;l<3;l++)
                            array[l]=array[l+1];
                        array[3]=0;
                    }
                }
                if(k==2&&(sp_Matrix->getChildNumber(0,i)==0||sp_Matrix->getChildNumber(1,i)==0))
                    flag=1;
                if(k==3&&(sp_Matrix->getChildNumber(0,i)==0||sp_Matrix->getChildNumber(1,i)==0||sp_Matrix->getChildNumber(2,i)==0))
                    flag=1;

                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(j,i,array[j]);
            }
        }
        if(flag==1)
        {
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
            x=qrand()%4;
            y=qrand()%4;
            while(sp_Matrix->getChildNumber(x,y)!=0)
            {
                x=qrand()%4;
                y=qrand()%4;
            }
            sp_Matrix->setChildNumber(x, y,2);
        }
    }

    if(dir==3)  //left
    {
        flag=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                array[j]=0;
            k=0;

            for(j=0;j<4;j++)
            {
                if(sp_Matrix->getChildNumber(i,j)!=0)
                    array[k++]=sp_Matrix->getChildNumber(i,j);
            }

            if(k==0)
                ;
            else if(k==1)
            {
                if(sp_Matrix->getChildNumber(i,0)==0)  //just one brick not equal to 0, can move only when end brick is 0
                    flag=1;
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(i,j,array[j]);           
            }
            else
            {
                for(j=0;j<3;j++)
                {
                    if(array[j]==array[j+1]&&array[j]!=0)
                    {
                        flag=1;
                        array[j]=array[j]*2;
                        sp_Matrix->changeScore(array[j]);
                        for(l =j+1;l<3;l++)
                            array[l]=array[l+1];
                        array[3]=0;
                    }
                }

                if(k==2&&(sp_Matrix->getChildNumber(i,0)==0||sp_Matrix->getChildNumber(i,1)==0))
                    flag=1;
                if(k==3&&(sp_Matrix->getChildNumber(i,0)==0||sp_Matrix->getChildNumber(i,1)==0||sp_Matrix->getChildNumber(i,2)==0))
                    flag=1;

                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(i,j,array[j]);
            }
        }
        if(flag==1)
        {
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
            x=qrand()%4;
            y=qrand()%4;
            while(sp_Matrix->getChildNumber(x,y)!=0)
            {
                x=qrand()%4;
                y=qrand()%4;
            }
            sp_Matrix->setChildNumber(x, y,2);
        }
    }

    if(dir==4)  //right
    {
        flag=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                array[j]=0;
            k=0;

            for(j=0;j<4;j++)
            {
                if(sp_Matrix->getChildNumber(i,3-j)!=0)
                    array[k++]=sp_Matrix->getChildNumber(i,3-j);
            }

            if(k==0)
                ;
            else if(k==1)
            {
                if(sp_Matrix->getChildNumber(i,3)==0)  //just one brick not equal to 0, can move only when end brick is 0
                    flag=1;
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(i,3-j,array[j]);              
            }
            else
            {
                for(j=0;j<3;j++)
                {
                    if(array[j]==array[j+1]&&array[j]!=0)
                    {
                        flag=1;
                        array[j]=array[j]*2;
                        sp_Matrix->changeScore(array[j]);
                        for(l =j+1;l<3;l++)
                            array[l]=array[l+1];
                        array[3]=0;
                    }
                }

                if(k==2&&(sp_Matrix->getChildNumber(i,3)==0||sp_Matrix->getChildNumber(i,2)==0))
                    flag=1;
                if(k==3&&(sp_Matrix->getChildNumber(i,3)==0||sp_Matrix->getChildNumber(i,2)==0||sp_Matrix->getChildNumber(i,1)==0))
                    flag=1;

                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(i,3-j,array[j]);
            }
        }
        if(flag==1)
        {
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
            x=qrand()%4;
            y=qrand()%4;
            while(sp_Matrix->getChildNumber(x,y)!=0)
            {
                x=qrand()%4;
                y=qrand()%4;
            }
            sp_Matrix->setChildNumber(x, y,2);
        }
    }
}


