﻿#if !defined(AFX_CDBPROCESS_H__82075B33_D9D7_42AC_B4A1_46D07A744066__INCLUDED_)
#define AFX_CDBPROCESS_H__82075B33_D9D7_42AC_B4A1_46D07A744066__INCLUDED_

/************************************************************************
*Description:                                                           *
*Author: realfan                                                        *
*Date of Created:                                                       *
*Date of Modified      Purpose of Modify       Person Name of Modify    *
*------------------  ----------------------  -------------------------  *
*                                                                       *
************************************************************************/
#include <QString>
#include "stdarg.h"
#include <QMap>
class QSqlDatabase;
class QSqlQuery;
class CDBProcess
{
public:

    CDBProcess(const QString strType); //sqlite  mysql  access sqlserver
    virtual ~CDBProcess();
    static const char * szEnd;

public:
    bool openDB(const QString strSvrName,
                const QString strDBname,
                const QString strUserID="",
                const QString strUserPwd="");

    void closeDB();
    bool excuteSQL(const QString);
    bool openRecordsetBySql(const QString strSql, int idx = -1);
    void closeRecordset(int idx = -1);
    bool isOpen() const;
    bool recEOF(int idx = -1) const;
    bool recBOF(int idx = -1) const;

    bool dropTable(const QString);
    //QStringList GetTableNames();
    //========读取==================================
    bool getFieldsValueFromRec(int idx, const char* szFldInfo, ...) const;
    bool addFieldsValueToTbl(const QString strTbl, const char* szFldInfo, ...);
    bool updateTblFieldsValue(const QString strTbl, QString strWhere, const char * szFldInfo, ... );
    long getRecordCount(int idx = -1) const;
    bool moveFirst(int idx = -1) const;
    bool movePrevious(int idx = -1) const;
    bool moveNext(int idx = -1) const;
    bool moveLast(int idx = -1) const;
    bool moveTo(int n, int idx = -1) const;

    bool execStoreProcOfArgList(int idx, const QString strStoreProc, const char* szFldsInfo, ...);
    bool exexProc(const QString strStoreProc, QString str1, QString& str2);
    bool transaction();
    bool commit();
    bool rollback();
    QString getDbName() const {return __strDbName;}
protected:
    bool __openMDB(const QString strMDBname, QString strUserID = "sa", const QString strPassword = "");
    bool __openMDBByUDL(const QString strUDL);
    bool __connectSqlServer(const QString strSvrName, const QString strDBname, const QString strUserID, const QString strUserPwd);
    bool __openSqlite(const QString & strDbName);
    bool __openMySql(QString strSvrName, const QString strDBname, QString strUserID, const QString strUserPwd);

    //void getQryByIndex(QSqlQuery* & pQry, int idx = -1);
private:
    QSqlDatabase * m_pDB;
    QString __strConnName;
    QMap<int, QSqlQuery *> m_mapQry;
    QString __strDbType;
    QString __strDbName;
};
#endif
