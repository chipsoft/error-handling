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

#include "error_ringbuffer.h"
#include "error_macros.h"
#include "error_handle.h"
#include "led.h"
#include "motor.h"

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
	/* Error module should initialize before any of modules */
	errorInit();
	/* Initialize all of modules */
	ledInit();
	motorInit();
	/* Regular work */
	ledSetState(1);
	motorRun();
	ledSetState(0);
	motorStop();
	/* Fetch error if it occur */
	size_t error_count = errorCount();
	if (error_count)
	{
		/* Print all of error */
		printf("Found %d errors:\r\n", error_count);
		for (size_t i = 0; i < error_count; ++i)
		{
			ErrorDescription* error_desc = errorFetch();
			ASSERT(error_desc)
			printf("Error #%d: timestamp = %d, module = %08X, code = %04X\r\n", i, error_desc->timestamp, error_desc->moduleId, error_desc->errorCode);
		}
	}
	else
	{
		printf("No error found\r\n");
	}
	/* De-initialize all of modules */
	ledDeinit();
	motorDeinit();
	/* Error module should de-initialize after all of modules */
	errorDeinit();
	return 0;
}
