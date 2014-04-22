# ifndef _BASIC_QUEUE_H_
# define _BASIC_QUEUE_H_

//----------------
//头文件
//----------------
# include <stdio.h>
# include <string.h>
# include <malloc.h>

//----------------
//结构声明
//----------------
//数据包
typedef struct PACKET {
	int serial_num;		//序号
	int length;			//长度
	int arrive_time;	//到达时间
	int prio;			//优先级
	int delay;			//时延
	void *add_info;		//扩展信息
	struct PACKET *next;//指针
}Packet;

//队列
typedef struct QUEUE {
	int max_length;		//最大队列长度
	int queue_length;	//当前队列长度
	int packet_num;		//当前队列包个数
	int	prio;			//队列优先级
	void *add_info;		//扩展信息
	Packet *head;		//队列头指针
	Packet *tail;		//队列尾指针
}Queue;

//------------------
//函数声明
//------------------
void enque(Queue *queue, Packet *packet);
Packet *deque(Queue *queue);

# endif