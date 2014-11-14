#include<stdio.h>
#include<stdlib.h> 
#include<iostream>
#include<string>
#include<Windows.h>

#include "mainwindow.h"
#include "sender.h"
#include <QApplication>
#include<QObject>
#include<QThread>

#include"ctp/ThostFtdcMdApi.h"
#include"ctp/ThostFtdcTraderApi.h"

#include"../gpp_qt/cfg/cfg.h"
#include"../gpp_qt/bar/bar.h"
#include"../gpp_qt/bar/bars.h"
#include"../gpp_qt/wtimer/wtimer.h"
#include"../gpp_qt/bar/bars_manage.h"
#include"../gpp_qt/wfunction/wfunction.h"
#include"../gpp_qt/log_info/log_info.h"

#include"ctp_quote.h"
#include"ctp_quote_qthread.h"

using namespace std;

wtimer tm;
cfg simu_cfg;
log_info simu_log;
bars_manage simu_bars_manage;

MainWindow * mw;
QApplication * qa;

void start_ctp();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qa=&a;
    MainWindow w;
    mw=&w;

    //load simu para
    simu_cfg.setcfgfile("c:/cfg/simu_trade.cfg");

    //set para
    simu_bars_manage.addbarlist(simu_cfg.getparam("INSTRUMENT_ID"));
    simu_log.setfile("d:/record/"+wfunction::get_now_second()+".txt");
    w.set_symbols_display(simu_cfg.getparam("INSTRUMENT_ID"));

    w.show();

	return a.exec();
}


void start_ctp()
{

    mw->setWindowTitle(QString::fromStdString(simu_cfg.getparam("FEED_SOURSE")));

    qRegisterMetaType<string>("std::string");

    ctp_quote_qthread  * cqq=new ctp_quote_qthread;
    QObject::connect(cqq, &ctp_quote_qthread::broadcast_markerdata, mw,&MainWindow::show_quote_1);
    QObject::connect(cqq, &ctp_quote_qthread::broadcast_markerdata, mw,&MainWindow::show_quote_label);



    cqq->start();
    //    ctp_quote simu_quote;
}
