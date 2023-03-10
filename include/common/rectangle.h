//
// Created by gy gao on 3/10/23.
//

#ifndef MYOWNOS_RECTANGLE_H
#define MYOWNOS_RECTANGLE_H

#include <common/vector.h>

namespace MyOwnOS
{
    namespace common
    {
        template<class T>
        class Rectangle
        {
        public:
            T left;
            T top;
            T width;
            T height;

            Rectangle();
            Rectangle(T left, T top, Twidth, T height);
            ~Rectangle();

            bool Intersects(const Rectangle<T>& other);
            Rectangle<T> Intersection(const Rectangle<T>& other);
            Vector<Rectangle<T>> Subtract(const Rectangle<T>& other);
            bool Contains(const Rectangle<T>& other);
            bool Contains(T x, T y);
        };
    }
}

#include "../../src/common/rectangle_templates.cpp"



#endif //MYOWNOS_RECTANGLE_H
