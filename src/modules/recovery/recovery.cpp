#include <px4_config.h>
#include <px4_tasks.h>
#include <px4_posix.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>

#include <uORB/uORB.h>
#include <uORB/topics/sensor_combined.h>
#include <uORB/topics/vehicle_attitude.h>

extern "C" __EXPORT int recovery_main(int argc, char *argv[]);

int recovery_main(int argc, char *argv[])
{
    PX4_INFO("Hello Sky!");

    /* advertise attitude topic */
    struct vehicle_attitude_s att;
    memset(&att, 0, sizeof(att));
    orb_advert_t att_pub = orb_advertise(ORB_ID(vehicle_attitude), &att);

    while(true){

        /*PX4_INFO("Quaternion:\t%8.4f\t%8.4f\t%8.4f\t%8.4f\n",
               (double)att.q[0],
               (double)att.q[1],
               (double)att.q[2],
               (double)att.q[3]);*/

        orb_publish(ORB_ID(vehicle_attitude), att_pub, &att);
    }

    PX4_INFO("exiting");

    return 0;
}