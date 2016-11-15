//
//	GetXYZCoordinates.h		This file is a part of the IKAROS project
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

#ifndef GetXYZCoordinates_
#define GetXYZCoordinates_

#include "IKAROS.h"

class GetXYZCoordinates: public Module
{
public:
    static Module * Create(Parameter * p) { return new GetXYZCoordinates(p); }

    GetXYZCoordinates(Parameter * p) : Module(p) {}
    virtual ~GetXYZCoordinates();

    void 		Init();
    void 		Tick();

    // pointers to inputs and outputs
    // and integers to represent their sizes

    float **    xyinput;

    float **	depth;
    float       depth_size_x;
    float       depth_size_y;


    float*      outputX;
    float*      outputY;
    float**		outputmatrix;
    float**		facematrix;

    float*	state; 
    float* 	change_state;
    float*	value; 

    float	x;
    float	y;
    float	z;

    int		xcord;
    int 	ycord;
    int 	y0; 
    int 	x0; 

};

#endif
