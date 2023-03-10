//
// Created by gy gao on 3/10/23.
//

#ifndef MYOWNOS_VECTOR_H
#define MYOWNOS_VECTOR_H

#include <common/types.h>

namespace MyOwnOS
{
    namespace common
    {
        template<class T>
        class VectorIterationHandler
        {
        public:
            VectorIterationHandler();
            ~VectorIterationHandler();
            virtual void OnRead(T);
            virtual void OnEndOfStream();
        };

        template<class T>
        class Vector
        {
        protected:
            T elements[100];
            uint32_t Size;
            uint32_t MaxSize;

        public:
            typedef T* iterator;

            Vector();
            Vector(int size, T element);
            ~Vector();

            T& operator[](int index);
            uint32_t size();
            iterator begin();
            iterator end();
            iterator find(T element);
            bool empty();

            iterator push_back(T element);
            void pop_back();
            iterator push_front(T element);
            void pop_front();
            void erase(T element);
            void erase(iterator position);
            void clear();

            void Iterator(VectorIterationHandler<T>* handler);
            void Iterator(void callback(T&));
        };
    }
}

#include "../../src/common/vector_templates.cpp"

#endif //MYOWNOS_VECTOR_H
