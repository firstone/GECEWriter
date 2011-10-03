/*********************************************************************
 *
 *  File Name: LightAnimator.cpp
 *
 *  Description: Animator for a single light class
 *
 *  Date Created: Sep 20, 2011
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
#include "LightAnimator.h"

#include "CppDefs.h"

namespace ESoft {
  
  namespace GECEWriter {

    Light LightAnimator::getLight() {
      if (shouldSleep_) {
        if (static_cast<long>(millis() - wakeTime_) < 0)
          return Light::SKIP_LIGHT;

        shouldSleep_ = false;
      }

      return getLight_();
    }

    void LightAnimator::sleep_(unsigned int ms) {
      shouldSleep_ = true;
      wakeTime_ = millis() + ms;
    }
    
  }

}


