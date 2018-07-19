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
    int i, j, x, y;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    if(mode==1)
    {
        i = qrand()%4;
        j = qrand()%4;
        x = qrand()%4;
        y = qrand()%4;
        while(x==i && y == j)
        {
            x = qrand()%4;
            y = qrand()%4;
        }
        sp_Matrix->setChildNumber(i,j,2);
        sp_Matrix->setChildColor(i,j);
        sp_Matrix->setChildNumber(x,y,2);
        sp_Matrix->setChildColor(x,y);
    }
    if(mode==2)
    {
        sp_Matrix->setChildNumber(2,0,1);
        sp_Matrix->setChildColor(2,0);
    }
}

void Model::DirectionChange(int dir)
{
    int i, j, k, l, x;
    if(dir==1)  //down
    {
        int array[4];
        int result[4];
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                array[j]=0;
            k=0;

            for(j=0;j<4;j++)
            {
                if(sp_Matrix->getChildNumber(3-j,i)!=0)
                    array[k++]=sp_Matrix->getChildNumber(3-j,i);
            }

            if(k==0)
                ;
            else if(k==1)
            {
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(3-j,i,array[j]);
            }
            else
            {
                for(j=0;j<3;j++)
                {
                    if(array[j]==array[j+1])
                    {
                        array[j]=array[j]*2;
                        for(l =j+1;l<3;l++)
                            array[l]=array[l+1];
                        array[3]=0;
                    }
                }
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(3-j,i,array[j]);
            }
        }
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        x=qrand()%4;
        while(sp_Matrix->getChildNumber(0,x)!=0)
            x=qrand()%4;
        sp_Matrix->setChildNumber(0,x,2);
    }
    if(dir==2)  //up
    {
        int array[4];
        int result[4];
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
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(j,i,array[j]);
            }
            else
            {
                for(j=0;j<3;j++)
                {
                    if(array[j]==array[j+1])
                    {
                        array[j]=array[j]*2;
                        for(l =j+1;l<3;l++)
                            array[l]=array[l+1];
                        array[3]=0;
                    }
                }
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(j,i,array[j]);
            }
        }
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        x=qrand()%4;
        while(sp_Matrix->getChildNumber(3,x)!=0)
            x=qrand()%4;
        sp_Matrix->setChildNumber(3,x,2);
    }
    if(dir==3)  //left
    {
        int array[4];
        int result[4];
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
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(i,j,array[j]);
            }
            else
            {
                for(j=0;j<3;j++)
                {
                    if(array[j]==array[j+1])
                    {
                        array[j]=array[j]*2;
                        for(l =j+1;l<3;l++)
                            array[l]=array[l+1];
                        array[3]=0;
                    }
                }
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(i,j,array[j]);
            }
        }
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        x=qrand()%4;
        while(sp_Matrix->getChildNumber(x,3)!=0)
            x=qrand()%4;
        sp_Matrix->setChildNumber(x,3,2);
    }
    if(dir==4)  //right
    {
        int array[4];
        int result[4];
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
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(i,3-j,array[j]);
            }
            else
            {
                for(j=0;j<3;j++)
                {
                    if(array[j]==array[j+1])
                    {
                        array[j]=array[j]*2;
                        for(l =j+1;l<3;l++)
                            array[l]=array[l+1];
                        array[3]=0;
                    }
                }
                for(j=0;j<4;j++)
                    sp_Matrix->setChildNumber(i,3-j,array[j]);
            }
        }
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        x=qrand()%4;
        while(sp_Matrix->getChildNumber(x,0)!=0)
            x=qrand()%4;
        sp_Matrix->setChildNumber(x,0,2);
    }

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            sp_Matrix->setChildColor(i,j);
}


