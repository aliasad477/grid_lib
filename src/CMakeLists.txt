#############################################################################################################################################
 # grid
 # 
 # Copyright (C) 2020, Mahendra K. Verma
 #
 # All rights reserved.
 # 
 # Redistribution and use in source and binary forms, with or without
 # modification, are permitted provided that the following conditions are met:
 #     1. Redistributions of source code must retain the above copyright
 #        notice, this list of conditions and the following disclaimer.
 #     2. Redistributions in binary form must reproduce the above copyright
 #        notice, this list of conditions and the following disclaimer in the
 #        documentation and/or other materials provided with the distribution.
 #     3. Neither the name of the copyright holder nor the
 #        names of its contributors may be used to endorse or promote products
 #        derived from this software without specific prior written permission.
 # 
 # THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 # ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 # WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 # DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 # ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 # (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 # LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 # ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 # (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 # SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 #
 ############################################################################################################################################
 ##
 ##! \file CMakeLists.txt
 #
 #   \brief Root level CMakeLists file.
 #
 #   \author Ali Asad
 #   \date Feb 2020
 #   \copyright New BSD License
 #
 ############################################################################################################################################
##

ADD_LIBRARY(grid${LIB_SUFFIX}
	grid.cc
)


INSTALL(TARGETS grid${LIB_SUFFIX}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PRIVATE_HEADER DESTINATION include)

INSTALL(FILES grid.h
        DESTINATION include)


configure_file("pkgconfig/grid.pc.in" "pkgconfig/grid${LIB_SUFFIX}.pc" @ONLY)
install(FILES ${PROJECT_BINARY_DIR}/src/pkgconfig/grid${LIB_SUFFIX}.pc
        DESTINATION lib/pkgconfig)
