# ifndef _CALENDAR_SCHEDULER_H_
# define _CALENDAR_SCHEDULER_H_

//------------------------------
//ͷ�ļ�
//------------------------------
# include <stdio.h>
# include <string.h>   
# include <malloc.h>

//------------------------------
//���ú�
//------------------------------
# define TIMER_USE	

//------------------------------
//�ṹ������
//------------------------------
//�¼�����
enum EventType {
	ORDINARY = 0,		//��ͨ�¼�

# ifdef TIMER_USE 
	TIMER,				//��ʱ���¼�
#endif
};

//�¼���Ԫ
typedef struct EVENT {
	enum EventType type;			//�¼�����
	unsigned int time;				//�¼�ִ��ʱ��
	int	node_id;					//�¼�ִ����ID
	char *event_name;				//�¼�����
	void *src_data;					//�¼�Դ����
	void *dest_data;				//�¼�Ŀ������
	void *add_data;					//�¼���������
	void (*pfun)(struct EVENT *e);	//�¼�������
	struct EVENT *next;				//��һ���¼�ָ��
	struct EVENT *pre;				//��һ���¼�ָ��
}Event;

//����ָ��
typedef void (*FunPtr)(Event *e);

//�¼���Ԫ����ͷ
typedef struct EVENT_HEAD {
	unsigned int time;			//�¼�ִ��ʱ��
	struct EVENT_HEAD *next;	//��һ���¼���Ԫ����
	struct EVENT_HEAD *pre;		//��һ���¼���Ԫ����
	Event *head;				//�¼�����ͷָ��
	Event *tail;				//�¼�����βָ��
}EventHead;

//-----------------------------
//��������
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