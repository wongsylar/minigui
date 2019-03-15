/*
 *   This file is part of MiniGUI, a mature cross-platform windowing
 *   and Graphics User Interface (GUI) support system for embedded systems
 *   and smart IoT devices.
 *
 *   Copyright (C) 2002~2018, Beijing FMSoft Technologies Co., Ltd.
 *   Copyright (C) 1998~2002, WEI Yongming
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   Or,
 *
 *   As this program is a library, any link to this program must follow
 *   GNU General Public License version 3 (GPLv3). If you cannot accept
 *   GPLv3, you need to be licensed from FMSoft.
 *
 *   If you have got a commercial license of this program, please use it
 *   under the terms and conditions of the commercial license.
 *
 *   For more information about the commercial license, please refer to
 *   <http://www.minigui.com/en/about/licensing-policy/>.
 */

/*
** glyphruninfo.h: Internal interface related GLYPHRUNINFO.
**
** Create by WEI Yongming at 2019/03/15
*/

#ifndef _MG_NEWGDI_GLYPHRUNINFO_H
    #define _MG_NEWGDI_GLYPHRUNINFO_H

typedef Glyph32 (*CB_GET_GLYPH_INFO) (void* shaping_engine,
        void* glyph_info, int index, int* cluster);

typedef BOOL (*CB_DESTROY_OBJECT) (void* object);

typedef struct _SHAPPINGENGINE {
    /* The pointer to the shaping engine */
    void*               shaping_engine;

    /* the callback reverse the glyphs */
    CB_REVERSE_ARRAY    cb_reverse_glyphs;

    /* The callback returns the glyph value and cluster
       from a void glyph information */
    CB_GET_GLYPH_INFO   cb_get_glyph_info;

    /* the callback destroy the shaping engine */
    CB_DESTROY_OBJECT   cb_destroy_engine;
} SHAPPINGENGINE;

typedef struct _SHAPEDGLYPHS {
    /* The array contains the glyph information */
    void*   glyph_infos;

    /* The number of glyphs */
    int     nr_glyphs;
} SHAPEDGLYPHS;

/* same as HarfBuzz */
typedef enum {
    GR_DIRECTION_INVALID = 0,
    GR_DIRECTION_LTR = 4,
    GR_DIRECTION_RTL,
    GR_DIRECTION_TTB,
    GR_DIRECTION_BTT
} GlyphRunDir;

struct _GLPYHRUNINFO {
    /* the logfont for upright glyphs */
    LOGFONT*        lfur;
    /* The logfont for sideways glyphs */
    LOGFONT*        lfsw;
    Uchar32*        ucs;
    SHAPPINGENGINE* se;

    struct _textrun {
        LanguageCode    lc;
        ScriptType st;
        GlyphRunDir     dir;
        int             si; // start index
        int             len;
    }*              runs;

    BidiLevel*      els;
    Uint16*         bos;
    SHAPEDGLYPHS**  sgs;
    GLYPHEXTINFO**  ges;

    int             nr_ucs;
    int             nr_runs;
    int             nr_scripts;
    Uint32          render_flags;
};

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif // _MG_NEWGDI_GLYPHRUNINFO_H

