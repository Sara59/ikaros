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

#include "MvmntDetChooser.h"

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;


void
MvmntDetChooser::Init()
{
    input		= GetInputArray("INPUT");
    output 		= GetOutputArray("OUTPUT");   
}

MvmntDetChooser::~MvmntDetChooser() {}

void
MvmntDetChooser::Tick()
{
	switch ((int) input[0]) {
		case 1:
			output[0] = 0.3;
			output[1] = 0.7;
			output[2] = 2;
			break;
		case 2:
			output[0] = 0.5;
			output[1] = 0.7;
			output[2] = 2;
			break;
		case 3:
			output[0] = 0.7;
			output[1] = 0.7;
			output[2] = 2;
			break;
		case 4:
			output[0] = 0.3;
			output[1] = 0.3;
			output[2] = 2;
			break;
		case 5:
			output[0] = 0.5;
			output[1] = 0.3;
			output[2] = 2;
			break;
		case 6:
			output[0] = 0.7;
			output[1] = 0.3;
			output[2] = 2;
			break;
	}
}



// Install the module. This code is executed during start-up.

static InitClass init("MvmntDetChooser", &MvmntDetChooser::Create, "Source/UserModules/MvmntDetChooser/");


