//
// Created by gy gao on 3/10/23.
//

#ifndef MYOWNOS_INPUTSTREAM_H
#define MYOWNOS_INPUTSTREAM_H

#include <common/vector.h>
#include <common/string.h>

namespace MyOwnOS
{
    namespace common
    {
        // BasicInputStream
        template<class T>
        class BasicInputStream;

        // InputStreamEventHandler
        template<class T>
        class InputStreamEventHandler
        {
            friend class BasicInputStream<T>;

        protected:
            common::Vector<BasicInputStream<T>*> streams;

        public:
            InputStreamEventHandler();
            ~InputStreamEventHandler();
            virtual void OnRead(T);
            virtual void OnEndOfStream(BasicInputStream<T>* stream);
        };

        // InputStreamProcessor
        template<class T, class U>
        class InputStreamProcessor
                : public InputStreamEventHandler<T>, public BasicInputStream<U>
        {
        public:
            InputStreamProcessor();
            InputStreamProcessor(InputStreamEventHandler<U>* handler);
            ~InputStreamProcessor();

            void OnEndOfStream(BasicInputStream<T>*);
        };

        // InputStreamSocket
        template<class T>
        class InputStreamSocket
                : public InputStreamProcessor<T, T>
        {
        public:
            InputStreamSocket();
            InputStreamSocket(InputStreamEventHandler<T>* handler);
            ~InputStreamSocket();

            void OnRead(T);
        };

        // InputStreamBuffer
        template<class T>
        class InputStreamBuffer
                :protected InputStreamProcessor<T, T*>
        {
        protected:
            T buffer[10240];
            int offset;
            T eventFireElement;
            T terminationElement;

        public:
            InputStreamBuffer(T eventFireElement, T terminationElement);
            ~InputStreamBuffer();

            void OnRead(T c);
            void OnEndOfStream(BasicInputStream<T>* stream);
            void Flush();
        };

        // BasicInputStream
        template<class T>
        class BasicInputStream
        {
        protected:
            common::Vector<InputStreamEventHandler<T>*> handlers;

        public:
            BasicInputStream();
            BasicInputStream(InputStreamEventHandler<T>* handler);
            ~BasicInputStream();
            string GetName();

            void ConnectEventHandler(InputStreamEventHandler<T>* handler);
            void DisconnectEventHandler(InputStreamEventHandler<T>* handler);
        };

        // InputStream
        class InputStream : public BasicInputStream<string>
        {
        public:
            InputStream(InputStreamEventHandler<string>* handler);
        };

        template<class T, class U>
        BasicInputStream<U>& operator>>(BasicInputStream<T>& source, InputStreamProcessor<T, U>& processor);

        template<class T>
        void operator>>(BasicInputStream<T>& source, InputStreamEventHandler<T>& handler);
    }
}

#include "../../src/common/inputstream_templates.cpp"
#endif //MYOWNOS_INPUTSTREAM_H
