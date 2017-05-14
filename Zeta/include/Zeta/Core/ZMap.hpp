/*
 * ZMap.hpp
 *
 *  Created on: 30 Δεκ 2014
 *      Author: klapeto
 */

#ifndef ZETA_CORE_ZMAP_HPP_
#define ZETA_CORE_ZMAP_HPP_

#ifdef ZETA_NO_USE_HASHTABLES
#include <map>
#else
#include <unordered_map>
#endif

namespace Zeta {

#ifdef ZETA_NO_USE_HASHTABLES
template<typename Key, typename Value>
using ZMap = std::unordered_map<Key, Value>;
#else
template<typename Key, typename Value>
using ZMap = std::unordered_map<Key, Value>;
#endif

}  // namespace Zeta

#endif /* ZETA_CORE_ZMAP_HPP_ */
