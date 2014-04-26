//---------------------------
//���ƣ���ɢ�¼�������
//���ߣ�����
//���ڣ�20121130
//˵����ΪЭ������ṩͳһ��ʱ����������¼���������
//�汾��v1.0---20131130
//		��ɵ������Ļ�������
//		v1.1---20131204
//		�����¼���Ӳ������ṩ�ⲿ����˽�б����ӿ�
//		v1.2---20131205
//		���붨ʱ������	
//---------------------------

//---------------------------
//ͷ�ļ�
//---------------------------
# include "core_event.h"

//---------------------------
//�ֲ�ȫ������
//---------------------------
static unsigned int now_time;		//��ǰʱ��
static unsigned int stop_time;		//�������ʱ��
static EventHead *event_list_head;	//�¼���Ԫ��������ͷ
static EventHead *event_list_tail;	//�¼���Ԫ��������β

//-------------------------
//���ƣ�����һ���¼�
//���룺e---�¼���Ԫ
//�������
//˵����������һ���¼���Ԫ��ͨ���˺�����������¼�����
//------------------------
static void insert(Event *e)
{
	EventHead *new_head = NULL;				//�µ��¼���Ԫͷ
	EventHead *list_tail = event_list_tail;	//�¼���Ԫ��������β

	//�¼���ԪΪ��
	if (NULL == e)	
		printf("param error in insert()!\n");

	//�¼�����ʱ��С�ڵ�ǰʱ��
	if (e->time < now_time)
		printf("time error in insert()!\n");


	//�ڴ����
	if (!(new_head = (EventHead *)malloc(sizeof(EventHead))))	
		printf("no memory for new_head in insert()!\n");

	//�����ʱ��û���κδ������¼�
	if (NULL == list_tail)
	{
		//�¼���Ԫ�����������
		event_list_head = new_head;
		event_list_tail = new_head;

		//�¼���Ԫ���в���
		new_head->head = e;
		new_head->tail = e;
		new_head->next = NULL;
		new_head->pre = NULL;
		new_head->time = e->time;
	}
	else //�����ڵȴ�������¼�����β��Ѱ��Ҫ������¼���Ԫ����
	{
		//��������ͬʱ�̵�Ԫ
		while (list_tail->time > e->time && list_tail != event_list_head)
		{
			list_tail = list_tail->pre;
		}

		//��ʱ���¼���Ԫ���в�����
		if (list_tail->time != e->time)
		{
			//�����¼���Ԫ����˫������
			//����list_tailǰ�棬����ͷ
			if (list_tail->time > e->time)	
			{
				list_tail->pre = new_head;
				new_head->next = list_tail;
				new_head->pre = NULL;

				event_list_head = new_head;
			}
			else	//����list_tail����
			{
				//β������
				if (list_tail->next != NULL)
					list_tail->next->pre = new_head;

				new_head->next = list_tail->next;
				list_tail->next = new_head;
				new_head->pre = list_tail;
				
				//β������
				if (new_head->next == NULL)
					event_list_tail = new_head;
			}

			//�¼���Ԫ���в���
			new_head->head = e;
			new_head->tail = e;
			new_head->time = e->time;
		}
		else	//��ʱ���¼���Ԫ���д���
		{
			//���β
			list_tail->tail->next = e;
			e->pre = list_tail->tail;
			list_tail->tail = e;

			//�ͷ��ڴ�
			free((void*)new_head);
		}
	}
}

//----------------
//���ƣ��¼�����
//���룺��
//������¼����
//˵�������¼���Ԫ���������ｫ����������¼�����
//----------------
static Event *deque(void)
{
	Event *first_event = NULL;				//��һ���¼�
	EventHead *list_head = event_list_head;	//�¼���Ԫ��������ͷ

	//��������¼���ȡ����һ���¼�
	if (NULL != list_head)
		first_event = list_head->head;
	else
		return (Event*)0;

	//���¼���Ԫ���н�һ���¼�
	if (list_head->head == list_head->tail)
	{
		//���ж���¼���Ԫ����
		if (event_list_head != event_list_tail)
		{
			//ָ����һ���¼�����
			event_list_head = list_head->next;

			//�Ͽ���һ������
			list_head->next->pre = NULL;
			list_head->next = NULL;
		}
		else	//���һ���¼�����
		{
			event_list_head = event_list_tail = NULL;
		}
		//�ͷ�ִ����ϵ��¼���Ԫ����
		free((void*)list_head);
		
	}
	else	//���¼���Ԫ�����ж���¼�
	{
		list_head->head = list_head->head->next;
		list_head->head->pre = NULL;
		first_event->next = NULL;
	}

	return first_event;
}

