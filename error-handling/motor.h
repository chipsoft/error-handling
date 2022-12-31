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

/**
* @brief Motor initialization function
*
* Run this function before using motor
*/
void motorInit(void);

/**
* @brief Run motor
*
* Run motor
*/
void motorRun(void);

/**
* @brief Stop motor
*
* Stop motor
*/
void motorStop(void);

/**
* @brief Motor de-initialization function
*
* Run this function to de-initialize motor (to switch to sleep mode, for example)
*/
void motorDeinit(void);
