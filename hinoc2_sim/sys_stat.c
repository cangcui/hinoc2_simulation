//--------------------
//名称：统计模块
//作者：
//日期：
//说明：完成仿真相关信息的采集
//版本：
//--------------------

//--------------------
//头文件
//--------------------
# include "sys_stat.h"

//--------------------
//全局参数
//--------------------
char *packet_up_path[HM_NUM][PRIO_NUM] = {{"123.txt"}};
char *packet_down_path[HM_NUM][PRIO_NUM] = {NULL};
Queue orgin_up_queue[HM_NUM][PRIO_NUM];
Queue orgin_down_queue[HM_NUM][PRIO_NUM];

//--------------------
//名称：数据包载入
//输入：e---事件指针
//输出：无
//说明：
//--------------------
void packet_load(Event *e)
{
	//路径
	char *path = NULL;
	Path *temp = NULL;

	//获取
	temp = (Path *)e->src_data;

	path = temp->up_path_ptr[0][0];

	path = path;

}

void packet_free(Event *e)
{

}