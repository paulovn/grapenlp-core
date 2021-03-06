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

/* context.i */
%module context
%include context.i
%{
#include <grapenlp/context.h>
%}

namespace grapenlp
{
    %nodefaultctor context;
    %nodefaultdtor context;
    template<typename CharT>
	class context
	{
    public:
        context(const context_key_value_hasher<CharT> &the_hasher_);

        template<typename KeyIterator, typename ValueIterator>
        void set(KeyIterator key_begin, KeyIterator key_end, ValueIterator value_begin, ValueIterator value_end);

        ~context();
	};
}
