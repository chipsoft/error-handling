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

#include "error_ringbuffer.h"
#include "error_macros.h"

static void ringBufferAdd_(RingBuffer* rb, ErrorDescription error)
{
	ASSERT(rb)
	rb->errors[rb->tail] = error;
	rb->tail = (rb->tail + 1) % RING_BUFFER_SIZE;
	rb->count++;
}

void ringBufferInit(RingBuffer* rb)
{
	ASSERT(rb)
	rb->head = 0;
	rb->tail = 0;
	rb->count = 0;
}

void ringBufferAdd(RingBuffer* rb, uint32_t timestamp, uint32_t moduleId, uint16_t errorCode)
{
	ASSERT(rb);
	ErrorDescription error = { .timestamp = timestamp, .moduleId = moduleId, .errorCode = errorCode };
	ringBufferAdd_(rb, error);
}

ErrorDescription* ringBufferFetch(RingBuffer* rb)
{
	ASSERT(rb)
	if (rb->head == rb->tail) return NULL;
	ErrorDescription* error = &rb->errors[rb->head];
	rb->head = (rb->head + 1) % RING_BUFFER_SIZE;
	rb->count--;
	return error;
}

size_t ringBufferCount(const RingBuffer* rb)
{
	ASSERT(rb)
	return rb->count;
}

void ringBufferClear(RingBuffer* rb)
{
	ASSERT(rb)
	rb->head = 0;
	rb->tail = 0;
	rb->count = 0;
}
