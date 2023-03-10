//
// Created by gy gao on 3/10/23.
//

#ifndef MYOWNOS_GRAPHICSCONTEXT_H
#define MYOWNOS_GRAPHICSCONTEXT_H

#include <common/color.h>
#include <common/string.h>

namespace MyOwnOS
{
    namespace common
    {
        class GraphicsContext
        {
        protected:
            uint32_t width;
            uint32_t height;
            uint32_t colordepth;

            Color Palette[256];
            virtual void DoPutPixel(uint32_t x, uint32_t y, uint32_t color);

            // 重载所有支持的位深
            virtual void DoPutPixel8Bit(uint32_t x, uint32_t y, uint8_t color);
            virtual void DoPutPixel16Bit(uint32_t x, uint32_t y, uint16_t color);
            virtual void DoPutPixel24Bit(uint32_t x, uint32_t y, uint24_t color);
            virtual void DoPutPixel32Bit(uint32_t x, uint32_t y, uint32_t color);

            virtual uint32_t DoGetPixel(uint32_t x, uint32_t y);

            // 重载所有支持的位深
            virtual uint8_t DoGetPixel8Bit(uint32_t x, uint32_t y);
            virtual uint16_t DoGetPixel16Bit(uint32_t x, uint32_t y);
            virtual uint24_t DoGetPixel24Bit(uint32_t x, uint32_t y);
            virtual uint32_t DoGetPixel32Bit(uint32_t x, uint32_t y);

            bool MirrorYaxis;

        public:
            GraphicsContext();
            ~GraphicsContext();

            uint32_t TranslateColor(Color color);
            Color TranslateColorBack(uint32_t color);
            uint32_t GetWidth();
            uint32_t GetHeight();

            void PutPixel(int32_t x, int32_t y, uint32_t color);
            void PutPixel(int32_t x, int32_t y, Color color);
            Color GetPixel(int32_t x, int32_t y);
            void InvertPixel(int32_t x, int32_t y);
            void Line(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color);
            void Line(int32_t x1, int32_t y1, int32_t x2, int32_t y2, Color color);
            void Rectangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color);
            void Rectangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, Color color);
            void FillRectangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color);
            void FillRectangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, Color color);

        };
    }
}
#endif //MYOWNOS_GRAPHICSCONTEXT_H
