//---------------------------
//名称：离散事件调度器
//作者：孙文
//日期：20121130
//说明：为协议仿真提供统一的时间调度器，事件精度任意
//版本：v1.0---20131130
//		完成调度器的基本功能
//		v1.1---20131204
//		完善事件入队操作，提供外部访问私有变量接口
//		v1.2---20131205
//		加入定时器功能	
//---------------------------

//---------------------------
//头文件
//---------------------------
# include "core_event.h"

//---------------------------
//局部全局数据
//---------------------------
static unsigned int now_time;		//当前时刻
static unsigned int stop_time;		//仿真结束时间
static EventHead *event_list_head;	//事件单元队列链表头
static EventHead *event_list_tail;	//事件单元队列链表尾

//-------------------------
//名称：插入一个事件
//输入：e---事件单元
//输出：无
//说明：在生成一个事件单元后通过此函数将其加入事件队列
//------------------------
static void insert(Event *e)
{
	EventHead *new_head = NULL;				//新的事件单元头
	EventHead *list_tail = event_list_tail;	//事件单元队列链表尾

	//事件单元为空
	if (NULL == e)	
		printf("param error in insert()!\n");

	//事件发生时间小于当前时间
	if (e->time < now_time)
		printf("time error in insert()!\n");


	//内存分配
	if (!(new_head = (EventHead *)malloc(sizeof(EventHead))))	
		printf("no memory for new_head in insert()!\n");

	//如果此时刻没有任何待处理事件
	if (NULL == list_tail)
	{
		//事件单元队列链表操作
		event_list_head = new_head;
		event_list_tail = new_head;

		//事件单元队列操作
		new_head->head = e;
		new_head->tail = e;
		new_head->next = NULL;
		new_head->pre = NULL;
		new_head->time = e->time;
	}
	else //有正在等待处理的事件，从尾部寻找要插入的事件单元队列
	{
		//索引至相同时刻单元
		while (list_tail->time > e->time && list_tail != event_list_head)
		{
			list_tail = list_tail->pre;
		}

		//该时刻事件单元队列不存在
		if (list_tail->time != e->time)
		{
			//插入事件单元队列双向链表
			//插入list_tail前面，链表头
			if (list_tail->time > e->time)	
			{
				list_tail->pre = new_head;
				new_head->next = list_tail;
				new_head->pre = NULL;

				event_list_head = new_head;
			}
			else	//插入list_tail后面
			{
				//尾部插入
				if (list_tail->next != NULL)
					list_tail->next->pre = new_head;

				new_head->next = list_tail->next;
				list_tail->next = new_head;
				new_head->pre = list_tail;
				
				//尾部插入
				if (new_head->next == NULL)
					event_list_tail = new_head;
			}

			//事件单元队列操作
			new_head->head = e;
			new_head->tail = e;
			new_head->time = e->time;
		}
		else	//该时刻事件单元队列存在
		{
			//入队尾
			list_tail->tail->next = e;
			e->pre = list_tail->tail;
			list_tail->tail = e;

			//释放内存
			free((void*)new_head);
		}
	}
}

//----------------
//名称：事件出队
//输入：无
//输出：事件句柄
//说明：从事件单元队列链表里将最近发生的事件出队
//----------------
static Event *deque(void)
{
	Event *first_event = NULL;				//第一个事件
	EventHead *list_head = event_list_head;	//事件单元队列链表头

	//如果还有事件，取出第一个事件
	if (NULL != list_head)
		first_event = list_head->head;
	else
		return (Event*)0;

	//该事件单元队列仅一个事件
	if (list_head->head == list_head->tail)
	{
		//还有多个事件单元队列
		if (event_list_head != event_list_tail)
		{
			//指向下一个事件队列
			event_list_head = list_head->next;

			//断开第一个队列
			list_head->next->pre = NULL;
			list_head->next = NULL;
		}
		else	//最后一个事件队列
		{
			event_list_head = event_list_tail = NULL;
		}
		//释放执行完毕的事件单元队列
		free((void*)list_head);
		
	}
	else	//该事件单元队列有多个事件
	{
		list_head->head = list_head->head->next;
		list_head->head->pre = NULL;
		first_event->next = NULL;
	}

	return first_event;
}

