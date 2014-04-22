//--------------------
//名称：队列收发模块
//作者：
//日期：
//说明：完成仿真相关信息的采集
//版本：
//--------------------

//--------------------
//头文件
//--------------------
# include "queue_mng.h"
#include "../user_setting.h"
//--------------------
//全局参数
//--------------------
//已打包队列
static Queue packed_up_queue[HM_NUM][PRIO_NUM];
static Queue packed_down_queue[HM_NUM][PRIO_NUM];
//待接收队列
static Queue to_be_received_up_queue[HM_NUM][PRIO_NUM];
static Queue to_be_received_down_queue[HM_NUM][PRIO_NUM];
//已接收队列
Queue received_up_queue[HM_NUM][PRIO_NUM];
Queue received_down_queue[HM_NUM][PRIO_NUM];

//HM
HinocQueue hm_packed_queue;

//HM
HinocQueue hm_sending_queue;

//HB
HinocQueue hb_packed_queue;

void enqueue_up(Event *e)
{
	HinocQueue *queue = NULL;
	Packet *packet = NULL;
	Frame *new_frame = NULL;
	FrameInfo *frame_info = NULL;

	queue = (HinocQueue *)e->src_data;

	packet = deque(&queue->up_queue[0][0]);

	if (!(new_frame = (Frame *)malloc(sizeof(Frame))))	
		printf("no memory for new_frame!\n");
	memset(new_frame,0,sizeof(Frame));

	if (!(frame_info = (FrameInfo *)malloc(sizeof(FrameInfo))))
	{
		printf("no memory for frame_info!\n");
		free((void*)new_frame);
	}
	memset(frame_info,0,sizeof(FrameInfo));

	new_frame->add_info = frame_info;
	
	new_frame->serial_num = 1;
	new_frame->length += packet->length;
	((FrameInfo *)new_frame->add_info)->first_packet = packet->serial_num;
	((FrameInfo *)new_frame->add_info)->packet_num++;

	return;
}

void enqueue_down(Event *e);
void send_up(Event *e);
void send_down(Event *e);
void recv_up(Event *e);
void recv_down(Event *e);