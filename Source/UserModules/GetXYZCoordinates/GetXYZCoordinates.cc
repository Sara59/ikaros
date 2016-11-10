//
//	GetXYZCoordinates.cc		This file is a part of the IKAROS project
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

#include "GetXYZCoordinates.h"

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;

void
GetXYZCoordinates::Init()
{

    xyinput = GetInputMatrix("XYINPUT");

    depth = GetInputMatrix("DEPTH");
    depth_size_x = GetInputSizeX("DEPTH");
    depth_size_y = GetInputSizeY("DEPTH");

    // Do the same for the outputs

    outputX = GetOutputArray("OUTPUTX");
    outputY = GetOutputArray("OUTPUTY");
    outputZ = GetOutputArray("OUTPUTZ");

    outputmatrix = GetOutputMatrix("OUTPUTMATRIX");

    state = GetInputArray("STATE");
    change_state = GetInputArray("CHANGESTATE")
    value = GetInputArray("VALUE")

    
}



GetXYZCoordinates::~GetXYZCoordinates()
{

}



void
GetXYZCoordinates::Tick()
{

	x = xyinput[0][0]*640;
	y = xyinput[0][1]*480;
	
	int xcord = (int) x;
	int ycord = (int) y;


        z = depth[ycord][xcord];


	*outputX = float(x);
	*outputY = float(y); 
	*outputZ = float(z);

	outputmatrix[0][0] = 1; 
	outputmatrix[0][1] = 0; 
	outputmatrix[0][2] = 0; 
	outputmatrix[0][3] = x; 

	outputmatrix[1][0] = 0; 
	outputmatrix[1][1] = 1; 
	outputmatrix[1][2] = 0; 
	outputmatrix[1][3] = y; 

	outputmatrix[2][0] = 0; 
	outputmatrix[2][1] = 0; 
	outputmatrix[2][2] = 1; 
	outputmatrix[2][3] = z; 

	outputmatrix[3][0] = 0; 
	outputmatrix[3][1] = 0; 
	outputmatrix[3][2] = 0; 
	outputmatrix[3][3] = 1; 

	if(state == 0){
		value = 0.3;
	} else if(state == 1){
		change_state = 2;
		value = 1;
	} else if(state == 2){
		value = 0.7;
	} else {
		value = 0;
	}




}



// Install the module. This code is executed during start-up.

static InitClass init("GetXYZCoordinates", &GetXYZCoordinates::Create, "Source/UserModules/GetXYZCoordinates/");


