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
	getX		= GetInputArray("GETX"); 	
	getY		= GetInputArray("GETY");	
	
    coordsOut	= GetOutputArray("COORDSOUT");
	weightOut	= GetOutputArray("WEIGHTOUT");
	stateOut	= GetOutputArray("STATEOUT");    
	
	incrementX = (int) (getX[1] - getX[0])/3;	
	incrementY = (int) (getY[1] - getY[0])/2; 
	x1 = (int) getX[0] + incrementX/2;
	x2 = (int) getX[0] + incrementX*1 + incrementX/2;
	x3 = (int) getX[0] + incrementX*2 + incrementX/2;
	y1 = (int) getY[0] + incrementY/2;
	y2 = (int) getY[0] + incrementY*1 + incrementY/2;
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
		if (demandAtt[0] == 1) {
			stateOut[0] = 4;
			switch ((int) region[0]) {
				case 1:
					coordsOut[0] = x1;
					coordsOut[1] = y1;
					coordsOut[2] = 2000;
					break;
				case 2:
					coordsOut[0] = x2;
					coordsOut[1] = y1;
					coordsOut[2] = 2000;
					break;
				case 3:
					coordsOut[0] = x3;
					coordsOut[1] = y1;
					coordsOut[2] = 2000;
					break;
				case 4:
					coordsOut[0] = x1;
					coordsOut[1] = y2;
					coordsOut[2] = 2000;
					break;
				case 5:
					coordsOut[0] = x2;
					coordsOut[1] = y2;
					coordsOut[2] = 2000;
					break;
				case 6:
					coordsOut[0] = x3;
					coordsOut[1] = y2;
					coordsOut[2] = 2000;
					break;
			}
		}
	} else if (stateIn[0] == 4) {
		weightOut[0] = 1;
		switch ((int) region[0]) {
			case 1:
				coordsOut[0] = x1;
				coordsOut[1] = y1;
				coordsOut[2] = 2000;
				break;
			case 2:
				coordsOut[0] = x2;
				coordsOut[1] = y1;
				coordsOut[2] = 2000;
				break;
			case 3:
				coordsOut[0] = x3;
				coordsOut[1] = y1;
				coordsOut[2] = 2000;
				break;
			case 4:
				coordsOut[0] = x1;
				coordsOut[1] = y2;
				coordsOut[2] = 2000;
				break;
			case 5:
				coordsOut[0] = x2;
				coordsOut[1] = y2;
				coordsOut[2] = 2000;
				break;
			case 6:
				coordsOut[0] = x3;
				coordsOut[1] = y2;
				coordsOut[2] = 2000;
				break;
		}
	} else {
		weightOut[0] = 0;
	}
}

// Install the module. This code is executed during start-up.
static InitClass init("small_MvmntDetChooser", &small_MvmntDetChooser::Create, "Source/UserModules/small_MvmntDetChooser/");


