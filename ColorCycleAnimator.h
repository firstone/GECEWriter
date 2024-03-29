/*********************************************************************
 *
 *  File Name: ColorCycleAnimator.h
 *
 *  Description: Color array animator
 *
 *  Date Created: Sep 25, 2011
 * 
 *  Revision History:
 *  
 *  NNN - MMM YY - Name - Change
 *  
 *  Copyright (C) 2011, Erissoft
 *  
 *  This file is part of Erissoft GE CE Lights Controller
 *
 *  GE CE Lights Controller is free software; you can redistribute it and/or
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
#ifndef __GE_CE_WRITER_COLOR_CYCLE_ANIMATOR_H__
#define __GE_CE_WRITER_COLOR_CYCLE_ANIMATOR_H__

#include <ColorCycle.h>
#include <Light.h>
#include <LightAnimator.h>

namespace ESoft {
  
  namespace GECEWriter {
    
    class ColorCycleAnimator : public LightAnimator {
    public:
      ColorCycleAnimator(ColorCycle cycle, uint8_t brightness, int lightCount); 

      void reset();

    protected:
      Light getLight_();
        
    private:
      ColorCycle cycle_;
      uint8_t brightness_;
      int lightCount_, curCount_;
  
    };    
    
  }
}

#endif //__GE_CE_LIGHTS_COLOR_CYCLE_ANIMATOR_H__


