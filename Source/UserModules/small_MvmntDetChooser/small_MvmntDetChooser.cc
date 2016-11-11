//
//	MyModule.cc		This file is a part of the IKAROS project
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

#include "small_MvmntDetChooser.h"

using namespace ikaros;

void
small_MvmntDetChooser::Init()
{
    demandAtt	= GetInputArray("DEMANDATTENTION"); 
	region		= GetInputArray("REGION");
	stateIn		= GetInputArray("STATEIN");
    coordsOut	= GetOutputArray("COORDSOUT");
	weightOut	= GetOutputArray("WEIGHTOUT");
	stateOut	= GetOutputArray("STATEOUT");    
}

/*void
small_MvmntDetChooser::SetSizes() {
	GetInputSize()
}*/

small_MvmntDetChooser::~small_MvmntDetChooser() {}

void
small_MvmntDetChooser::Tick()
{
	if (stateIn[0] == 2) {
		weightOut[0] = 1;
		if (demandAtt[0] == 1/* && input[2] == 0*/) {
			stateOut[0] = 4;
			/*  */
			switch ((int) region[0]) {
				case 1:
					coordsOut[0] = 25;
					coordsOut[1] = 37;
					coordsOut[2] = 0;
					break;
				case 2:
					coordsOut[0] = 75;
					coordsOut[1] = 37;
					coordsOut[2] = 0;
					break;
				case 3:
					coordsOut[0] = 125;
					coordsOut[1] = 37;
					coordsOut[2] = 0;
					break;
				case 4:
					coordsOut[0] = 25;
					coordsOut[1] = 113;
					coordsOut[2] = 0;
					break;
				case 5:
					coordsOut[0] = 75;
					coordsOut[1] = 113;
					coordsOut[2] = 0;
					break;
				case 6:
					coordsOut[0] = 125;
					coordsOut[1] = 113;
					coordsOut[2] = 0;
					break;
			}
		}
	} else if (stateIn[0] == 4) {
		weightOut[0] = 1;
		//TODO: check mvmnt here, but only if allowed. How distinguish
		// 		when allowed?
	} else {
		weightOut[0] = 0;
	}
}

// Install the module. This code is executed during start-up.
static InitClass init("small_MvmntDetChooser", &small_MvmntDetChooser::Create, "Source/UserModules/small_MvmntDetChooser/");


