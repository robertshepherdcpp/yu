#include"Size_t" // yu::Size_t


namespace yu
{
	struct String
	{
		String(const char* chars)
		{
			if (sizeof(chars) * sizeof(char) <= size)
			{
				size_used = sizeof(chars) * sizeof(char);
			}
			else if (sizeof(chars) * sizeof(char) > size)
			{
				size = sizeof(chars) * sizeof(char) + 5;
				arr = new char[size];
				size_used = size - 5;
			}
			str_ = chars
		}

		String()
		{
			str_ = {};
		}

		auto operator+=(char c)
		{
			if (size_used + 1 == size)
			{
				str_ = new char[size + 5];
			}
			else
			{
				str_[size] = c;
				size_used += 1;
			}
		}

		~String()
		{
			size = 0;
			size_used = 0;
			delete[] str_;
		}

		Size_t size_used = 5;
		Size_t size = 5;
		char str_[size];
	};
} // namespace yu