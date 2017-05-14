/*
 * ZSmallMap.hpp
 *
 *  Created on: 30 Δεκ 2014
 *      Author: klapeto
 */

#ifndef ZETA_CORE_ZSMALLMAP_HPP_
#define ZETA_CORE_ZSMALLMAP_HPP_

#include <map>

namespace Zeta {

template<typename Key, typename Value>
using ZSmallMap = std::map<Key, Value>;

}  // namespace Zeta

#endif /* ZETA_CORE_ZSMALLMAP_HPP_ */
