/*********************************************************************
 *
 *  File Name: Color.h
 *
 *  Description: Color helper class
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
#ifndef __GE_CE_WRITER_COLOR_H__
#define __GE_CE_WRITER_COLOR_H__

#include <WProgram.h>

namespace ESoft {

  namespace GECEWriter {
    
    class Color {
    public:
      static const Color BLACK, RED, GREEN, BLUE, YELLOW, CYAN, VIOLET, WHITE;

      class Channel {
      public:
        Channel(uint8_t value) : value_(value) {}
	Channel(const Channel &channel) { value_ = channel.value_; }

        Channel &operator++() { value_++; return *this; }
        Channel operator++(int) { 
          Channel old(*this);
          value_++; 

          return old;
        }

        Channel &operator--() { value_--; return *this; }
        Channel operator--(int) { 
          Channel old(*this);
          value_--; 

          return old;
        }

        uint8_t getValue() const { return value_; }

        bool isMax() { return value_ == 0xF; }
        bool isMin() { return value_ == 0; }

        bool operator==(const Channel &channel) {
          return value_ == channel.value_;
        }

      private:
        uint8_t value_;
      };

      Color(uint8_t red, uint8_t green, uint8_t blue)
        : red_(red), green_(green), blue_(blue) {}

      Color(const Color &color) : red_(color.red_), green_(color.green_), blue_(color.blue_) {}

      const Channel &getRed() const { return red_; }
      const Channel &getGreen() const { return green_; }
      const Channel &getBlue() const { return blue_; }

      String toString() const {
        String str = "Color: ";
        
        str += static_cast<unsigned int>(red_.getValue());
        str += ":";
        str += static_cast<unsigned int>(green_.getValue());
        str += ":";
        str += static_cast<unsigned int>(blue_.getValue());

        return str;
      }

      bool operator==(const Color &color) {
        if (this == &color)
          return true;

        return red_ == color.red_
          && green_ == color.green_
          && blue_ == color.blue_;
      }

    protected:
      Channel red_, green_, blue_;
    };
    
  }

}

#endif //__GE_CE_WRITER_COLOR_H__
