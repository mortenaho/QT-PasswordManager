#ifndef DB_H
#define DB_H

#include <qsqldatabase.h>




class db
{
public:
    QSqlDatabase m_db;
    db();
    void connect();
    int execute(QString query);


};

#endif // DB_H
