/********************************************************************************************************************************************
 * grid
 * 
 * Copyright (C) 2020, Mahendra K. Verma
 *
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     1. Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *     2. Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *     3. Neither the name of the copyright holder nor the
 *        names of its contributors may be used to endorse or promote products
 *        derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ********************************************************************************************************************************************
 */

/*! \file main.cc
 *
 *  \brief test file for poisoon library
 *
 *  \author Ali Asad and Roshan Samuel
 *  \date Feb 2020
 *  \copyright New BSD License
 *
 ********************************************************************************************************************************************
 */

#include <grid.h>

int main()
{
    MPI_Init(NULL, NULL);

    blitz::Array<int, 1> gridInitInt(8);
    blitz::Array<real, 1> gridInitReal(6);
    
    int xIndex = 6;
    int yIndex = 6;
    int zIndex = 6;
    int xMesh = 0;
    int yMesh = 0;
    int zMesh = 0;
    int nopX = 2;
    int nopY = 2;

    real xL = 1.0;
    real yL = 1.0;
    real zL = 1.0;
    real btX = 1.0;
    real btY = 1.0;
    real btZ = 1.0;


    gridInitInt(0) = xIndex;
    gridInitInt(1) = yIndex;
    gridInitInt(2) = zIndex;
    gridInitInt(3) = xMesh;
    gridInitInt(4) = yMesh;
    gridInitInt(5) = zMesh;
    gridInitInt(6) = nopX;
    gridInitInt(7) = nopY;
    
    gridInitReal(0) = xL;
    gridInitReal(1) = yL;
    gridInitReal(2) = zL;
    gridInitReal(3) = btX;
    gridInitReal(4) = btY;
    gridInitReal(5) = btZ;
   
    
   /*****************************************************************************************************************************************
    * CALLING GRID LIBRARY
    *****************************************************************************************************************************************
   */ 
    grid grid_lib;
    grid_lib.Init(gridInitInt, gridInitReal);

    if (grid_lib.rank == 0) {
        std::cout << std::fixed << std::setw(6)  << std::setprecision(4) << grid_lib.zStaggr <<std::endl;

    }
    
    MPI_Finalize();
  	return 0;
}
