/* $Id$ */
/*
   Copyright (C) 2007 - 2010 by Mark de Wever <koraq@xs4all.nl>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License version 2
   or at your option any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

/**
 *  @file src/settings.cpp
 *  General settings and defaults for scenarios.
 */

#include "global.hpp"

#include "settings.hpp"

#include "serialization/string_utils.hpp"
#include "util.hpp"

namespace settings {

int get_turns(const std::string& value)
{
	// Special case, -1 is also allowed, which means unlimited turns
	int val = lexical_cast_default<int>(value);

	if(val == -1) {
		return turns_max;
	}

	return lexical_cast_in_range<int>
		(value, turns_default, turns_min, turns_max);
}

int get_village_gold(const std::string& value)
{
	return lexical_cast_in_range<int>(value, 2, 1, 5);
}

int get_xp_modifier(const std::string& value)
{
	return lexical_cast_in_range<int>(value, 70, 30, 200);
}

bool use_fog(const std::string& value)
{
	return utils::string_bool(value, true);
}

bool use_random_start_time(const std::string& value)
{
	return utils::string_bool(value, true);
}

bool use_shroud(const std::string& value)
{
	return utils::string_bool(value, false);
}

} // end namespace settings
