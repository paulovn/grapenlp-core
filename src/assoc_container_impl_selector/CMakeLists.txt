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

project(assoc_container_impl_selector VERSION ${CHANGELOG_VERSION} LANGUAGES CXX)

add_library(assoc_container_impl_selector STATIC
        src/set_impl_selector.cpp
        src/map_impl_selector.cpp
        src/multiset_impl_selector.cpp
        src/multimap_impl_selector.cpp)
target_include_directories(assoc_container_impl_selector PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)
target_link_libraries(assoc_container_impl_selector
        lrb_tree
        )

install(TARGETS assoc_container_impl_selector EXPORT assoc_container_impl_selectorConfig
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/grapenlp COMPONENT libgrapenlpdev)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT libgrapenlpdev)
install(EXPORT assoc_container_impl_selectorConfig DESTINATION share/grapenlp/assoc_container_impl_selector/cmake COMPONENT libgrapenlpdev)
export(TARGETS assoc_container_impl_selector FILE assoc_container_impl_selectorConfig.cmake)