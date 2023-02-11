import rospy
from std_msgs.msg import Int32


def talker():
    rospy.init_node("talker", anonymous=True)
    pub = rospy.Publisher("numbers", Int32, 10)
    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        message = f"The current time is {rospy.get_time()}"
        rospy.loginfo(message)
        pub.publish(message)
        rate.sleep()


if __name__ == "__main__":
    try:
        talker()
    except rospy.ROSInterruptException:
        rospy.loginfo("Ending Publisher")
