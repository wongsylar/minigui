///////////////////////////////////////////////////////////////////////////////
//
//                          IMPORTANT NOTICE
//
// The following open source license statement does not apply to any
// entity in the Exception List published by FMSoft.
//
// For more information, please visit:
//
// https://www.fmsoft.cn/exception-list
//
//////////////////////////////////////////////////////////////////////////////
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
 *   <http://www.minigui.com/blog/minigui-licensing-policy/>.
 */
#ifndef	_EM86_H_
#define _EM86_H_

#define MOUSE_MOVE_PIXEL    5
#define MOUSE_MOVE_PIXEL_F  15

#define MOUSE_MAX_X         639
#define MOUSE_MAX_Y         464

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */
BOOL    InitEm86Input (INPUT* input, const char* mdev, const char* mtype);
void    TermEm86Input (void);

#define IR_IOCTL 0x00450000
#define IR_IOCTL_READ_KEY               (IR_IOCTL + 0x00)
#define IR_IOCTL_FLUSH_KEY              (IR_IOCTL + 0x01)

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif	/* _EM86_H_ */


