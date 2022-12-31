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

/* This is config file for error handling. To turn off some option, just comment line with parameter and define
 * You can also set this parameters via command line
 */

 /* For panic command we always panic, no other options available :)*/

#ifdef NDEBUG
/* Configuration for Release */
#undef config_PANIC_PRINT_MESSAGE
#undef config_TODO_DEFINED
#undef config_UNIMPLEMENTED_DEFINED
#undef config_ASSERT_DEFINED
#else
/* Configuration for Debug */
#define config_PANIC_PRINT_MESSAGE
#define config_TODO_DEFINED
#define config_UNIMPLEMENTED_DEFINED
#define config_ASSERT_DEFINED
#endif

