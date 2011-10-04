/*********************************************************************
 *
 *  File Name: Light.h
 *
 *  Description: Individual light class
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
#ifndef __GE_CE_WRITER_LIGHT_H__
#define __GE_CE_WRITER_LIGHT_H__

#include <WProgram.h>

#include "Color.h"

namespace ESoft {
  
  namespace GECEWriter {

    class Light {
    public:
      static const Light SKIP_LIGHT;
    
      Light() : data_(0) {}

      Light &setAddr(uint8_t addr) { 
        addr_ = addr; 

        return *this;
      }

      uint8_t getBrightness() { return bright_; }
      Light &setBrightness(uint8_t bright) { 
        bright_ = bright; 

        return *this;
      }

      Light &dim() {
        if (bright_ > 0)
          bright_--;

        return *this;
      }

      Light &bright() {
        if (bright_ < 255)
          bright_++;

        return *this;
      }

      Light &setColor(const Color &color) {
        red_ = color.getRed().getValue();
        green_ = color.getGreen().getValue();
        blue_ = color.getBlue().getValue();

        return *this;
      }
        
      Light &setTrack(uint8_t track) {
        track_ = track;
          
        return *this;
      }
        
      uint8_t getTrack() { return track_; }
        
      uint32_t getData() { return data_; }
      void setData(uint8_t *data) { 
        field1_ = data[0];
        field2_ = data[1];
        field3_ = data[2];
        field4_ = data[3];
      }

      // if skip bit is set, the light is equal regardless of the other fields
      bool operator==(const Light &light) { 
        return skip_ == light.skip_ || data_ == light.data_; 
      }

      bool operator!=(const Light &light) { return !(*this == light); }
    
    private:
      Light(bool skip) : data_(0), skip_(skip) {}
    
      uint8_t track_;
      union {
        uint32_t data_;
        struct {
          uint32_t red_ : 4;
          uint32_t green_ : 4;
          uint32_t blue_ : 4;
          uint32_t bright_ : 8;
          uint32_t addr_ : 6;
          uint32_t skip_ : 1;
        };
        struct {
          uint8_t field4_;
          uint8_t field3_;
          uint8_t field2_;
          uint8_t field1_;
        };
      };
    };
  }
}

#endif //__GE_CE_WRITER_LIGHT_H__
