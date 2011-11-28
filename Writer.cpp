/*********************************************************************
 *
 *  File Name: Writer.cpp
 *
 *  Description: Physical signal writer
 *
 *  Date Created: Sep 20, 2011
 * 
 *  Revision History:
 *  
 *  NNN - MMM YY - Name - Change
 *  001 - Nov 11 - firstone - Added reverse address assignment and bad pixel exception
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
#include "Writer.h"

namespace ESoft {
  
  namespace GECEWriter {

    void Writer::initialize(uint8_t track, uint8_t lightCount, uint8_t brightness, 
        bool visual /* = false */, bool reverse /* = false */, uint8_t badPixel /* = 255 */) {

      uint8_t tracks[] = { track };

      Writer writer(1, tracks);
      Light lights[1];

      lights[0].setBrightness(brightness).setTrack(track);
      if (visual) {
        lights[0].setColor(Color::WHITE);
        writeAll_(writer, lights, lightCount, reverse, badPixel);
      }

      lights[0].setColor(Color::BLACK);
      writeAll_(writer, lights, lightCount, reverse, badPixel);

    }

    void Writer::writeAll_(Writer &writer, Light lights[], uint8_t lightCount, 
      bool reverse, uint8_t badPixel) {

      uint8_t curAddr = 0;
      for (int i = 0; i < lightCount; i++) {
        if (i == badPixel)
          lights[0].setAddr(lightCount);
        else	
          lights[0].setAddr(reverse ? lightCount - 1 - curAddr++ : curAddr++);

        writer.write(1, lights);
      }
    }
    
  }
  
}

