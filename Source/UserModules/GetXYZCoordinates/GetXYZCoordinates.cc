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
#include <iostream>
using namespace std;

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

    outputmatrix = GetOutputMatrix("OUTPUTMATRIX");
    facematrix = GetOutputMatrix("OUTPUTFACEMATRIX");

    state = GetInputArray("STATE");
    change_state = GetOutputArray("CHANGESTATE");
    value = GetOutputArray("VALUE");

	state[0] = 0;

    
}



GetXYZCoordinates::~GetXYZCoordinates()
{

}



void
GetXYZCoordinates::Tick()
{


//	printf("INPUTSTATE = " + state + "\n");
	x = xyinput[0][0]*depth_size_x;
	y = xyinput[0][1]*depth_size_y;
	
	int xcord = (int) x;
	int ycord = (int) y;


        z = depth[ycord][xcord];

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

	if(z < 700){
		outputX[0] = 0;
		outputX[1] = depth_size_x;
		outputY[0] = 0; 
		outputY[1] = depth_size_y;
	}else if(z >= 700 && z < 1500){
		if((xcord - 200) < 0){
			outputX[0] = 0;
		} else {
			outputX[0] = xcord - 200;			
		}
		if((xcord + 200) > depth_size_x){
			outputX[1] = depth_size_x;
		} else {
			outputX[1] = xcord + 200;			
		}
		if((ycord - 200) < 0){
			outputY[0] = 0;
		} else {
			outputY[0] = ycord - 200;			
		} 
		outputY[1] = depth_size_y;
	}else if(z >= 1500){
		if((xcord - 100) < 0){
			outputX[0] = 0;
		} else {
			outputX[0] = xcord - 100;			
		}
		if((xcord + 100) > depth_size_x){
			outputX[1] = depth_size_x;
		} else {
			outputX[1] = xcord + 100;			
		}
		if((ycord - 100) < 0){
			outputY[0] = 0;
		} else {
			outputY[0] = ycord - 100;			
		} 
		outputY[1] = depth_size_y;
	}

	if(state[0] == 0){
		value[0] = float(0.3);
		change_state[0] = float(1);
	} else if(state[0] == float(1)){
		change_state[0] = float(2);
		value[0] = float(1);
	} else if(state[0] == float(2)){
		value[0] = float(0.7);
	} else {
		value[0] = 0;
		change_state[0] = state[0];
	}

}



// Install the module. This code is executed during start-up.

static InitClass init("GetXYZCoordinates", &GetXYZCoordinates::Create, "Source/UserModules/GetXYZCoordinates/");


