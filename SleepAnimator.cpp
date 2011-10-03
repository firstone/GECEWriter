/*********************************************************************
 *
 *  File Name: SleepAnimator.cpp
 *
 *  Description: Stops execution for a number of milliseconds
 *
 *  Date Created: Sep 21, 2011
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
#include "SleepAnimator.h"

namespace ESoft {
  
  namespace GECEWriter {

    bool SleepAnimator::isDone() {
      return !startSleep_ || static_cast<long>(millis() - wakeTime_) >= 0;
    }
    
    void SleepAnimator::reset() {
      startSleep_ = false;
    }
    
    Light SleepAnimator::getLight_() {
      if (!startSleep_) {
        startSleep_ = true;
        wakeTime_ = millis() + ms_;
      }
      
      return Light::SKIP_LIGHT;
    }
    
    
  }

}


