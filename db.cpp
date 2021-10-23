#include "db.h"

#include <QSqlDatabase>
#include <QSqlQuery>

db::db()
{
    m_db=QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("pass_manager.db");
    if(!m_db.isOpen())
        m_db.open();
    if(!m_db.isOpen())
    {
        qDebug()<<"db cannot open";
    }



}


int db::execute(QString query){

    QSqlQuery m_qu= QSqlQuery(m_db);
    if(!m_qu.exec(query)){
        qDebug()<<"add:error :";
        return 0;
    }
    return   m_qu.lastInsertId().toInt();
}

