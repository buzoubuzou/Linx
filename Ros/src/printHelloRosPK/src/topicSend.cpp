#include "ros/ros.h"
#include "std_msgs/String.h"  //消息发送相关头文件  
#include <sstream>
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "topicSend");
  //前面两个参数跟系统的重映射有关，在这里不考虑。第三个参数为节点名称,我们定义为topicSend
  ros::NodeHandle n;
  //节点句柄，第一个创建的节点句柄会为节点初始化。最后一个销毁的节点句柄则会释放该节点所占用的资源
  ros::Publisher hello_pub = n.advertise<std_msgs::String>("hello", 100);
  //advertise()会告知ROS我们要发布一个话题，话题名是第一个参数的“hello”。这样ROS的管理进程就会告诉所
  //有订阅了"hello"话题的节点，将要有数据发布。第二个参数是发布序列的大小。如果我们发布的消息的频率太高，
  //缓冲区中的消息在大于1000个的时候就会开始丢弃先前发布的消息。
  //advertise()返回一个ros::Publisher对象,它有两个作用：
  //1)它有一个publish()成员函数可以让你在topic上发布消息；
  //2)如果消息类型不对,它会拒绝发布。
  ros::Rate loop_rate(0.5);
  //ros::Rate对象可以允许你指定自循环的频率。它会追踪记录自上一次调用Rate::sleep()后时间的流逝，并休眠直到过了一个频率周期的时间。
  //上面程序的写法就是让程序以10Hz的频率发布消息
  int count = 0;//消息发送计数器
  while (ros::ok())
  {
	//如果下列条件之一发生，ros::ok() 返回false：
	/*
	1.SIGINT 被触发 (Ctrl-C)
	2.被另一同名节点踢出 ROS 网络
	3.ros::shutdown() 被程序的另一部分调用
	4.节点中的所有 ros::NodeHandles 都已经被销毁
	*/
    std_msgs::String msg;
 //标准的String消息，它只有一个数据成员 "data"。当然，你也可以发布更复杂的消息类型。
    std::stringstream ss;
    if(count <= 100) {
    ss << "hello world " << count;}
    else {
    ss << "Invalid number!";}
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());//将要发布的消息打印出来看看
    hello_pub.publish(msg);//向所有订阅 chatter 话题的节点发送消息
    ros::spinOnce();
	//在这个例子中并不是一定要调用 ros::spinOnce()，因为我们不接受回调。然而，如果你的程序里包含其他回调函数，最好在这里加上
	//ros::spinOnce()这一语句，否则你的回调函数就永远也不会被调用了。
    loop_rate.sleep();
    //调用ros::Rate对象来休眠一段时间以使得发布频率为10Hz
    ++count;
  }
  return 0;
}
