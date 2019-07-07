#pragma once
#include <initializer_list>
#include <cstring>

template<typename Type>
class BIT
{
	int size;
	Type *data, *prefixSum;

	static constexpr int lowbit(int x) {
		return (x) & (-x);
	}

	void add(int pos, Type val) {
		while (pos < size) {
			prefixSum[pos] += val;
			pos += lowbit(pos);
		}
	}
public:
	Type prefix(int end) const {
		int sum = 0;
		++end;
		while (end > 0) {
			sum += prefixSum[end];
			end -= lowbit(end);
		}
		return sum;
	}

	Type sum(int start, int end) const {
		return prefix(end + 1) - prefix(start);
	}

	Type at(int pos) const {
		return data[pos + 1];
	}

	void change(int pos, Type val) {
		add(pos + 1, val - data[pos]);
		data[pos + 1] = val;
	}

	BIT(int size, const std::initializer_list<Type>& list) :
		size(size), data(new Type[size + 1]), prefixSum(new Type[size + 1])
	{
		memset(data, 0, sizeof(Type) * (size + 1));
		memset(prefixSum, 0, sizeof(Type) * (size + 1));
		int i = 1;
		for (const Type& arg : list) {
			add(i, data[i] = arg);
			++i;
		}
	}
	~BIT() { delete data, delete prefixSum; }
};

