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
#include "error_ringbuffer.h"

/**
* @brief Error module initialization function
*
* Run this function before using error handling
*/
void errorInit(void);

/**
* @brief Add error to ring buffer
*
* Add error to ring buffer
* @param timestamp Timestamp of error
* @param moduleId Module ID of error (from MODULE_ID macros)
* @param errorCode Error code within moduleId
*/
void errorAdd(uint32_t timestamp, uint32_t moduleId, uint16_t errorCode);

/**
* @brief Fetch error from ring buffer
*
* Fetch error from ring buffer
* @return error Pointer to error description structure
*/
ErrorDescription* errorFetch(void);

/**
* @brief Get error count in ring buffer
*
* Get error count in ring buffer
*/
size_t errorCount(void);

/**
* @brief Error module de-initialization function
*
* Run this function to de-initialize error handling (to switch to sleep mode, for example)
*/
void errorDeinit(void);

/**
 * @brief Function to get hash value from string
 *
 * This function calculates hash value from string with djb2 algorithm
 * @param str Pointer to string to hash
 * @return uint32_t Return hash value of string
 */
uint32_t hash_string(const char* str);

