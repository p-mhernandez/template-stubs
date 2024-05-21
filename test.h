#ifndef TEST_H_
#define TEST_H_

struct Pre {
	int x = 11;
};

template <typename T>
struct S
{
	S(const T& a): t(a) {}

	T get() const
	{
		return t;
	}

	T t;
};

template <>
struct S<float>
{
	float get() const
	{
		return 11.0;
	}
};

template <typename T>
T get(const S<T> s)
{
	return s.get();
}

int get_value();

template <typename T>
int get_nontemplate(T)
{
	return get_value();
}


#endif /* TEST_H_ */