//---------------------
//名称：执行事件函数
//输入：e---事件单元指针
//输出：无
//说明：修改仿真时钟，并执行事件函数
//---------------------
static void dispatch(Event *e)
{
	//修改当前时刻
	now_time = e->time;

	//时间判定
	if (now_time > stop_time)
		return;
	
	//运行事件执行函数
	e->pfun(e);

	//普通事件，释放内存
	if (ORDINARY == e->type)
		free((void*)e);
}

//-----------------------------
//名称：生成事件单元
//输入：type----事件类型
//		delay---事件发生前等待时间
//		id------节点ID，为此节点的事件
//		s_data--事件输入参数
//		d_data--事件输出参数
//		a_data--事件附加参数
//		fun_ptr-事件执行函数
//输出：生成的事件单元指针
//说明：根据需求生成不同的事件单元
//-----------------------------
static Event *gen_event(enum EventType type, int delay, int id, char *name, void *s_data, void *d_data, void *a_data, FunPtr fun_ptr)
{
	Event *new_event = NULL;	//新事件单元

	//事件ID不合法
	if (id < 0)	
		printf("id error in gen_event()!\n");

	//时间不合法
	if (delay < 0)
		printf("delay error in gen_event()!\n");
	
	//申请事件单元内存
	if (!(new_event = (Event *)malloc(sizeof(Event))))
		printf("no memory for new_event in gen_event()!\n");

	//填充内部成员
	new_event->type = type;
	new_event->time = now_time+delay;
	new_event->node_id = id;
	new_event->event_name = name;
	new_event->src_data = s_data;
	new_event->dest_data = d_data;
	new_event->add_data = a_data;
	new_event->pfun = fun_ptr;
	new_event->next = NULL;
	new_event->pre = NULL;

	return new_event;
}

//-----------------------
//名称：生成普通事件
//输入：delay---事件发生前等待时间
//		id------节点ID，为此节点的事件
//		s_data--事件输入参数
//		d_data--事件输出参数
//		a_data--事件附加参数
//		fun_ptr-事件执行函数
//输出：无
//说明：普通事件仅执行一次便被释放掉，即对其没有后续操作
//		则无需获取其事件单元指针。
//-----------------------
void gen_ordinary(int delay, int id, char *name, void *s_data, void *d_data, void *a_data, FunPtr fun_ptr)
{
	Event *new_event = NULL;

	//生成新事件单元
	new_event = gen_event(ORDINARY, delay, id, name, s_data, d_data, a_data, fun_ptr);

	//事件单元入队
	insert(new_event);
}

# ifdef TIMER_USE 
//-----------------------------
//名称：生成定时器事件
//输入：id------节点ID，为此节点的定时器
//		s_data--定时器输入参数
//		d_data--定时器输出参数
//		a_data--定时器附加参数
//		fun_ptr-定时器溢出执行函数
//输出：定时器事件指针
//说明：定时器的其他操作都是以其句柄为参数的，需要返回定时器指针
//-----------------------------
Event *gen_timer(int id, char *name, void *s_data, void *d_data, void *a_data, FunPtr fun_ptr)
{
	return gen_event(TIMER, 0, id, name, s_data, d_data, a_data, fun_ptr);
}

//--------------------------
//名称：开启定时器
//输入：timer---定时器句柄
//		delay---定时时长
//输出：无
//说明：开启定时器即将其加入事件链表，等待调度执行
//--------------------------
void start_timer(Event *timer, int delay)
{
	timer->time = now_time+delay;

	//定时器事件入队
	insert(timer);
}

