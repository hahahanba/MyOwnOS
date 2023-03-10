//
// Created by gy gao on 3/9/23.
//

#ifndef MYOWNOS_COLOR_H
#define MYOWNOS_COLOR_H

#include <common/types>

namespace MyOwnOS
{
    namespace common
    {
        class Color
        {
        public:
            uint8_t Red;
            uint8_t Green;
            uint8_t Blue;
            uint8_t Alpha;

            Color();
            Color(uint8_t Red, uint8_t Green, uint8_t Blue);
            Color(uint8_t Red, uint8_t Green, uint8_t Blue, uint8_t Alpha);
            ~Color();
        };
    }
}


#endif //MYOWNOS_COLOR_H
