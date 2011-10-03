/*********************************************************************
 *
 *  File Name: RainbowAnimator.cpp
 *
 *  Description: Rainbow colors animator
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
#include "RainbowAnimator.h"

namespace ESoft {
  
  namespace GECEWriter {
    
    RainbowAnimator::RainbowAnimator(uint8_t brightness, uint8_t start /* = 0 */,
        uint8_t step /* = 1 */, bool reverse /* = false */) 
      : brightness_(brightness), step_(step), reverse_(reverse) {
      reset();
      change_(start);
    }
     
    bool RainbowAnimator::isDone() {
      return reverse_ ? rain_ == Rainbow::BEGIN : rain_ == Rainbow::END; 
    }

    void RainbowAnimator::reset() { 
      rain_ = reverse_ ? Rainbow::VIOLET : Rainbow::RED; 
    }
      
    Light RainbowAnimator::getLight_() {  
      Light light = Light().setBrightness(brightness_).setColor(rain_.getColor());
      change_(step_);

      return light;
    }

    void RainbowAnimator::change_(int step) {
      if (reverse_)
        rain_ -= step;
      else
        rain_ += step;
    }
    
  }

}
