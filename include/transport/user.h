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

#pragma once

#include <time.h>
#include "Swiften/Swiften.h"
#include "Swiften/Presence/PresenceOracle.h"
#include "Swiften/Disco/EntityCapsManager.h"

namespace Transport {

class Component;

// Representation of XMPP User
class User {
	public:
		User(const Swift::JID &jid, const std::string &username, const std::string &password, Component * component);
		virtual ~User();

		const Swift::JID &getJID();

		const char *getLang() { return "en"; }

	private:
		Swift::JID m_jid;
		Swift::Component *m_component;		
		Swift::EntityCapsManager *m_entityCapsManager;
		Swift::PresenceOracle *m_presenceOracle;
};

}
