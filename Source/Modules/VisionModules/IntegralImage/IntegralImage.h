//
//	IntegralImage.h		This file is a part of the IKAROS project
//						A module to caculate the integral image
//
//    Copyright (C) 2013  Christian Balkenius
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

#ifndef IntegralImage_
#define IntegralImage_

#include "IKAROS.h"



class IntegralImage: public Module
{
public:

    IntegralImage(Parameter * p) : Module(p) {};
    virtual ~IntegralImage() {}

    static Module * Create(Parameter * p) { return new IntegralImage(p); };

    void Init();
    void Tick();

    int		size_x;
    int		size_y;

    float **	input;
    float **	output;
};


#endif
