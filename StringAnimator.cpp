/*********************************************************************
 *
 *  File Name: StringAnimator.cpp
 *
 *  Description: Applies animation steps to all bulbs together
 *
 *  Date Created: Sep 22, 2011
 * 
 *  Revision History:
 *  
 *  NNN - MMM YY - Name - Change
 *  
 *  Copyright (C) 2011, Erissoft
 *  
 *  This file is part of Erissoft GE CE library
 *
 *  GE CE library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *  
 *********************************************************************/
#include "StringAnimator.h"

namespace ESoft {

  namespace GECEWriter {

    void StringAnimator::reset() {
      TrackAnimator::reset();
      animator_->reset();
    }

    Light StringAnimator::getLight_() {
      if (curLight_ == 0)
        light_ = animator_->getLight();

      light_.setAddr(curLight_++);

      if (curLight_ == lightCount_)
        curLight_ = 0;

      return light_;
    }

  }
}

