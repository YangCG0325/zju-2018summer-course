#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <QTime>
#include <QtGlobal>

class Square
{
private:
    int number;
public:
    Square()
    {
        number = 0;
    }

    Square(int num)
    {
        number = num;
    }

    ~Square()
    {

    }

    void setNumber(int num)
    {
        number = num;
    }
    int getNumber() const
    {
        return number;
    }
};

class SquareMatrix
{
private:
    int Score;
    int Best;
    Square gamebody[4][4];
    int position[16];  //position change record in one operation
    bool Lose;
    bool Win;

public:
    SquareMatrix()
    {
        int i, j;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                gamebody[i][j].setNumber(0);
            }
        }
        Score = 0;
        Best = 0;
        for(i=0;i<16;i++)
            position[i]=i;
        Lose = 0;
        Win = 0;
    }

    ~SquareMatrix()
    {

    }

    void setChildNumber(int row, int col, int num)
    {
        gamebody[row][col].setNumber(num);
    }

    int getChildNumber(int row,int col)
    {
        return gamebody[row][col].getNumber();
    }

    void changeScore(int add)
    {
        Score+=add;
        if(Score>Best)
            Best=Score;
    }

    int getScore()
    {
        return Score;
    }

    int getBest()
    {
        return Best;
    }

    void setPos(int brick,int pos)
    {
        position[brick] = pos;
    }

    void resetPos()
    {
        int i;
        for(i=0;i<16;i++)
            position[i] = i;
    }

    int getPos(int brick)
    {
        return position[brick];
    }

    void setWin(bool s)
    {
        Win = s;
    }

    void setLose(bool s)
    {
        Lose = s;
    }

    bool LoseSignal()
    {
        return Lose;
    }

    bool WinSignal()
    {
        return Win;
    }
    void ResetMoode1()  //classic mode reset
    {
        int i, j, x, y;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
            {
                gamebody[i][j].setNumber(0);
            }
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        i = qrand()%4;
        j = qrand()%4;
        x = qrand()%4;
        y = qrand()%4;
        while(x==i && y == j)
        {
            x = qrand()%4;
            y = qrand()%4;
        }
        setChildNumber(i,j,-2);
        setChildNumber(x,y,-2);
        Score=0;
        Win = 0;
        Lose = 0;
    }
    void ResetMode2()  //flappy mode reset
    {
        int i, j;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
            {
                gamebody[i][j].setNumber(0);
            }

        Score=0;
    }
};
#endif // SQUARE_H
