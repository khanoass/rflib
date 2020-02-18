#pragma once

#include <random>
#include <type_traits>

namespace rf
{
	//
	// Returns a psudo-random value of type T using the mt19937 generator in range min...max
	//
	template<typename T>
	inline T getRandomValue(T min, T max)
	{
		static std::mt19937 default_generator(std::random_device{}());
		if constexpr (std::is_integral_v<T>) {
			return std::uniform_int_distribution{min, max}(default_generator);
		} else if constexpr (std::is_floating_point_v<T>) {
			return std::uniform_real_distribution{min, max}(default_generator);
		}

		static_assert(0, "getRandomValue requires an arithmetic type");
		return min+max;
	}
}