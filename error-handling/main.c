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

#include <stdio.h>
#include <stdlib.h>

#include "ErrorHandling.h"
#include "ErrorMacros.h"

void handle_critical_error(void)
{
#ifndef NDEBUG
	while (1) {/* Endless loop to catch bug */ }
#else
	reboot_device();
#endif
}

void print_error_message(const char* error_type, const char* message, const char* file_name, int line)
{
	/* Different actions for release and debug build */
#ifdef _DEBUG
	/* Show error to developer */
	fprintf(stderr, "%s: %s (file %s, line %d)\n", error_type, message, file_name, line);
#else
	/* Possibly save error to eeprom/external memory */
	printf("Save error to eeprom: %s: %s (file %s, line %d)\n", error_type, message, file_name, line);
#endif
}

void reboot_device(void)
{
	printf("Reboot device\n");
}

static RingBuffer ringBuffer;

int main(int argc, char** argv)
{
	ringBufferInit(&ringBuffer);
	ErrorDescription* a = ringBufferGet(&ringBuffer);
	ringBufferAdd(&ringBuffer, 1, 2, 3);
	a = ringBufferGet(&ringBuffer);
	a = ringBufferGet(&ringBuffer);
	ASSERT(0)
	return 0;
}
