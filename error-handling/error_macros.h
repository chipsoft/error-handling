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

#include "error_macros_config.h"

/* This function may print info about error and save this information to NVRAM memory for future use in diagnostic purposes
 * May be differ for debug and release build
 */
extern void print_error_message(const char* error_type, const char* message, const char* file_name, int line);

/* This function handle critical error.
 * May be differ for debug and release build. For debug build, as rule, this function run infinite loop and make some signal
 * to developer (turn on led red).
 * For release build this function reboot device
 */
extern void handle_critical_error(void);

/*
 The do - while loop is used in these macros to ensure that the statements inside the loop
 are always executed at least once.This is useful in cases where the macro is used as a standalone
 statement(e.g., PANIC("foo");), since it guarantees that the error message will be printed and
 the program will be terminated even if the macro is not followed by a semicolon.
 */

 /* Panic macros */
#ifdef config_PANIC_PRINT_MESSAGE
/* Panic with print message */
#define PANIC(msg) do { \
    print_error_message("PANIC", msg, __FILE__, __LINE__); \
    handle_critical_error(); \
} while (0)
#else
/* Panic without print message */
#define PANIC(msg) do { \
    handle_critical_error(); \
} while (0)
#endif

#define PANIC_() PANIC("")

/* TODO macros */
#ifdef config_TODO_DEFINED
#define TODO(msg) do { \
    print_error_message("TODO", msg, __FILE__, __LINE__); \
    handle_critical_error(); \
} while (0)
#else
#define TODO(msg)
#endif

#ifdef config_TODO_DEFINED
#define TODO_() TODO("")
#else
#define TODO_()
#endif

/* UNIMPLEMENTED macros */
#ifdef config_UNIMPLEMENTED_DEFINED
#define UNIMPLEMENTED() do { \
    print_error_message("UNIMPLEMENTED", "", __FILE__, __LINE__); \
    handle_critical_error(); \
} while (0)
#else
#define UNIMPLEMENTED()
#endif

/* ASSERT macros */
#ifdef config_ASSERT_DEFINED
#define ASSERT(x) \
  if (!(x)) { \
	print_error_message("ASSERT", "", __FILE__, __LINE__); \
    handle_critical_error(); \
  }
#else
#define ASSERT(x)
#endif
