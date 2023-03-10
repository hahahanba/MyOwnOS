//
// Created by gy gao on 3/10/23.
//

#ifndef MYOWNOS_FONT_H
#define MYOWNOS_FONT_H

#include <common/string.h>
#include <common/rectangle.h>
#include <common/graphicscontext.h>

namespace MyOwnOS
{
    namespace common
    {
        class Font
        {
        public:
            Font();
            ~Font();

            bool bold;
            bool italic;
            uint16_t size;
            common::Color color;
            common::Color backgroundColor;

            virtual void WriteText(int32_t x, int32_t y, GraphicsContext* context, string text);
            virtual void WriteText(int32_t x, int32_t y, GraphicsContext* context, string text, Rectangle<int> limitArea);
            virtual uint32_t TextHeight(string text);
            virtual uint32_t TextWidth(string text);
        };
    }
}
#endif //MYOWNOS_FONT_H
