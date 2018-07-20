#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <QtGlobal>
#include <QTime>
#include "Common/etlbase.h"
#include "Common/square.h"
#include <QMessageBox>


class Model : public Proxy_PropertyNotification<Model>, public Proxy_CommandNotification<Model>
{
public:
    Model();
    ~Model();
    std::shared_ptr<SquareMatrix> getMatrix(); //return data
    void newLayout(int mode);  //assign page according to mode
    void DirectionChange(int dir);
private:
    std::shared_ptr<SquareMatrix> sp_Matrix;  //data structure, 4*4 array, each node include number(int)
};

#endif // MODEL_H
