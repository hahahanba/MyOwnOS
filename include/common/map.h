//
// Created by gy gao on 3/10/23.
//

#ifndef MYOWNOS_MAP_H
#define MYOWNOS_MAP_H

#include <common/vector.h>
#include <common/pair.h>

namespace MyOwnOS
{
    namespace common
    {
        template<class Key, class Value>
        class MapIterationHandler
        {
        public:
            MapIterationHandler();
            ~MapIterationHandler();
            virtual void OnRead(Key, Value);
            virtual void OnEndOfStream();
        };

        template<class Key, class Value>
        class Map
        {
        protected:
            Vector<Pair<Key, Value>> elements;

        public:
            typedef typename Vector<Pair<Key, Value>>::iterator iterator;

            Map();
            ~Map();

            Value& operator[](Key key);
            iterator begin();
            iterator end();
            iterator find(Key element);

            bool empty();
            void clear();
            void insert(Key key, Value value);
            void erase(Key key);

            void Iterate(MapIterationHandler<Key, Value>* handler);
            void Iterate(void callback(Key&, Value&));
        };
    }
}

#include "../../src/common/map_templates.cpp"
#endif //MYOWNOS_MAP_H
