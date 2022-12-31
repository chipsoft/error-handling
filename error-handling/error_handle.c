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
#define MODULE_ID (hash_string("error_handle.c"))
#else
#error MODULE_ID already defined. Check MODULE_ID in other files!
#endif

#include "error_ringbuffer.h"

/* Ring buffer for error description list */
static RingBuffer ringBufferErrorList;

void errorInit(void)
{
	/* Global ring buffer initialization for error description */
	ringBufferInit(&ringBufferErrorList);
}

void errorAdd(uint32_t timestamp, uint32_t moduleId, uint16_t errorCode)
{
	/* Add error description to global ring buffer initialization */
	ringBufferAdd(&ringBufferErrorList, timestamp, moduleId, errorCode);
}

ErrorDescription* errorFetch(void)
{
	/* Fetch error description from global ring buffer */
	return ringBufferFetch(&ringBufferErrorList);
}

size_t errorCount(void)
{
	return ringBufferCount(&ringBufferErrorList);
}

void errorDeinit(void)
{
	
}

uint32_t hash_string(const char* str)
{
	uint32_t hash = 5381;
	char c;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return hash;
}

#undef MODULE_ID