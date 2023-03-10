//
// Created by gy gao on 3/10/23.
//

#ifndef MYOWNOS_PAIR_H
#define MYOWNOS_PAIR_H

namespace MyOwnOS
{
    namespace common
    {
        template<class First, class Second>
        class Pair
        {
        public:
            First first;
            Second second;

            Pair();
            Pair(First, Second);
            ~Pair();
        };
    }
}

#include "../../src/common/pair_templates.cpp"

#endif //MYOWNOS_PAIR_H
