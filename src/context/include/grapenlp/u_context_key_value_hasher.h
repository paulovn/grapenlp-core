/*
 * GRAPENLP
 *
 * Copyright (C) 2004-2019 Javier Miguel Sastre Martínez <javier.sastre@telefonica.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 *
 */

/*
 *  @author Javier Sastre
 */

#ifndef GRAPENLP_U_CONTEXT_ITEM_HASHER_H
#define GRAPENLP_U_CONTEXT_ITEM_HASHER_H

#include <grapenlp/unicode.h>
#include <grapenlp/context_key_value_hasher.h>

namespace grapenlp
{
    /**
     * A unichar key and value indexer used to optimize comparisons of context keys and values (these are reduced to
     * integer comparisons)
     */
    typedef context_key_value_hasher<unichar> u_context_key_value_hasher;
} //namespace grapenlp

#endif //GRAPENLP_U_CONTEXT_ITEM_HASHER_H
