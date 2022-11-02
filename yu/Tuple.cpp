// tuple.cpp 

// MIT License 2022 Robert Shepherd
#include"Size_t.cpp" // yu::size_t
#include"Global_vars.cpp" // yu::globals::tuple_count_g
#include"Errors.cpp" // errors::out_of_bounds_access_t


namespace yu
{

	template<typename T, typename... Ts>
	struct Tuple
	{
		T first;
		Tuple<Ts...> second;

		template<Size_t size>
		friend auto get(auto& t); // auto because cant pass in template parameters
	};

	template<typename T>
	struct Tuple<T>
	{
		T first;

		template<Size_t size>
		friend auto get(auto& t) // auto because cant pass in template parameters
	};

	template<Size_t size> // definition of Tuple<T>::get(auto& t);
	auto get(auto& t)
	{
		if (size == globals::tuple_count_g)
		{
			return t.first;
		}
		else
		{
			yu::globals::tuple_count_g++;
			if (t.second)
			{
				return get<size>(second);
			}
			else
			{
				throw Errors::out_of_bounds_access{"Trying to access index which is more than Tuple size.\n"};
			}
		}
	}
} // namespace yu
