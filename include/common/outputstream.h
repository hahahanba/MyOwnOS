//
// Created by gy gao on 3/10/23.
//

#ifndef MYOWNOS_OUTPUTSTREAM_H
#define MYOWNOS_OUTPUTSTREAM_H

#include <common/vector.h>
#include <common/string.h>
#include <common/inputstream.h>

namespace MyOwnOS
{
    namespace common
    {
        template<class T>
        class BasicOutputStream
                :public InputStreamProcessor<T, T>
        {
        public:
            BasicOutputStream();
            virtual ~BasicOutputStream();
            virtual string GetName();
            void OnRead(T c);
            void OnEndOfStream(BasicInputStream<T>* stream);

            virtual void Write(T);
            virtual void Close();
            virtual BasicOutputStream<T>& operator<<(T);
        };

        class OutputStream
                : public BasicOutputStream<string>
        {
        public:
            OutputStream();
            ~OutputStream();
            virtual string GetName();

            virtual void Write(string s);
            virtual void WriteChar(char c);
            virtual void WriteInt(int i);
            virtual void WriteIntHex(unsigned int i);

            virtual void LineFeed();
            virtual void CarriageReturn();
            virtual void Clear();

            OutputStream& operator<<(int i);
            OutputStream& operator<<(string s);
            OutputStream& operator<<(char c);
        };

        template<class T>
        class NullStream : public BasicOutputStream<T>
        {
        public:
            NullStream();
            ~NullStream();
            string GetName();
        };

    }
}

#include "../../src/common/outputstream_templates.cpp"
#endif //MYOWNOS_OUTPUTSTREAM_H
