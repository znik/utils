//
// Binary Maxheap Implementation
//
// Nick Zaborovskii, Aug-2014
//


#pragma once

#include <vector>


template<typename Type>
class Heap {

	std::vector<Type> _array;
	unsigned _size;

public:
	Heap(unsigned size) : _size(0) {
		_array.resize(size);
	};

	void add(const Type& entry) {
		if (_size == _array.size())
			_array.resize(2 * _array.size());

		_array[_size++] = entry;
		unsigned idx = _size - 1;
		while (0 != idx && _array[idx / 2] < _array[idx]) {
			std::swap(_array[idx / 2], _array[idx]);
			idx /= 2;
		}
	}

	Type get() {
		if (0 == _size)
			return 0; // + throw/return error
		Type ret = _array[0];
		_array[0] = _array[--_size];

		unsigned idx = 0;
		while(2 * idx + 1 < _size) {
			if (_array[idx] < _array[2 * idx + 1]) {
				std::swap(_array[idx], _array[2 * idx + 1]);
				idx = 2 * idx + 1;
			}
			else if (2 * idx + 2 < _size && _array[idx] < _array[2 * idx + 2]) {
				std::swap(_array[idx], _array[2 * idx + 2]);
				idx = 2 * idx + 2;
			}
			else
				break;
		}

		return ret;
	}

	Type max() const {
		return (0 == _array.size()) ? 0 : _array[0];
	}
};