//---------------------
//���ƣ�ִ���¼�����
//���룺e---�¼���Ԫָ��
//�������
//˵�����޸ķ���ʱ�ӣ���ִ���¼�����
//---------------------
static void dispatch(Event *e)
{
	//�޸ĵ�ǰʱ��
	now_time = e->time;

	//ʱ���ж�
	if (now_time > stop_time)
		return;
	
	//�����¼�ִ�к���
	e->pfun(e);

	//��ͨ�¼����ͷ��ڴ�
	if (ORDINARY == e->type)
		free((void*)e);
}

//-----------------------------
//���ƣ������¼���Ԫ
//���룺type----�¼�����
//		delay---�¼�����ǰ�ȴ�ʱ��
//		id------�ڵ�ID��Ϊ�˽ڵ���¼�
//		s_data--�¼��������
//		d_data--�¼��������
//		a_data--�¼����Ӳ���
//		fun_ptr-�¼�ִ�к���
//��������ɵ��¼���Ԫָ��
//˵���������������ɲ�ͬ���¼���Ԫ
//-----------------------------
static Event *gen_event(enum EventType type, int delay, int id, char *name, void *s_data, void *d_data, void *a_data, FunPtr fun_ptr)
{
	Event *new_event = NULL;	//���¼���Ԫ

	//�¼�ID���Ϸ�
	if (id < 0)	
		printf("id error in gen_event()!\n");

	//ʱ�䲻�Ϸ�
	if (delay < 0)
		printf("delay error in gen_event()!\n");
	
	//�����¼���Ԫ�ڴ�
	if (!(new_event = (Event *)malloc(sizeof(Event))))
		printf("no memory for new_event in gen_event()!\n");

	//����ڲ���Ա
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
//���ƣ�������ͨ�¼�
//���룺delay---�¼�����ǰ�ȴ�ʱ��
//		id------�ڵ�ID��Ϊ�˽ڵ���¼�
//		s_data--�¼��������
//		d_data--�¼��������
//		a_data--�¼����Ӳ���
//		fun_ptr-�¼�ִ�к���
//�������
//˵������ͨ�¼���ִ��һ�α㱻�ͷŵ���������û�к�������
//		�������ȡ���¼���Ԫָ�롣
//-----------------------
void gen_ordinary(int delay, int id, char *name, void *s_data, void *d_data, void *a_data, FunPtr fun_ptr)
{
	Event *new_event = NULL;

	//�������¼���Ԫ
	new_event = gen_event(ORDINARY, delay, id, name, s_data, d_data, a_data, fun_ptr);

	//�¼���Ԫ���
	insert(new_event);
}

# ifdef TIMER_USE 
//-----------------------------
//���ƣ����ɶ�ʱ���¼�
//���룺id------�ڵ�ID��Ϊ�˽ڵ�Ķ�ʱ��
//		s_data--��ʱ���������
//		d_data--��ʱ���������
//		a_data--��ʱ�����Ӳ���
//		fun_ptr-��ʱ�����ִ�к���
//�������ʱ���¼�ָ��
//˵������ʱ����������������������Ϊ�����ģ���Ҫ���ض�ʱ��ָ��
//-----------------------------
Event *gen_timer(int id, char *name, void *s_data, void *d_data, void *a_data, FunPtr fun_ptr)
{
	return gen_event(TIMER, 0, id, name, s_data, d_data, a_data, fun_ptr);
}

//--------------------------
//���ƣ�������ʱ��
//���룺timer---��ʱ�����
//		delay---��ʱʱ��
//�������
//˵����������ʱ������������¼������ȴ�����ִ��
//--------------------------
void start_timer(Event *timer, int delay)
{
	timer->time = now_time+delay;

	//��ʱ���¼����
	insert(timer);
}

//-------------------------
//���ƣ�������ʱ��
//���룺timer---��ʱ�����
//		delay---��ʱʱ��
//�������
//˵���������Ҫĳ���¼�����ִ�У����䶨ʱ�����������
//		��Ҫ���ô˺�������һ�ΰ��Ŷ�ʱ���¼���
//--------------------------
void restart_timer(Event *timer, int delay)
{
	start_timer(timer, delay);
}

//------------------------
//���ƣ�ȡ���¼�
//���룺�¼���Ԫָ��
//�������
//˵������ʱ���ã�����ʹ�ö�ʱ��ʱ��Ҫʹ�ô˺���
//------------------------
void cancel(Event *e)
{
	EventHead *list_head = event_list_head;	//�¼���Ԫ��������ͷ

	//�������¼���Ԫ���У�Ҫôʱ����ȣ�Ҫôָ��β��
	while (list_head->time < e->time && list_head != event_list_tail)
		list_head = list_head->next;

	//��ʱ���ɲ���ȣ�ʱ�䲻�����¼�������
	if (list_head->time != e->time)
		printf("no such event in list in cancel()!\n");

	//ͷ���¼�
	if (list_head->head == e)
	{
		//ͬʱ�����һ���¼�����Ҫɾ�����¼���Ԫ����ͷ
		if (NULL == e->next)
		{
			//ͷ���¼���Ԫ����ͷ
			if (list_head == event_list_head)
			{
				//ͬʱ�����һ���¼���Ԫ����ͷ
				if (NULL == list_head->next)
					event_list_head = event_list_tail = NULL;
				else	//���滹�ж���¼���Ԫ����ͷ
				{
					event_list_head = list_head->next;
					event_list_head->pre = NULL;
				}

				list_head->next = NULL;
			}
			else if (list_head == event_list_tail)	//β���¼���Ԫ����ͷ
			{
				event_list_tail = list_head->pre;
				event_list_tail->next = NULL;
				list_head->pre = NULL;
			}
			else	//�м�ĳ���¼���Ԫ����ͷ
			{
				list_head->pre->next = list_head->next;
				list_head->next->pre = list_head->pre;
				list_head->next = list_head->pre = NULL;
			}

			free((void*)list_head);
			return;
		}

		//���滹�ж���¼�
		list_head->head = list_head->head->next;
		list_head->head->pre = NULL;
		e->next = NULL;
	}
	else if (list_head->tail == e)	//β���¼�
	{
		list_head->tail = list_head->tail->pre;
		list_head->tail->next = NULL;
		e->pre = NULL;
	}
	else	//�м�ĳ���¼�
	{
		e->pre->next = e->next;
		e->next->pre = e->pre;
		e->pre = e->next = NULL;
	}
}

//--------------------------
//���ƣ�ɾ����ʱ��
//���룺timer---��ʱ�����
//�������
//˵������ɾ����ʱ��ǰ�������ȵ���cancel��
//		��ȷ���䲻���¼������С�
//--------------------------
void delete_timer(Event *timer)
{
	free((void*)timer);
}
# endif

//--------------------------
//���ƣ����е�����
//���룺��
//�������
//˵����������������
//-------------------------
void run(void)
{
	Event *e = NULL;

	//��һ���¼�δ����ֹʱ�� �� ���¼�
	while ((now_time <= stop_time) && (e = deque()))	
		dispatch(e);

	printf("Simulation Finished.\n");
}

//-------------------------
//���ƣ���ȡ��ǰʱ��
//���룺��
//�������ǰʱ��
//˵������ȡʱ��
//-------------------------
unsigned int get_time(void)
{
	return now_time;
}

//-------------------------
//���ƣ����÷�������¼�
//���룺����ʱ��
//�������
//˵�������ý���ʱ��
//-------------------------
void set_time(unsigned int time)
{
	stop_time = time;
}

//-------------------------
//���ƣ���ȡ����ͷ
//���룺��
//���������ͷָ��
//˵������ȡ�¼���Ԫ����˫������ͷָ��ĵ�ַ
//-------------------------
EventHead **get_list_head(void)
{
	return &event_list_head;
}

//-------------------------
//���ƣ���ȡ����β
//���룺��
//���������βָ��
//˵������ȡ�¼���Ԫ����˫������βָ��ĵ�ַ
//-------------------------
EventHead **get_list_tail(void)
{
	return &event_list_tail;
}