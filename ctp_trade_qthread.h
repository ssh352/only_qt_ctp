#ifndef CTP_TRADE_QTHREAD
#define CTP_TRADE_QTHREAD
#include<QThread>
#include"ctp_trade.h"

#include"ctp_order_manager.h"

class ctp_trade_qthread :public QThread
{
	Q_OBJECT
public:
    bool check_init_para();
    ctp_trade * get_tradep(){return trade;}
    void init();

public slots:
    void delete_all_pending_order();
    void check_add_order(const std::string &,const std::string &,const std::string &,const std::string &,const std::string &);

signals:protected:
    void run();

private:
    ctp_trade * trade;
};
#endif
// *
// * 在这里创建tactic 在ctp_trade中包装好简单操作函数
// *
// * 针对ctp中各种On函数  回调tactic中相应函数
// *
// * 给tactic传递ctp_trade指针 进行收发单操作
// *
// *
// *
// *
// * 未来建议
// *
// * 是否可以通过signal来传递消息
// * /
