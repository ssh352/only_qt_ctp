#ifndef CTP_TRADE
#define CTP_TRADE
#include "../libs/ctp/ThostFtdcTraderApi.h"
#include<string>
#include<map>

class ctp_trade_qthread;
class ctp_trade : public CThostFtdcTraderSpi
{
public:
	ctp_trade();
	ctp_trade(ctp_trade_qthread *);
    void init();//set con file  dir
    char * mk_trade_con_dir();

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

private:
    void ReqQryOrder(const std::string &);
    void ReqQryOrder(const std::string &,bool);
    void ReqQryInstrument(const std::string & );
    void ReqQryInstrument(const std::string & ,bool);
    void ReqQryInvestorPosition(const std::string &);
    void ReqQryInvestorPosition(const std::string & ,bool);

	void ReqQryTradingAccount(bool);
    void ReqQryTradingAccount();
    bool IsFlowControl(int );
    bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
    bool IsMyOrder(CThostFtdcOrderField *pOrder);
    bool IsTradingOrder(CThostFtdcOrderField *pOrder);
    void ReqUserLogin();
    void ReqSettlementInfoConfirm();
    void ReqQryInvestorPosition();
	
	void ReqOrderInsert(CThostFtdcInputOrderField *);
	CThostFtdcInputOrderField * initorder(const std::string & InstrumentID, const std::string & side, const std::string & openclose, double price, long size);
	void ReqOrderAction(CThostFtdcInputOrderActionField *pOrder);
	CThostFtdcInputOrderActionField * initorderchange(const std::string & ordername);
	void change_order(const std::string & ordername, double price, long size);
	void delete_order(const std::string & ordername);

	void add_order_ref(TThostFtdcOrderRefType);

    CThostFtdcTraderApi				* pUserApi;
    CThostFtdcReqUserLoginField		* req;
    TThostFtdcFrontIDType           FRONT_ID;
    TThostFtdcSessionIDType         SESSION_ID;
    TThostFtdcOrderRefType          NowOrderRef;
    TThostFtdcOrderRefType          MaxOrderRef;

    long iRequestID;
    int maxdelaytime;
	//可以添加iRequestID对应的map 以便于查询order状态
    std::map<std::string,CThostFtdcOrderField*> ordermap;


	ctp_trade_qthread * ptfather ;

};
#endif // CTP_TRADE_H
