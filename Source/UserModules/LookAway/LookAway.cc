//
//	LookAway.cc		This file is a part of the IKAROS project
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

#include "LookAway.h"
#include <iostream>
using namespace std;
// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;

void
LookAway::Init()
{

    input_matrix = GetInputMatrix("INPUT");

    picture = GetInputMatrix("PICTURE");
    picture_size_x = GetInputSizeX("PICTURE");
    picture_size_y = GetInputSizeY("PICTURE");

    // Do the same for the outputs


    outputX = GetOutputArray("OUTPUTX");
    outputY = GetOutputArray("OUTPUTY");
    outputZ = GetOutputArray("OUTPUTZ");

    output_matrix = GetOutputMatrix("OUTPUTMATRIX");
    state = GetInputArray("STATE");
    value = GetOutputArray("VALUE");

	state[0] = 0;

    
}



LookAway::~LookAway()
{

}



void
LookAway::Tick()
{



//	printf("INPUTSTATE = " + state + "\n");

		oldx = input_matrix[0][3];
		oldy = input_matrix[1][3]; 
		oldz = input_matrix[2][3];

		if(picture_size_x > (oldx + 10)){
			newx = oldx + 10; 
		}else{ 
			newx = oldx - 10; 
		}
		newy = oldy; 
		newz = oldz; 

		*outputX = float(newx);
		*outputY = float(newy); 
		*outputZ = float(newz);


		if ((rand() % 2) + 1 == 2){
			output_matrix[0][0] = 1; 
			output_matrix[0][1] = 0; 
			output_matrix[0][2] = 0; 
			output_matrix[0][3] = 600; 

			output_matrix[1][0] = 0; 
			output_matrix[1][1] = 1; 
			output_matrix[1][2] = 0; 
			output_matrix[1][3] = 240; 

			output_matrix[2][0] = 0; 
			output_matrix[2][1] = 0; 
			output_matrix[2][2] = 1; 
			output_matrix[2][3] = picture[600][240]; 

			output_matrix[3][0] = 0; 
			output_matrix[3][1] = 0; 
			output_matrix[3][2] = 0; 
			output_matrix[3][3] = 1; 

		} else {
			output_matrix[0][0] = 1; 
			output_matrix[0][1] = 0; 
			output_matrix[0][2] = 0; 
			output_matrix[0][3] = 40; 

			output_matrix[1][0] = 0; 
			output_matrix[1][1] = 1; 
			output_matrix[1][2] = 0; 
			output_matrix[1][3] = 240; 

			output_matrix[2][0] = 0; 
			output_matrix[2][1] = 0; 
			output_matrix[2][2] = 1; 
			output_matrix[2][3] = picture[40][240]; 

			output_matrix[3][0] = 0; 
			output_matrix[3][1] = 0; 
			output_matrix[3][2] = 0; 
			output_matrix[3][3] = 1; 
		}
		
		
		if(state[0] == float(2)){
			value[0] = float(1);
		} else {
			value[0] = float(0);
		}


}



// Install the module. This code is executed during start-up.

static InitClass init("LookAway", &LookAway::Create, "Source/UserModules/LookAway/");


