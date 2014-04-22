//----------------------
//名称：队列模型
//作者：孙文
//日期：20131201
//说明：仿真中队列的统一底层操作，所有类型的数据包，数据帧，
//		数据分组都可以通过此模块来扩展。
//版本：v1.0
//		20131201
//		完成基本的入队出队操作
//		v1.1
//		修改Packet细节
//		v1.2---20131223
//		修改Node细节，重新抽象
//---------------------

//-----------------------
//头文件
//-----------------------
# include "basic_queue.h"

//-----------------------
//名称：数据入队
//输入：queue---待入队列
//		packet----待入队节点
//输出：无
//说明：应在可入队的情况下调用此函数,
//		数据包入队前要保证packet->next = NULL，
//		队列在初始化时要保证queue->prio有值。
//-----------------------
void enque(Queue *queue, Packet *packet)
{
	//进入错误队列
	if (packet->prio != queue->prio)
		printf("enter the wrong queue in enque()!\n");

	//队列为空
	if (NULL == queue->tail)
	{
		queue->head = packet;
		queue->tail = packet;
	}
	else	//队列非空
	{
		queue->tail->next = packet;
		queue->tail = packet;
	}
	
	//队列信息完善
	queue->queue_length += packet->length;
	queue->packet_num++;
}

//-----------------------
//名称：节点出队
//输入：queue---待出队队列
//输出：出队数据包
//说明：有啥说的、、、、、记得检查返回值
//-----------------------
Packet *deque(Queue *queue)
{
	Packet *packet = NULL;
	
	//队列无数据
	if (NULL == queue)
		return packet;
		
	//获取第一个数据包	
	packet = queue->head;	
	queue->head = packet->next;
	packet->next = NULL;
	
	//最后一个包
	if (packet == queue->tail)
		queue->tail = NULL;

	//队列信息完善
	queue->queue_length -= packet->length;
	queue->packet_num--;
		
	return packet;
}



















