/*********************************************************************
 *
 *  File Name: Rainbow.h
 *
 *  Description: Rainbow color iterator
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
#ifndef __GE_CE_WRITER_RAINBOW_H__
#define __GE_CE_WRITER_RAINBOW_H__

#include "Color.h"

namespace ESoft {
  
  namespace GECEWriter {

    class Rainbow {
    private:
      enum RANGE_ { BEGIN_, RED_, YELLOW_, GREEN_, CYAN_, BLUE_, VIOLET_, END_ };

    public:
      static const Rainbow RED, VIOLET, BEGIN, END;

      Rainbow() : range_(RED_), curColor_(Color::RED) {}
      Rainbow(const Rainbow &rain) : range_(rain.range_), curColor_(rain.curColor_) {}

      Color getColor() { return Color(curColor_); }

      Rainbow &operator+=(int step) {
        for (int i = 0; i < step; i++)
          ++(*this);

	return *this;
      }

      Rainbow &operator++();
      Rainbow operator++(int) {
        Rainbow old(*this);

        ++(*this);

        return old;
      }

      Rainbow &operator-=(int step) {
        for (int i = 0; i < step; i++)
          --(*this);

        return *this;
      }

      Rainbow &operator--();
      Rainbow operator--(int) {
        Rainbow old(*this);

        --(*this);

        return old;
      }

      bool operator==(const Rainbow &rain) {
        if (this == &rain)
          return true;

        return range_ == rain.range_ 
          && curColor_ == rain.curColor_;
      }

      bool operator!=(const Rainbow &rain) { return !(*this == rain); }

    private:
      class RainColor;

      Rainbow(RANGE_ range, const Color &color) : range_(range), curColor_(color) {}

      class RainColor : public Color {
        friend class Rainbow;

      public:
        RainColor(const Color &color) : Color(color) {}
      };

      RainColor curColor_;
      RANGE_ range_;
    };
    
  }

}

#endif //__GE_CE_WRITER_RAINBOW_H__
