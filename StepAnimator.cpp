/*********************************************************************
 *
 *  File Name: StepAnimator.cpp
 *
 *  Description: Applies animation to each bulb of the string
 *               one by one
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
#include "StepAnimator.h"

namespace ESoft {

  namespace GECEWriter {

    void StepAnimator::reset() {
      TrackAnimator::reset();
      animator_->reset();
    }
    
    Light StepAnimator::getLight_() {
      Light light = animator_->getLight().setAddr(curLight_);

      if (animator_->isDone()) {
        animator_->reset();
        curLight_++;
      }

      if (delay_ > 0)
        sleep_(delay_);

      return light;
    }

  }
}

