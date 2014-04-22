//---------------------
//名称：队列
//说明：主要负责数据在存储转发时的
//		一系列过程，包括维护cache队列、
//		待发送队列、已发送队列、已接收队列、
//		丢弃队列等。某些情况下要将此模块细化为：
//		入出队模块和收发模块
//--------------------

# ifndef _QUEUE_MNG_H_
# define _QUEUE_MNG_H_

//---------------------
//头文件
//---------------------
# include "user_setting.h"


//--------------------
//全局变量声明
//--------------------
extern Queue received_up_queue[HM_NUM][PRIO_NUM];
extern Queue received_down_queue[HM_NUM][PRIO_NUM];

//--------------------
//函数声明
//--------------------
void enqueue_up(Event *e);
void enqueue_down(Event *e);
void send_up(Event *e);
void send_down(Event *e);
void recv_up(Event *e);
void recv_down(Event *e);

# endif