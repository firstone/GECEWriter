/*********************************************************************
 *
 *  File Name: Rainbow.cpp
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
#include "Rainbow.h"

namespace ESoft {
  
  namespace GECEWriter {

    const Rainbow Rainbow::RED(Rainbow::RED_, Color(0xF, 0, 0));
    const Rainbow Rainbow::BEGIN(Rainbow::BEGIN_, Color(0xF, 0, 0));

    const Rainbow Rainbow::VIOLET(Rainbow::VIOLET_, Color(0xF, 0, 0xF));
    const Rainbow Rainbow::END(Rainbow::END_, Color(0xF, 0, 0xF));

    Rainbow &Rainbow::operator++() {
      switch (range_) {

      case BEGIN_:
      case RED_:
        curColor_.green_++;
        if (curColor_.green_.isMax())
          range_ = YELLOW_;
          
        break;

      case YELLOW_:
        curColor_.red_--;
        if (curColor_.red_.isMin())
          range_ = GREEN_;
          
        break;

      case GREEN_:
        curColor_.blue_++;
        if (curColor_.blue_.isMax())
          range_ = CYAN_;
          
        break;

      case CYAN_:
        curColor_.green_--;
        if (curColor_.green_.isMin())
          range_ = BLUE_;
        
        break;

      case BLUE_:
        curColor_.red_++;
        if (curColor_.red_.isMax())
          range_ = VIOLET_;
        
        break;

      case VIOLET_:
        range_ = END_;
      
      }

      return *this;
    }

    Rainbow &Rainbow::operator--() {
      switch (range_) {

      case VIOLET_:
      case END_:
        curColor_.red_--;
        if (curColor_.red_.isMin())
        range_ = BLUE_;
        
        break;

      case BLUE_:
        curColor_.green_++;
        if (curColor_.green_.isMax())
          range_ = CYAN_;
          
        break;

      case CYAN_:
        curColor_.blue_--;
        if (curColor_.blue_.isMin())
          range_ = GREEN_;
        
        break;

      case GREEN_:
        curColor_.red_++;
        if (curColor_.red_.isMax())
          range_ = YELLOW_;
        
        break;

      case YELLOW_:
        curColor_.green_--;
        if (curColor_.green_.isMin())
          range_ = RED_;
        
        break;

      case RED_:
        range_ = BEGIN_;
      }
      
      return *this;
    }
    
  }
}
