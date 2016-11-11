//
//	FaceMatrix.cc		This file is a part of the IKAROS project
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

#include "FaceMatrix.h"

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;

void
FaceMatrix::Init()
{

    face = GetInputMatrix("FACE");



    // Do the same for the outputs

    outputX = GetOutputArray("OUTPUTX");
    outputY = GetOutputArray("OUTPUTY");

    outputmatrix = GetOutputMatrix("OUTPUTMATRIX");

    //state = GetInputArray("STATE");
    //change_state = GetInputArray("CHANGESTATE");
    //value = GetInputArray("VALUE");

    
}



FaceMatrix::~FaceMatrix()
{

}



void
FaceMatrix::Tick()
{

	x = face[0][2];
	y = face[0][3];



	*outputX = float(x);
	*outputY = float(y); 



	//if(state[0] == 0){
	//	value[0] = float(0.3);
	//} else if(state[0] == float(1)){
	//	change_state[0] = float(2);
	//	value[0] = float(1);
	//} else if(state[0] == float(2)){
	//	value[0] = float(0.7);
	//} else {
	//	value[0] = 0;
	//}



}



// Install the module. This code is executed during start-up.

static InitClass init("FaceMatrix", &FaceMatrix::Create, "Source/UserModules/FaceMatrix/");


