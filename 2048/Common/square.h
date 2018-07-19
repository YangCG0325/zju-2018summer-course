#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square
{
private:
    int number;
    std::string color;
public:
    Square()
    {
        number = 0;
        color = "0";
    }

    Square(int num)
    {
        number = num;
        color="";
        char str[10];
        sprintf(str,"%d",number);
        color+=str;
    }

    ~Square()
    {

    }

    void setColor()
    {
        color="";
        char str[10];
        sprintf(str,"%d",number);
        color+=str;
    }

    std::string getColor()
    {
        return color;
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
    Square gamebody[4][4];

public:
    SquareMatrix()
    {
        int i, j;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                gamebody[i][j].setNumber(0);
                gamebody[i][j].setColor();
            }
        }
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

    void setChildColor(int row, int col)
    {
        gamebody[row][col].setColor();
    }

    std::string getChildColor(int row, int col)
    {
        return gamebody[row][col].getColor();
    }

    void Reset()
    {
        int i, j;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
            {
                gamebody[i][j].setNumber(0);
                gamebody[i][j].setColor();
            }
    }
};
#endif // SQUARE_H
