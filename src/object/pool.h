/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author      ruki
 * @file        object_pool.h
 * @ingroup     object
 *
 */
#ifndef TB_MEMORY_OBJECT_POOL_H
#define TB_MEMORY_OBJECT_POOL_H

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_enter__

/* //////////////////////////////////////////////////////////////////////////////////////
 * macros
 */
#define tb_object_pool_get(pool, size, flag, type)      tb_object_pool_get_(pool, size, flag, type __tb_debug_vals__)
#define tb_object_pool_del(pool, object)                tb_object_pool_del_(pool, object __tb_debug_vals__)

/* //////////////////////////////////////////////////////////////////////////////////////
 * types
 */

/// the object pool ref type
typedef struct{}*       tb_object_pool_ref_t;

/* //////////////////////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! the object pool instance
 *
 * @return              the object pool
 */
tb_object_pool_ref_t    tb_object_pool(tb_noarg_t);

/*! init object pool
 *
 * @return              the object pool
 */
tb_object_pool_ref_t    tb_object_pool_init(tb_noarg_t);

/*! exit object pool
 *
 * @param pool          the object pool
 */
tb_void_t               tb_object_pool_exit(tb_object_pool_ref_t pool);

/*! exit object pool
 *
 * @param pool          the object pool
 */
tb_void_t               tb_object_pool_clear(tb_object_pool_ref_t pool);

/*! get object from object_pool
 *
 * @param pool          the object pool
 * @param size          the object size
 * @param flag          the object flag
 * @param type          the object type
 *
 * @return              the object pointer
 */
tb_object_ref_t         tb_object_pool_get_(tb_object_pool_ref_t pool, tb_size_t size, tb_size_t flag, tb_size_t type __tb_debug_decl__);

/*! del object from object_pool
 *
 * @param pool          the object pool
 * @param object        the object pointer
 */
tb_void_t               tb_object_pool_del_(tb_object_pool_ref_t pool, tb_object_ref_t object __tb_debug_decl__);

#ifdef __tb_debug__
/*! dump object pool
 *
 * @param pool          the object pool
 */
tb_void_t               tb_object_pool_dump(tb_object_pool_ref_t pool);
#endif

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_leave__

#endif