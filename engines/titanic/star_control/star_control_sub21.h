/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef TITANIC_STAR_CONTROL_SUB21_H
#define TITANIC_STAR_CONTROL_SUB21_H

#include "titanic/star_control/star_control_sub20.h"
#include "titanic/star_control/star_control_sub24.h"

namespace Titanic {

class CStarControlSub21 : public CStarControlSub20 {
private:
	CStarControlSub24 _sub24;
public:
	CStarControlSub21(const CStar20Data *src);
	virtual ~CStarControlSub21() {}

	virtual void proc9(FVector &v1, FVector &v2, FMatrix &matrix);
	virtual void proc10(const FVector &v1, const FVector &v2, const FVector &v3, const FMatrix &m);
	virtual void proc11(CErrorCode &errorCode, FVector &v, const FMatrix &m);
};

} // End of namespace Titanic

#endif /* TITANIC_STAR_CONTROL_SUB21_H */
