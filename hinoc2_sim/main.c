# include "sys_stat.h"
# include "queue/queue_mng.h"
# include "schedule/map.h"


void c(Event *e)
{
	static int i = 0;

	printf("time is %d,my id is %d,my name is %s\n",get_time(), e->node_id,e->event_name);
	restart_timer(e, 5);

	if (++i == 8)
		cancel(e);
}

void a(Event *e)
{
	printf("time is %d, my id is %d, my name is %s!\n", e->time, e->node_id, e->event_name);
}

void b(Event *e)
{
	gen_ordinary(10,1,"b",0,0,0,b);
	gen_ordinary(2,2,"c",0,0,0,a);
}

int main (void)
{
	//队列传参及数据包信息扩展测试
	HinocQueue temp_queue;
	Packet temp_packet;

	temp_queue.up_queue = orgin_up_queue;
	temp_queue.down_queue = orgin_down_queue;
	
	memset(&temp_packet,0,sizeof(Packet));
	temp_packet.serial_num = 10;
	temp_packet.arrive_time = 1;
	temp_packet.prio = 0;
	temp_packet.length = 512;

	enque(&orgin_up_queue[0][0], &temp_packet);

	gen_ordinary(10,1,"text",&temp_queue,0,0,enqueue_up);   

	set_time(100);

	run();
	
	/*//统计传参数测试
	Path temp_path;
	temp_path.up_path_ptr = packet_up_path;
	temp_path.down_path_ptr = packet_down_path;
	
	set_time(100);

	gen_ordinary(10,1,"param",&temp_path,0,0,packet_load);

	run();
	*/

	/*//timer测试
	Event *timer = NULL;
	
	set_time(100);

	timer = gen_timer(1, "my_timer", 0, 0, 0, c);

	start_timer(timer, 10);

	run();
	*/

	/*//事件中生成事件
	set_time(100);

	gen_ordinary(10,3,"a",0,0,0,b);

	run();
	*/

	/*
	//调度器测试
	gen_ordinary(10,1,"a",0,0,0,a);
	gen_ordinary(10,2,"b",0,0,0,a);
	gen_ordinary(9,3,"c",0,0,0,a);
	gen_ordinary(11,4,"d",0,0,0,a);
	gen_ordinary(10,5,"e",0,0,0,a);
	gen_ordinary(15,6,"f",0,0,0,a);
	gen_ordinary(7,7,"g",0,0,0,a);
	gen_ordinary(13,8,"h",0,0,0,a);

	run();
	*/

	
	
	
	return 1;
}