//-------------------------
//名称：重启定时器
//输入：timer---定时器句柄
//		delay---定时时长
//输出：无
//说明：如果需要某个事件周期执行，在其定时器溢出函数中
//		需要调用此函数，再一次安排定时器事件。
//--------------------------
void restart_timer(Event *timer, int delay)
{
	start_timer(timer, delay);
}

//------------------------
//名称：取消事件
//输入：事件单元指针
//输出：无
//说明：暂时觉得，仅在使用定时器时需要使用此函数
//------------------------
void cancel(Event *e)
{
	EventHead *list_head = event_list_head;	//事件单元队列链表头

	//所引导事件单元队列，要么时间相等，要么指向尾部
	while (list_head->time < e->time && list_head != event_list_tail)
		list_head = list_head->next;

	//此时依旧不相等，时间不存在事件链表中
	if (list_head->time != e->time)
		printf("no such event in list in cancel()!\n");

	//头部事件
	if (list_head->head == e)
	{
		//同时是最后一个事件，需要删除此事件单元队列头
		if (NULL == e->next)
		{
			//头部事件单元队列头
			if (list_head == event_list_head)
			{
				//同时是最后一个事件单元队列头
				if (NULL == list_head->next)
					event_list_head = event_list_tail = NULL;
				else	//后面还有多个事件单元队列头
				{
					event_list_head = list_head->next;
					event_list_head->pre = NULL;
				}

				list_head->next = NULL;
			}
			else if (list_head == event_list_tail)	//尾部事件单元队列头
			{
				event_list_tail = list_head->pre;
				event_list_tail->next = NULL;
				list_head->pre = NULL;
			}
			else	//中间某个事件单元队列头
			{
				list_head->pre->next = list_head->next;
				list_head->next->pre = list_head->pre;
				list_head->next = list_head->pre = NULL;
			}

			free((void*)list_head);
			return;
		}

		//后面还有多个事件
		list_head->head = list_head->head->next;
		list_head->head->pre = NULL;
		e->next = NULL;
	}
	else if (list_head->tail == e)	//尾部事件
	{
		list_head->tail = list_head->tail->pre;
		list_head->tail->next = NULL;
		e->pre = NULL;
	}
	else	//中间某个事件
	{
		e->pre->next = e->next;
		e->next->pre = e->pre;
		e->pre = e->next = NULL;
	}
}

//--------------------------
//名称：删除定时器
//输入：timer---定时器句柄
//输出：无
//说明：在删除定时器前，必须先调用cancel，
//		以确保其不在事件队列中。
//--------------------------
void delete_timer(Event *timer)
{
	free((void*)timer);
}
# endif

//--------------------------
//名称：运行调度器
//输入：无
//输出：无
//说明：运行整个仿真
//-------------------------
void run(void)
{
	Event *e = NULL;

	//上一个事件未到终止时刻 且 有事件
	while ((now_time <= stop_time) && (e = deque()))	
		dispatch(e);

	printf("Simulation Finished.\n");
}

//-------------------------
//名称：获取当前时间
//输入：无
//输出：当前时刻
//说明：获取时间
//-------------------------
unsigned int get_time(void)
{
	return now_time;
}

//-------------------------
//名称：设置仿真结束事件
//输入：结束时间
//输出：无
//说明：设置结束时间
//-------------------------
void set_time(unsigned int time)
{
	stop_time = time;
}

//-------------------------
//名称：获取链表头
//输入：无
//输出：链表头指针
//说明：获取事件单元队列双向链表头指针的地址
//-------------------------
EventHead **get_list_head(void)
{
	return &event_list_head;
}

//-------------------------
//名称：获取链表尾
//输入：无
//输出：链表尾指针
//说明：获取事件单元队列双向链表尾指针的地址
//-------------------------
EventHead **get_list_tail(void)
{
	return &event_list_tail;
}