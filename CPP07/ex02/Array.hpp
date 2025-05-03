#ifndef ARRAY_HPP
# define ARRAY_HPP

		
template <typename T>
class Array{
	private:
		T* _arr;
		unsigned int _len;
	
	public:
		Array();
		Array(int n);
		Array(const Array &);
		~Array();
		T& operator[](unsigned int);
		const T& operator[](unsigned int) const;
		Array<T> &operator=(const Array &);
		unsigned int size(void) const;
};


template<typename T>
Array<T>::Array()
	:_arr(new T[0]), _len(0)
{}

template<typename T>
Array<T>::Array(int n)
	:_arr(new T[n]), _len(n)
{}

template<typename T>
Array<T>::Array(const Array &ref)
	:_arr(new T[ref.size()]), _len(ref.size())
{
	for (unsigned int i = 0; i < _len; i++)
		this->_arr[i] = ref[i];
}

template<typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _len)
		throw std::exception();
	return _arr[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _len)
		throw std::exception();
	return _arr[index];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &ref)
{
	delete[] _arr;
	_len = ref.size();
	_arr = new T[_len];
	for (unsigned int i = 0; i < _len; i++)
		this->_arr[i] = ref[i];
	return (*this);
}

template<typename T>
unsigned int Array<T>::size(void) const
{
	return _len;
}

#endif