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

/*
	本模块中应只含队列管理的接口。
	具体业务层的操作，应该由节点模块完成。
*/

// 数据入原始队列，即生成原始数据
int en_orignal_queue(int updown_flag, Queue (*orign_queue)[2][PRIO_NUM])
{
	//调用业务员模块
	return 0;
}

// 数据入缓存队列，即数据入队
int en_cache_queue(int updown_flag, Queue (*orign_queue)[2][PRIO_NUM], Queue (*cache_queue)[2][PRIO_NUM])
{

	return 0;
}

// 数据入正在发送队列，即数据发送
int en_sending_queue(int updown_flag, Queue (*cache_queue)[2][PRIO_NUM], Queue (*sending_queue)[2][PRIO_NUM])
{

	return 0;
}

// 数据如已接受队列，即数据接收
int en_received_queue(int updown_flag, Queue (*cache_queue)[2][PRIO_NUM], Queue (*sending_queue)[2][PRIO_NUM])
{

	return 0;
}