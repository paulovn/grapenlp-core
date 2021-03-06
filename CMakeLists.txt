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

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")
set(CMAKE_VERBOSE_MAKEFILE ON)

include(VersionFromChangelog)

set(CPACK_PACKAGE_NAME "grapenlp-core")
set(CPACK_PACKAGE_FILE_NAME "grapenlp-core-binary-${CHANGELOG_VERSION}")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "grapenlp-core-${CHANGELOG_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "GRAPENLP")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_HOME_DIRECTORY}/description.txt")
set(CPACK_PACKAGE_VERSION "${CHANGELOG_VERSION}")
set(CPACK_PACKAGE_VENDOR "GrapeNLP")
set(CPACK_PACKAGE_CONTACT "Javier Sastre <javier.sastre@telefonica.net>")
# Every file to install in this project belongs to a component; third party project files (e.g. GoogleTest) are to be
# used as build tools but are not to be packed along with this project files, so they are to be put in a "trash"
# component whose packaging is to be ommited
set(CMAKE_INSTALL_DEFAULT_COMPONENT_NAME "trash")
set(CPACK_SOURCE_IGNORE_FILES
    ${CPACK_SOURCE_IGNORE_FILES}
    "/test\\\\.txt"
    "/trace\\\\.txt"
    "/result\\\\.txt"
    "/grammar\\\\.dot"
    "/grammar\\\\.svg"
    "/dirty_parses\\\\.dot"
    "/dirty_parses\\\\.svg"
    "/inv_parses\\\\.dot"
    "/inv_parses\\\\.svg"
    "/parses\\\\.dot"
    "/parses\\\\.svg"
    "/Data/"
    "/build/"
    "/scripts/"
    "/\\\\.git/"
    "/\\\\.gitignore"
    "/\\\\.idea/"
    "/.*\\\\.iml"
    "/cmake-build-.*/"
    "/\\\\.travis.yml"
)

MESSAGE(STATUS "BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "CHANGELOG_VERSION: ${CHANGELOG_VERSION}")

if (NOT ANDROID_NDK_TOOLCHAIN_INCLUDED)
    # Enable testing for non-Android compilations
    # TODO: support running tests in Android continuous integration workflow by using some emulator (qemu?)
    include(CTest)
    MESSAGE(STATUS "BUILD_TESTING: ${BUILD_TESTING}")
endif (NOT ANDROID_NDK_TOOLCHAIN_INCLUDED)

add_subdirectory(src)
