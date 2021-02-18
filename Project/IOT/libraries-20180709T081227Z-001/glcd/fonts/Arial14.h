

/*
 *
 * Arial_14
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : Arial14.h
 * Date                : 02.05.2008
 * Font size in bytes  : 7788
 * Font width          : 10
 * Font height         : 14
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef ARIAL_14_H
#define ARIAL_14_H

#define ARIAL_14_WIDTH 10
#define ARIAL_14_HEIGHT 14

/*
 * added to allow fontname to match header file name. 
 * as well as keep the old name for backward compability
 */

#define Arial14 Arial_14 

const uint8_t Arial_14[] PROGMEM = {
    0x1E, 0x6C, // size
    0x0A, // width
    0x0E, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x00, 0x01, 0x03, 0x08, 0x07, 0x0A, 0x08, 0x01, 0x03, 0x03, 
    0x05, 0x07, 0x01, 0x04, 0x01, 0x04, 0x06, 0x03, 0x06, 0x06, 
    0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x06, 0x06, 
    0x06, 0x06, 0x0D, 0x09, 0x07, 0x08, 0x08, 0x07, 0x07, 0x09, 
    0x07, 0x01, 0x05, 0x08, 0x07, 0x09, 0x07, 0x09, 0x07, 0x09, 
    0x08, 0x07, 0x07, 0x07, 0x09, 0x0D, 0x08, 0x09, 0x08, 0x02, 
    0x04, 0x02, 0x05, 0x08, 0x02, 0x06, 0x06, 0x05, 0x06, 0x06, 
    0x04, 0x06, 0x06, 0x01, 0x02, 0x06, 0x01, 0x09, 0x06, 0x06, 
    0x06, 0x06, 0x04, 0x05, 0x04, 0x06, 0x07, 0x09, 0x06, 0x07, 
    0x06, 0x03, 0x01, 0x03, 0x07, 0x07, 
    
    // font data
    0xFE, 0x14, // 33
    0x1E, 0x00, 0x1E, 0x00, 0x00, 0x00, // 34
    0x90, 0x90, 0xF8, 0x96, 0x90, 0xF8, 0x96, 0x90, 0x00, 0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, // 35
    0x18, 0x24, 0x22, 0xFF, 0x42, 0x42, 0x84, 0x08, 0x10, 0x10, 0x3C, 0x10, 0x08, 0x04, // 36
    0x1C, 0x22, 0x22, 0x1C, 0xC0, 0x30, 0x8C, 0x42, 0x40, 0x80, 0x00, 0x00, 0x10, 0x0C, 0x00, 0x00, 0x0C, 0x10, 0x10, 0x0C, // 37
    0x80, 0x5C, 0x22, 0x62, 0x92, 0x0C, 0x80, 0x00, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x0C, 0x08, 0x10, // 38
    0x1E, 0x00, // 39
    0xF0, 0x0C, 0x02, 0x1C, 0x60, 0x80, // 40
    0x02, 0x0C, 0xF0, 0x80, 0x60, 0x1C, // 41
    0x04, 0x14, 0x0E, 0x14, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, // 42
    0x40, 0x40, 0x40, 0xF8, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, // 43
    0x00, 0x70, // 44
    0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, // 45
    0x00, 0x10, // 46
    0x00, 0xC0, 0x38, 0x06, 0x18, 0x04, 0x00, 0x00, // 47
    0xFC, 0x02, 0x02, 0x02, 0x02, 0xFC, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x0C, // 48
    0x08, 0x04, 0xFE, 0x00, 0x00, 0x1C, // 49
    0x0C, 0x02, 0x02, 0x82, 0x42, 0x3C, 0x10, 0x18, 0x14, 0x10, 0x10, 0x10, // 50
    0x0C, 0x02, 0x22, 0x22, 0x22, 0xDC, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x0C, // 51
    0x80, 0x40, 0x30, 0x08, 0x04, 0xFE, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x1C, 0x04, // 52
    0x38, 0x16, 0x12, 0x12, 0x12, 0xE2, 0x0C, 0x10, 0x10, 0x10, 0x18, 0x04, // 53
    0xF8, 0x44, 0x22, 0x22, 0x22, 0xC4, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x0C, // 54
    0x02, 0x02, 0x02, 0xE2, 0x1A, 0x06, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, // 55
    0xDC, 0x22, 0x22, 0x22, 0x22, 0xDC, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x0C, // 56
    0x3C, 0x42, 0x42, 0x42, 0x22, 0xFC, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, // 57
    0x08, 0x10, // 58
    0x08, 0x70, // 59
    0x40, 0xA0, 0xA0, 0x10, 0x10, 0x08, 0x00, 0x00, 0x00, 0x04, 0x04, 0x08, // 60
    0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 61
    0x08, 0x10, 0x10, 0xA0, 0xA0, 0x40, 0x08, 0x04, 0x04, 0x00, 0x00, 0x00, // 62
    0x0C, 0x02, 0x82, 0x42, 0x22, 0x1C, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, // 63
    0xE0, 0x18, 0x04, 0xC4, 0x22, 0x12, 0x12, 0x12, 0xA2, 0x72, 0x04, 0x08, 0xF0, 0x0C, 0x30, 0x40, 0x4C, 0x90, 0x90, 0x90, 0x88, 0x9C, 0x90, 0x50, 0x4C, 0x20, // 64
    0x00, 0x80, 0xE0, 0x9C, 0x82, 0x9C, 0xE0, 0x80, 0x00, 0x18, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x18, // 65
    0xFE, 0x22, 0x22, 0x22, 0x22, 0x22, 0xDC, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0C, // 66
    0xF8, 0x04, 0x02, 0x02, 0x02, 0x02, 0x04, 0x08, 0x04, 0x08, 0x10, 0x10, 0x10, 0x10, 0x08, 0x04, // 67
    0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0xF8, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x04, // 68
    0xFE, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, // 69
    0xFE, 0x22, 0x22, 0x22, 0x22, 0x22, 0x02, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 70
    0xF8, 0x04, 0x02, 0x02, 0x02, 0x42, 0x42, 0x44, 0xC8, 0x04, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x04, // 71
    0xFE, 0x20, 0x20, 0x20, 0x20, 0x20, 0xFE, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, // 72
    0xFE, 0x1C, // 73
    0x00, 0x00, 0x00, 0x00, 0xFE, 0x0C, 0x10, 0x10, 0x10, 0x0C, // 74
    0xFE, 0x80, 0x40, 0x20, 0x50, 0x88, 0x04, 0x02, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x10, // 75
    0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, // 76
    0xFE, 0x0C, 0x30, 0xC0, 0x00, 0xC0, 0x30, 0x0C, 0xFE, 0x1C, 0x00, 0x00, 0x04, 0x18, 0x04, 0x00, 0x00, 0x1C, // 77
    0xFE, 0x04, 0x18, 0x60, 0x80, 0x00, 0xFE, 0x1C, 0x00, 0x00, 0x00, 0x04, 0x08, 0x1C, // 78
    0xF8, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0xF8, 0x04, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x04, // 79
    0xFE, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
    0xF8, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0xF8, 0x04, 0x08, 0x10, 0x10, 0x10, 0x14, 0x08, 0x1C, 0x10, // 81
    0xFE, 0x42, 0x42, 0x42, 0xC2, 0x42, 0x42, 0x3C, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x10, // 82
    0x1C, 0x22, 0x22, 0x22, 0x42, 0x42, 0x8C, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0C, // 83
    0x02, 0x02, 0x02, 0xFE, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, // 84
    0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x04, 0x08, 0x10, 0x10, 0x10, 0x08, 0x04, // 85
    0x06, 0x18, 0x60, 0x80, 0x00, 0x80, 0x60, 0x18, 0x06, 0x00, 0x00, 0x00, 0x04, 0x18, 0x04, 0x00, 0x00, 0x00, // 86
    0x06, 0x38, 0xC0, 0x00, 0xC0, 0x3C, 0x02, 0x3C, 0xC0, 0x00, 0xC0, 0x38, 0x06, 0x00, 0x00, 0x04, 0x18, 0x04, 0x00, 0x00, 0x00, 0x04, 0x18, 0x04, 0x00, 0x00, // 87
    0x02, 0x0C, 0x90, 0x60, 0x60, 0x90, 0x0C, 0x02, 0x10, 0x0C, 0x00, 0x00, 0x00, 0x04, 0x0C, 0x10, // 88
    0x02, 0x04, 0x18, 0x20, 0xC0, 0x20, 0x18, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, // 89
    0x00, 0x02, 0x82, 0x42, 0x22, 0x1A, 0x06, 0x02, 0x10, 0x18, 0x14, 0x10, 0x10, 0x10, 0x10, 0x10, // 90
    0xFE, 0x02, 0xFC, 0x80, // 91
    0x06, 0x38, 0xC0, 0x00, 0x00, 0x00, 0x04, 0x18, // 92
    0x02, 0xFE, 0x80, 0xFC, // 93
    0x20, 0x1C, 0x02, 0x1C, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, // 95
    0x02, 0x04, 0x00, 0x00, // 96
    0x10, 0x88, 0x48, 0x48, 0x48, 0xF0, 0x0C, 0x10, 0x10, 0x10, 0x08, 0x1C, // 97
    0xFE, 0x10, 0x08, 0x08, 0x08, 0xF0, 0x1C, 0x08, 0x10, 0x10, 0x10, 0x0C, // 98
    0xF0, 0x08, 0x08, 0x08, 0x10, 0x0C, 0x10, 0x10, 0x10, 0x08, // 99
    0xF0, 0x08, 0x08, 0x08, 0x10, 0xFE, 0x0C, 0x10, 0x10, 0x10, 0x08, 0x1C, // 100
    0xF0, 0x48, 0x48, 0x48, 0x48, 0x70, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x08, // 101
    0x08, 0xFC, 0x0A, 0x0A, 0x00, 0x1C, 0x00, 0x00, // 102
    0xF0, 0x08, 0x08, 0x08, 0x10, 0xF8, 0x4C, 0x90, 0x90, 0x90, 0x88, 0x7C, // 103
    0xFE, 0x10, 0x08, 0x08, 0x08, 0xF0, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C, // 104
    0xFA, 0x1C, // 105
    0x00, 0xFA, 0x80, 0x7C, // 106
    0xFE, 0x80, 0x40, 0xA0, 0x10, 0x08, 0x1C, 0x00, 0x00, 0x00, 0x0C, 0x10, // 107
    0xFE, 0x1C, // 108
    0xF8, 0x10, 0x08, 0x08, 0xF0, 0x10, 0x08, 0x08, 0xF0, 0x1C, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x1C, // 109
    0xF8, 0x10, 0x08, 0x08, 0x08, 0xF0, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C, // 110
    0xF0, 0x08, 0x08, 0x08, 0x08, 0xF0, 0x0C, 0x10, 0x10, 0x10, 0x10, 0x0C, // 111
    0xF8, 0x10, 0x08, 0x08, 0x08, 0xF0, 0xFC, 0x08, 0x10, 0x10, 0x10, 0x0C, // 112
    0xF0, 0x08, 0x08, 0x08, 0x10, 0xF8, 0x0C, 0x10, 0x10, 0x10, 0x08, 0xFC, // 113
    0xF8, 0x10, 0x08, 0x08, 0x1C, 0x00, 0x00, 0x00, // 114
    0x30, 0x48, 0x48, 0x48, 0x90, 0x08, 0x10, 0x10, 0x10, 0x0C, // 115
    0x08, 0xFE, 0x08, 0x08, 0x00, 0x1C, 0x10, 0x10, // 116
    0xF8, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x0C, 0x10, 0x10, 0x10, 0x08, 0x1C, // 117
    0x18, 0x60, 0x80, 0x00, 0x80, 0x60, 0x18, 0x00, 0x00, 0x04, 0x18, 0x04, 0x00, 0x00, // 118
    0x18, 0xE0, 0x00, 0xE0, 0x18, 0xE0, 0x00, 0xE0, 0x18, 0x00, 0x04, 0x18, 0x04, 0x00, 0x04, 0x18, 0x04, 0x00, // 119
    0x08, 0x30, 0xC0, 0xC0, 0x30, 0x08, 0x10, 0x0C, 0x00, 0x00, 0x0C, 0x10, // 120
    0x18, 0x60, 0x80, 0x00, 0x80, 0x60, 0x18, 0x00, 0x80, 0x8C, 0x70, 0x0C, 0x00, 0x00, // 121
    0x08, 0x08, 0x88, 0x68, 0x18, 0x08, 0x10, 0x18, 0x14, 0x10, 0x10, 0x10, // 122
    0x80, 0x7C, 0x02, 0x00, 0x7C, 0x80, // 123
    0xFE, 0xFC, // 124
    0x02, 0x7C, 0x80, 0x80, 0x7C, 0x00, // 125
    0x40, 0x20, 0x20, 0x60, 0x40, 0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
    0xFC, 0x04, 0x04, 0x04, 0x04, 0x04, 0xFC, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1C // 127
    
};

#endif
