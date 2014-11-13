#ifndef CTP_TRADE_H
#define CTP_TRADE_H

#include<./ctp/ThostFtdcTraderApi.h>
class ctp_trade:public
{
public:
    virtual void OnFrontConnected();
    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    virtual void OnFrontDisconnected(int nReason);
    virtual void OnHeartBeatWarning(int nTimeLapse);
    virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);
    virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);

    //
    void cmd();
    //������ѯ����
    void ReqQryOrder();
    //������ѯ
    void QryOrder();
    // �Ƿ��յ��ɹ�����Ӧ
    bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
    // �Ƿ��ҵı����ر�
    bool IsMyOrder(CThostFtdcOrderField *pOrder);
    // �Ƿ����ڽ��׵ı���
    bool IsTradingOrder(CThostFtdcOrderField *pOrder);


private:
    void ReqUserLogin();
    void ReqSettlementInfoConfirm();
    void ReqQryInstrument();
    void ReqQryTradingAccount();
    void ReqQryInvestorPosition();
    void ReqOrderInsert();
    void ReqOrderAction(CThostFtdcOrderField *pOrder);

};

#endif // CTP_TRADE_H
