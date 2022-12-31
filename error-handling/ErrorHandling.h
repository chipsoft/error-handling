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

#pragma once
#include <stdint.h>

#define RING_BUFFER_SIZE 100

/**
 * @brief This is presentation of error
 *
 * This structure contain detailed information about error: timestamp, moduleId, errorCode
 */
struct ErrorDescription_
{
	uint32_t timestamp; /* Time when error is occur */
	uint32_t moduleId;  /* Module Id */
	uint16_t errorCode; /* Error code corresponding to the module */
};

typedef struct ErrorDescription_ ErrorDescription;

/**
 * @brief This is presentation of RingBuffer to store errors
 *
 */
struct RingBuffer_
{
	ErrorDescription errors[RING_BUFFER_SIZE];
	int head;
	int tail;
	int count;
};

typedef struct RingBuffer_ RingBuffer;

/**
 * @brief This function initialize RingBuffer
 *
 * Run this function before using ring buffer
 * @param rb Pointer to ring buffer structure
 */
void ringBufferInit(RingBuffer* rb);

/**
 * @brief This function add error to ring buffer
 *
 * This function add error to ring buffer
 * @param rb Pointer to ring buffer structure
 * @param timestamp Time when error is occur
 * @param moduleId Module Id
 * @param errorCode Error code, that appear
 */
void ringBufferAdd(RingBuffer* rb, uint32_t timestamp, uint32_t moduleId, uint16_t errorCode);

/**
 * @brief Get error description from RingBuffer in queue order
 *
 * This function gets error description from ring buffer in queue order
 * @param rb Pointer to ring buffer structure
 * @return ErrorDescription* pointer to element. Return NULL, if ring buffer is empty
 */
ErrorDescription* ringBufferFetch(RingBuffer* rb);

/**
 * @brief Get number of elements in ring buffer
 *
 * This function return number of elements in ring buffer
 * @param rb Pointer to ring buffer structure
 * @return size_t Return number of element in ring buffer
 */
size_t ringBufferCount(const RingBuffer* rb);

/**
 * @brief Clear ring buffer
 *
 * This function clear ring buffer
 */
void ringBufferClear(RingBuffer* rb);

/**
 * @brief Function to get hash value from string
 *
 * This function calculates hash value from string with djb2 algorithm
 * @param str Pointer to string to hash
 * @return uint32_t Return hash value of string
 */
uint32_t hash_string(const char* str);
