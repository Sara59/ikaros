//
//	Kinect     This file is a part of the IKAROS project
//                 A module to grab images from Kinect
//
//    Copyright (C) 2016  Simon Holk
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

#ifndef ClosestPoint_
#define ClosestPoint_

#include "IKAROS.h"

class ClosestPoint: public Module {
public:
    // pointers to inputs and outputs
    // and integers to represent their sizes

    float **		depth;		
    int			depthX;
    int			depthY;
    bool 		connected;
    
    
    int			divider;

    float **		output;

    float *		inputState;
    float *		outputState;
    float *		value;

    static Module * Create(Parameter * p) {return new ClosestPoint(p);};
    
    ClosestPoint(Parameter * p) : Module(p) {};
    virtual ~ClosestPoint();

    void    Init();
    void    Tick();
};

#endif
