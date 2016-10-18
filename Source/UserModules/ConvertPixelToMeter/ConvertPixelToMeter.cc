//
//	MyModule.cc		This file is a part of the IKAROS project
//
//    Copyright (C) 2012 <Author Name>
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//    See http://www.ikaros-project.org/ for more information.
//
//  This example is intended as a starting point for writing new Ikaros modules
//  The example includes most of the calls that you may want to use in a module.
//  If you prefer to start with a clean example, use he module MinimalModule instead.
//

#include "ConvertPixelToMeter.h"


// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;


void
ConvertPixelToMeter::Init()
{

    input		= GetInputMatrix("INPUT");
    output 		= GetOutputMatrix("OUTPUT");

    
}



ConvertPixelToMeter::~ConvertPixelToMeter()
{

    

}



void
ConvertPixelToMeter::Tick()
{

    const double xRes = 640;
    const double yRes = 480;

    const double FOV_h = 1; // horizontal field of view, in radians.
    const double FOV_v = 0.75; // vertical field of view, in radians.

    const double fXToZ = tan(FOV_h/2)*2;
    const double fYToZ = tan(FOV_v/2)*2;
    float x = input[0][3];
    float y = input[1][3];
    float z = input[2][3];
    // compensate for perspective

    float tx = (float)((x / xRes - 0.5) * z * fXToZ);
    float ty = (float)((0.5 - y / yRes) * z * fYToZ);
    float tz = z; //convert from mm to meter

    // shift to sensor coordinate system
    // x is pointing forwards and y to the side; z is up

    x = tz;
    y = -tx;
    z = ty;
	
	for (int i=0;i<4;i++) {
		output[i][i] = 1;
	}
    
    output[0][3] = x;
    output[1][3] = y;
    output[2][3] = z;

}



// Install the module. This code is executed during start-up.

static InitClass init("ConvertPixelToMeter", &ConvertPixelToMeter::Create, "Source/UserModules/ConvertPixelToMeter/");


