/*
 * ZSet.hpp
 *
 *  Created on: 30 Δεκ 2014
 *      Author: klapeto
 */

#ifndef ZETA_CORE_ZSET_HPP_
#define ZETA_CORE_ZSET_HPP_

#ifdef ZETA_NO_USE_HASHTABLES
#include <set>
#else
#include <unordered_set>
#endif

namespace Zeta {

#ifdef ZETA_NO_USE_HASHTABLES
template<typename Key>
using ZSet = std::set<Key>;
#else
template<typename Key>
using ZSet = std::unordered_set<Key>;
#endif

}  // namespace Zeta

#endif /* ZETA_CORE_ZSET_HPP_ */
