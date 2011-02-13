/**
 * libtransport -- C++ library for easy XMPP Transports development
 *
 * Copyright (C) 2011, Jan Kaluza <hanzz.k@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */

#include "transport/config.h"
#include <fstream>

using namespace boost::program_options;

namespace Transport {
namespace Config {

bool load(const std::string &configfile, Variables &variables, boost::program_options::options_description &opts) {
	std::ifstream ifs(configfile.c_str());
	if (!ifs.is_open())
		return false;

	opts.add_options()
		("service.jid", value<std::string>(), "set compression level")
		("service.server", value<std::string>(), "set compression level")
		("service.password", value<std::string>(), "set compression level")
		("service.port", value<int>(), "set compression level")
		("database.database", value<std::string>(), "set compression level")
		("database.prefix", value<std::string>(), "set compression level")
	;


    store(parse_config_file(ifs, opts), variables);
	notify(variables);

	return true;
}

bool load(const std::string &configfile, Variables &variables) {
	options_description opts("Transport options");
	return load(configfile, variables, opts);
}

}
}
