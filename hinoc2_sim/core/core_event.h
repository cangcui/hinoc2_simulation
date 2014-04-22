# ifndef _CALENDAR_SCHEDULER_H_
# define _CALENDAR_SCHEDULER_H_

//------------------------------
//头文件
//------------------------------
# include <stdio.h>
# include <string.h>   
# include <malloc.h>

//------------------------------
//配置宏
//------------------------------
# define TIMER_USE	

//------------------------------
//结构体声明
//------------------------------
//事件类型
enum EventType {
	ORDINARY = 0,		//普通事件

# ifdef TIMER_USE 
	TIMER,				//定时器事件
#endif
};

//事件单元
typedef struct EVENT {
	enum EventType type;			//事件类型
	unsigned int time;				//事件执行时间
	int	node_id;					//事件执行者ID
	char *event_name;				//事件名称
	void *src_data;					//事件源数据
	void *dest_data;				//事件目的数据
	void *add_data;					//事件附加数据
	void (*pfun)(struct EVENT *e);	//事件处理函数
	struct EVENT *next;				//下一个事件指针
	struct EVENT *pre;				//上一个事件指针
}Event;

//函数指针
typedef void (*FunPtr)(Event *e);

//事件单元队列头
typedef struct EVENT_HEAD {
	unsigned int time;			//事件执行时间
	struct EVENT_HEAD *next;	//下一个事件单元队列
	struct EVENT_HEAD *pre;		//上一个事件单元队列
	Event *head;				//事件队列头指针
	Event *tail;				//事件队列尾指针
}EventHead;

//-----------------------------
//函数声明
//-----------------------------
void gen_ordinary(int delay, int id, char *name, void *s_data, void *d_data, void *a_data, FunPtr fun_ptr);
void run(void);
unsigned int get_time(void);
void set_time(unsigned int time);
EventHead **get_list_head(void);
EventHead **get_list_tail(void);

# ifdef TIMER_USE
Event *gen_timer(int id, char *name, void *s_data, void *d_data, void *a_data, FunPtr fun_ptr);
void start_timer(Event *timer, int delay);
void restart_timer(Event *timer, int delay);
void cancel(Event *e);
void delete_timer(Event *timer);
# endif


# endif