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

using namespace ikaros;

void
discovery_MvmntDetChooser::Init()
{
    demandAtt	= GetInputArray("DEMANDATTENTION"); 
	region		= GetInputArray("REGION");
	stateIn		= GetInputArray("STATEIN");
    coordsOut	= GetOutputArray("COORDSOUT");
	weightOut	= GetOutputArray("WEIGHTOUT");
	stateOut	= GetOutputArray("STATEOUT");   
}

discovery_MvmntDetChooser::~discovery_MvmntDetChooser() {}

void
discovery_MvmntDetChooser::Tick()
{
	if (stateIn[0] == 0) {
		weightOut[0] = 1;
		if (demandAtt[0] == 1/* && input[2] == 0*/) {
			stateOut[0] = 1;
			
			switch ((int) region[0]) {
				case 1:
					coordsOut[0] = 106;
					coordsOut[1] = 120;
					coordsOut[2] = 2000;
					break;
				case 2:
					coordsOut[0] = 3*106;
					coordsOut[1] = 120;
					coordsOut[2] = 2000;
					break;
				case 3:
					coordsOut[0] = 5*106;
					coordsOut[1] = 120;
					coordsOut[2] = 2000;
					break;
				case 4:
					coordsOut[0] = 106;
					coordsOut[1] = 360;
					coordsOut[2] = 2000;
					break;
				case 5:
					coordsOut[0] = 3*106;
					coordsOut[1] = 360;
					coordsOut[2] = 2000;
					break;
				case 6:
					coordsOut[0] = 5*106;
					coordsOut[1] = 360;
					coordsOut[2] = 2000;
					break;
			}
		}
	} else if (stateIn[0] == 1) {
		weightOut[0] = 0.2;
		if (demandAtt[0] == 1) {
			stateOut[0] = 1;
			switch ((int) region[0]) {
				case 1:
					coordsOut[0] = 106;
					coordsOut[1] = 120;
					coordsOut[2] = 2000;
					break;
				case 2:
					coordsOut[0] = 3*106;
					coordsOut[1] = 120;
					coordsOut[2] = 2000;
					break;
				case 3:
					coordsOut[0] = 5*106;
					coordsOut[1] = 120;
					coordsOut[2] = 2000;
					break;
				case 4:
					coordsOut[0] = 106;
					coordsOut[1] = 360;
					coordsOut[2] = 2000;
					break;
				case 5:
					coordsOut[0] = 3*106;
					coordsOut[1] = 360;
					coordsOut[2] = 2000;
					break;
				case 6:
					coordsOut[0] = 5*106;
					coordsOut[1] = 360;
					coordsOut[2] = 2000;
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
