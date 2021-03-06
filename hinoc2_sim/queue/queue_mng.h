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
# define UP   0
# define DOWN 1
//---------------------
//头文件
//---------------------
# include "../user_setting.h"
# include "../core/core_event.h"

//每个队列仅保存队列指针
//*(hm_queue.cache_queue[PRIO_ID][UP|DOWN]).head;
// 数组指针，orign_queue[HM_ID][2][PRIO_NUM], 或*(orign_queue+1)[2][PRIO_NUM]

typedef struct HBQueue {
	Queue (*origin_queue)[2][PRIO_NUM];
	Queue (*cache_queue)[2][PRIO_NUM];
	Queue (*sending_queue)[2][PRIO_NUM];
	Queue (*received_queue)[2][PRIO_NUM];
}HBQueue;

typedef struct HMQueue {
	Queue origin_queue[2][PRIO_NUM];
	Queue cache_queue[2][PRIO_NUM];
	Queue sending_queue[2][PRIO_NUM];
	Queue received_queue[2][PRIO_NUM];
}HMQueue;

//生成orign_queue

//入队cache_queue

//调度允许后sending

//
/*
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
*/
# endif