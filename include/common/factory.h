//
// Created by gy gao on 3/10/23.
//

#ifndef MYOWNOS_FACTORY_H
#define MYOWNOS_FACTORY_H

#include <common/map.h>

namespace MyOwnOS
{
    namespace common
    {
        template<class T>
        class Instantiator
        {
        public:
            Instantiator();
            ~Instantiator();
            T* Instantiate();
        };

        template<class Key, class T>
        class Factory
        {
        protected:
            Map<Key, Instantiator<T>*> Instantiators;

        public:
            Factory();
            ~Factory();
            void Register(Key& key, Instantiator<T>* instantiator);
            T* Produce(Key&);
        };
    }
}

#include "../../src/common/factory_templates.cpp"
#endif //MYOWNOS_FACTORY_H
