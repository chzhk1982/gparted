/* Copyright (C) 2010 Curtis Gedak
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */


/* Proc_Partitions_Info
 * 
 * A persistent cache of information from the file /proc/partitions
 * that helps to minimize the number of required disk reads.
 */

#ifndef GPARTED_PROC_PARTITIONS_INFO_H
#define GPARTED_PROC_PARTITIONS_INFO_H

#include "../include/Utils.h"

namespace GParted
{

class Proc_Partitions_Info
{
public:
	Proc_Partitions_Info() ;
	Proc_Partitions_Info( bool do_refresh ) ;
	~Proc_Partitions_Info() ;
	std::vector<Glib::ustring> get_device_paths() ;
	std::vector<Glib::ustring> get_alternate_paths( const Glib::ustring & path ) ;
private:
	void load_proc_partitions_info_cache() ;
	static bool proc_partitions_info_cache_initialized ;
	static std::vector<Glib::ustring> device_paths_cache ;
	static std::map< Glib::ustring, Glib::ustring > alternate_paths_cache ;
};

}//GParted

#endif /* GPARTED_PROC_PARTITIONS_INFO_H */
