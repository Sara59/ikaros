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

#include "Splitter.h"

using namespace ikaros;

/*void
Splitter::SetSizes() {
	
}*/

void
Splitter::Init()
{
    getX			= GetInputArray("GETX"); 
	getY			= GetInputArray("GETY");
	changeMatrix	= GetInputMatrix("GETFACEMATRIX");
	
    mean1			= GetOutputArray("MEAN1");
	mean2			= GetOutputArray("MEAN2");
	mean3			= GetOutputArray("MEAN3");
	mean4			= GetOutputArray("MEAN4");
	mean5			= GetOutputArray("MEAN5");
	mean6			= GetOutputArray("MEAN6");
	
	incrementX = (int) (getX[1] - getX[0])/3;
	incrementY = (int) (getY[1] - getY[0])/2;   
}

Splitter::~Splitter() {}

void
Splitter::Tick()
{
	float m1[incrementX*incrementY];
	float m2[incrementX*incrementY];
	float m3[incrementX*incrementY];
	float m4[incrementX*incrementY];
	float m5[incrementX*incrementY];
	float m6[incrementX*incrementY];
	
	
	for (int i=0;i<incrementX;i++) { //splitting the changeMatrix into six different matrices
		for (int j=0;j<incrementY;j++) {
			m1[i*incrementX+j] = changeMatrix[i][j];
			m2[i*incrementX+j] = changeMatrix[i+incrementX][j];
			m3[i*incrementX+j] = changeMatrix[i+incrementX*2][j];
			m4[i*incrementX+j] = changeMatrix[i][j+incrementY];
			m5[i*incrementX+j] = changeMatrix[i+incrementX][j+incrementY];
			m6[i*incrementX+j] = changeMatrix[i+incrementX*2][j+incrementY];
		}
	}
	
	*mean1 = mean(m1, incrementX*incrementY); //calculation of means
	*mean2 = mean(m2, incrementX*incrementY);
	*mean3 = mean(m3, incrementX*incrementY);
	*mean4 = mean(m4, incrementX*incrementY);
	*mean5 = mean(m5, incrementX*incrementY);
	*mean6 = mean(m6, incrementX*incrementY);
	//float mean(float ** a, int sizex, int sizey);
}

// Install the module. This code is executed during start-up.
static InitClass init("Splitter", &Splitter::Create, "Source/UserModules/Splitter/");


