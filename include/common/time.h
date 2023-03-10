//
// Created by gy gao on 3/10/23.
//

#ifndef MYOWNOS_TIME_H
#define MYOWNOS_TIME_H

namespace MyOwnOS
{
    namespace common
    {
        struct Time
        {
            uint16_t year;
            uint8_t  month;
            uint8_t  day;

            uint8_t  hour;
            uint8_t  minute;
            uint8_t  second;

        };
    }
}


#endif //MYOWNOS_TIME_H
