#include"Size_t.cpp"
#include"Initailizer_List.cpp"
#include"Errors.cpp"

namespace yu
{
	template<typename T>
	struct Vector
	{
		auto begin() { return arr_; } // return start of array
		auto end() { return arr_ + size_; } // return start of array + size

		auto size() { return size_; } // size and length are the same
		auto length() { return size_; }

		Vector(T t)
		{
			auto _ = arr;
			arr_ = new T[size + 1];
			for (int i = 0; i < size_; i++)
			{
				arr_[i] = _[i];
			}
			arr[size_] = t;
			size_ += 1;
		}

		Vector(Initailizer_List<T> list)
		{
			auto _ = arr_;
			arr_ = new T[list.size()];
			for (int i = 0; i < size_; i++)
			{
				arr[i] = _[i];
			}
			size_ = list.size();
			for (int i = 0; i < list.size(); i++)
			{
				arr_[i] = list[i];
			}
		}

		Vector(Vector<T>& v)
		{
			arr_ = new T[v.size()];
			for (int i = 0; i < v.size(); i++)
			{
				arr_[i] = v[i];
			}
		}

		Vector(Vector<T>&& v) 
		{
			arr_ = new T[v.size()];
			for (int i = 0; i < v.size(); i++)
			{
				arr_[i] = v[i];
			}
			v.size_ = 0;
			v.arr_ = nullptr;
		}

		auto push_back(T t)
		{
			auto _ = arr_;
			arr_ = new T[size_ + 1];
			for (int i = 0; i < size_; i++)
			{
				arr_[i] = _[i];
			}
			arr[size_] = t;
			
		}

		auto operator[](Size_t index)
		{
			if (index > size_)
			{
				throw Errors::out_of_bounds_access{ "Index entered is too high a number for arr_" };
			}
			return arr_[index];
		}

		auto operator=(Vector<T>&& v) // move assignment
		{
			arr_ = new T[v.size()];
			for (int i = 0; i < v.size(); i++)
			{
				arr_[i] = v[i];
			}
			v.size_ = 0;
			v.arr_ = nullptr;
		}

		auto operator=(Vector<T>& v)
		{
			arr_ = new T[v.size()];
			for (int i = 0; i < v.size(); i++)
			{
				arr_[i] = v[i];
			}
			return *this;
		}

		Size_t size_ = 0;
		T arr_[size_];
	};
} // namspace yu
