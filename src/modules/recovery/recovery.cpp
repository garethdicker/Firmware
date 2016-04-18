#include <px4_config.h>
#include <px4_tasks.h>
#include <px4_posix.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>

#include <uORB/uORB.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/quaternion.h>

extern "C" __EXPORT int recovery_main(int argc, char *argv[]);


int recovery_main(int argc, char *argv[])
{
    /* advertise attitude topic */
    struct quaternion_s _quaternion;
    memset(&_quaternion, 0, sizeof(_quaternion));
    _quaternion.q[0] = 1.0f;
    orb_advert_t quaterion_pub = orb_advertise(ORB_ID(quaternion), &_quaternion);

    while(true){

       /* PX4_INFO("Quaternion:\t%8.4f\t%8.4f\t%8.4f\t%8.4f\n",
               (double)_quaternion.q[0],
               (double)_quaternion.q[1],
               (double)_quaternion.q[2],
               (double)_quaternion.q[3]);*/

        orb_publish(ORB_ID(quaternion), quaterion_pub, &_quaternion);
    }

    PX4_INFO("exiting");

    return 0;
}