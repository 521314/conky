/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*-
 * vim: ts=4 sw=4 noet ai cindent syntax=cpp
 *
 * Conky, a system monitor, based on torsmo
 *
 * Please see COPYING for details
 *
 * Copyright (C) 2010 Pavel Labath et al.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef UNICODE_HH
#define UNICODE_HH

#include <string>
#include <stdexcept>

#include <ext/codecvt_specializations.h>

class conversion_error: public std::runtime_error {
public:
	conversion_error(const char *charset)
		: std::runtime_error(std::string("Error converting to ") + charset)
	{}
};

class unicode_converter {
	typedef std::codecvt<char, char32_t, __gnu_cxx::encoding_state> codecvt;

	static std::locale locale;
	static const codecvt &converter;

	mutable __gnu_cxx::encoding_state state;

public:
	unicode_converter();	

	std::string to_utf8(const std::u32string &str) const;
	std::u32string to_utf32(const std::string &str) const;
};

#endif /* UNICODE_HH */
