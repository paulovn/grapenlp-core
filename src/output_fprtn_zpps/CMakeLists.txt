#
# GRAPENLP
#
# Copyright (C) 2004-2019 Javier Miguel Sastre Martínez <javier.sastre@telefonica.net>
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
#
#
#
#
# @author Javier Sastre
#

project(output_fprtn_zpps VERSION ${CHANGELOG_VERSION} LANGUAGES CXX)

add_library(output_fprtn_zpps STATIC
        src/output_fprtn_zpps.cpp
        src/a_output_fprtn_zpps.cpp
        src/ua_output_fprtn_zpps.cpp
        src/lua_output_fprtn_zpps.cpp
        src/aw_output_fprtn_zpps.cpp
        src/uaw_output_fprtn_zpps.cpp
        src/luaw_output_fprtn_zpps.cpp
        src/x_output_fprtn_zpps.cpp
        src/xw_output_fprtn_zpps.cpp
        src/ux_output_fprtn_zpps.cpp
        src/lux_output_fprtn_zpps.cpp
        src/uxw_output_fprtn_zpps.cpp
        src/luxw_output_fprtn_zpps.cpp
        )
target_include_directories(output_fprtn_zpps PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)
target_link_libraries(output_fprtn_zpps
        output_fprtn
        )

install(TARGETS output_fprtn_zpps EXPORT output_fprtn_zppsConfig
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/grapenlp COMPONENT libgrapenlpdev)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT libgrapenlpdev)
install(EXPORT output_fprtn_zppsConfig DESTINATION share/grapenlp/output_fprtn_zpps/cmake COMPONENT libgrapenlpdev)
export(TARGETS output_fprtn_zpps FILE output_fprtn_zppsConfig.cmake)
