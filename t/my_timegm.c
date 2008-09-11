#include <stdlib.h>
#include "tap.c"
#include "localtime64.h"

int main(void) {
    struct tm date;
    Time64_T time = 0;

    /* localtime is before GMT on New Year's */
    setenv("TZ", "US/Pacific", 1);
    gmtime64_r(&time, &date);
    is_int( (int)my_timegm(&date), (int)timegm(&date), "my_timegm(0), local before" );

    time = 60*60*16;
    gmtime64_r(&time, &date);
    is_int( (int)my_timegm(&date), (int)timegm(&date), "my_timegm(60*60*16)" );


    /* localtime is after GMT on New Year's */
    setenv("TZ", "Europe/Moscow", 1);
    gmtime64_r(&time, &date);
    is_int( (int)my_timegm(&date), (int)timegm(&date), "my_timegm(0), local after" );

    time = 60*60*16;
    gmtime64_r(&time, &date);
    is_int( (int)my_timegm(&date), (int)timegm(&date), "my_timegm(60*60*16)" );

    /* 5:30 offset */
    setenv("TZ", "Asia/Calcutta", 1);
    gmtime64_r(&time, &date);
    is_int( (int)my_timegm(&date), (int)timegm(&date), "my_timegm(0), minute offset" );

    time = 60*60*16;
    gmtime64_r(&time, &date);
    is_int( (int)my_timegm(&date), (int)timegm(&date), "my_timegm(60*60*16)" );


    /* -4:30 offset */
    setenv("TZ", "America/Caracas", 1);
    gmtime64_r(&time, &date);
    is_int( (int)my_timegm(&date), (int)timegm(&date), "my_timegm(0), minute offset" );

    time = 60*60*16;
    gmtime64_r(&time, &date);
    is_int( (int)my_timegm(&date), (int)timegm(&date), "my_timegm(60*60*16)" );


    done_testing();
    return(0);
}