//
//	  discovery_MvmntDetChooser.cc		This file is a part of the IKAROS project
//
//    Copyright (C) 2016 Rasmus olofzon
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

#include "discovery_MvmntDetChooser.h"
#include <stdlib.h> 
#include <iostream>

using namespace ikaros;
using namespace std;

void
discovery_MvmntDetChooser::Init()
{
    demandAtt	= GetInputArray("DEMANDATTENTION"); 
	region		= GetInputArray("REGION");
	stateIn		= GetInputArray("STATEIN");
    coordsOut	= GetOutputMatrix("COORDSOUT");
	weightOut	= GetOutputArray("WEIGHTOUT");
	stateOut	= GetOutputArray("STATEOUT"); 
	
	for (int i=0;i<4;i++) 
		for (int j=0;j<4;j++) 
			coordsOut[i][j] = 0;
	coordsOut[0][0] = 1;
	coordsOut[1][1] = 1;
	coordsOut[2][2] = 1;
	coordsOut[3][3] = 1;
	
	stateIn[0] = 0;  
}

discovery_MvmntDetChooser::~discovery_MvmntDetChooser() {}

void
discovery_MvmntDetChooser::Tick()
{
	cout << "d_mdc: STATEIN = " << stateIn[0] << endl;
	cout << "d_mdc: demandAtt = " << demandAtt[0] << endl;
	if (stateIn[0] == 0) {
		weightOut[0] = 1;
		stateOut[0] = stateIn[0];
		
		if (demandAtt[0] == 1/* && input[2] == 0*/) {
			stateOut[0] = 1;
			
			switch ((int) region[0]) {
				case 1:
					coordsOut[0][3] = 106;
					coordsOut[1][3] = 120;
					coordsOut[2][3] = 2000;
					break;
				case 2:
					coordsOut[0][3] = 3*106;
					coordsOut[1][3] = 120;
					coordsOut[2][3] = 2000;
					break;
				case 3:
					coordsOut[0][3] = 5*106;
					coordsOut[1][3] = 120;
					coordsOut[2][3] = 2000;
					break;
				case 4:
					coordsOut[0][3] = 106;
					coordsOut[1][3] = 360;
					coordsOut[2][3] = 2000;
					break;
				case 5:
					coordsOut[0][3] = 3*106;
					coordsOut[1][3] = 360;
					coordsOut[2][3] = 2000;
					break;
				case 6:
					coordsOut[0][3] = 5*106;
					coordsOut[1][3] = 360;
					coordsOut[2][3] = 2000;
					break;
			}
		}
	} else if (stateIn[0] == 1) {
		weightOut[0] = 0.2;
		stateOut[0] = stateIn[0];
		
		if (demandAtt[0] == 1) {
			stateOut[0] = 1;
			switch ((int) region[0]) {
				case 1:
					coordsOut[0][3] = 106;
					coordsOut[1][3] = 120;
					coordsOut[2][3] = 2000;
					break;
				case 2:
					coordsOut[0][3] = 3*106;
					coordsOut[1][3] = 120;
					coordsOut[2][3] = 2000;
					break;
				case 3:
					coordsOut[0][3] = 5*106;
					coordsOut[1][3] = 120;
					coordsOut[2][3] = 2000;
					break;
				case 4:
					coordsOut[0][3] = 106;
					coordsOut[1][3] = 360;
					coordsOut[2][3] = 2000;
					break;
				case 5:
					coordsOut[0][3] = 3*106;
					coordsOut[1][3] = 360;
					coordsOut[2][3] = 2000;
					break;
				case 6:
					coordsOut[0][3] = 5*106;
					coordsOut[1][3] = 360;
					coordsOut[2][3] = 2000;
					break;
			}
		}
	} else {
		weightOut[0] = 0;
		stateOut[0] = stateIn[0];
	}
}

// Install the module. This code is executed during start-up.
static InitClass init("discovery_MvmntDetChooser", &discovery_MvmntDetChooser::Create, "Source/UserModules/discovery_MvmntDetChooser/");
