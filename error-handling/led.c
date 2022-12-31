/****************************************************************************
 * Copyright (C) 2022 by Denys Suprunenko                                   *
 *                                                                          *
 * This file is part of Error Handling example.                             *
 *                                                                          *
 *   Box is free software: you can redistribute it and/or modify it         *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   Box is distributed in the hope that it will be useful,                 *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Box.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

/* Define MODULE_ID_MACROS macros */
/* Macros MODULE_ID_MACROS should not be defined! We check this condition */
#ifndef MODULE_ID
#define MODULE_ID (hash_string("led.c"))
#else
#error MODULE_ID already defined. Check MODULE_ID in other files!
#endif

#include <stdbool.h>
#include "error_macros.h"
#include "error_handle.h"

/*
 * Define all error codes for LED module here
 */
enum ErrorCode 
{
	ERROR_LED_UNDEFINED_STATE = 0,
	ERROR_LED_NOT_INITIALIZED,
	ERROR_LED_IS_BROKEN,
};

void ledInit(void)
{
	errorAdd(0, MODULE_ID, (uint16_t)ERROR_LED_IS_BROKEN);
}
void ledSetState(bool state)
{
	errorAdd(0, MODULE_ID, (uint16_t)ERROR_LED_UNDEFINED_STATE);
}

void ledDeinit(void)
{
	TODO("Implement ledDeinit");
}

#undef MODULE_ID