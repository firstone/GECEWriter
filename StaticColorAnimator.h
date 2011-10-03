/*********************************************************************
 *
 *  File Name: StaticColorAnimator.h
 *
 *  Description: Returns light of a static color
 *
 *  Date Created: Sep 25, 2011
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
#ifndef __GE_CE_WRITER_STATIC_COLOR_ANIMATOR_H__
#define __GE_CE_WRITER_STATIC_COLOR_ANIMATOR_H__

#include <Color.h>
#include <Light.h>
#include <LightAnimator.h>

namespace ESoft {
  
  namespace GECEWriter {
    
    using GECEWriter::Light;
    
    class StaticColorAnimator : public LightAnimator {
    public:
      StaticColorAnimator(uint8_t brightness, Color color)
        : color_(color), brightness_(brightness) {} 

      bool isDone() { return true; }
      
    protected:
      Light getLight_() {
        return Light().setColor(color_).setBrightness(brightness_);
      }
        
    private:
      Color color_;
      uint8_t brightness_;
      
    };    
    
  }
}

#endif //__GE_CE_WRITER_STATIC_COLOR_ANIMATOR_H__


