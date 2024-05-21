#include "test.h"

float full_specialization()
{
	S<float> s;

	// S<float>::get() stub will be used, no template stubs is needed
	// as full specialization is not template class
	return s.get();
}

int template_stub_from_nontemplate()
{
	S<int> s(10);

	// S<int>::get() stub will be used:
	return s.get();
}

int template_stub_from_template()
{
	S<long> s(12);

	// S<long>::get() stub will be used in template 'get' function:
	return get(s);
}

int get_value()
{
	return 131;
}

int function_from_template()
{
	// get_value stub will be used (non-template function)
	get_value();
	// get_value stub will not be used in template get_nontemplate function
	// non-template stubs support is limited in template functions
	return get_nontemplate('a');
}

struct Post {
	int x = 12;
};

int unknown_type()
{
	// template stubs for instance with user-defined type which is defined/declared before
	// template class 'S' is.
	S<Pre> pre({13});
	// Class 'Post' is defined after template class 'S'. It is impossible to create template stub
	// Code will not compile. The only workaround is to move definition/declation before class 'S'
	S<Post> post({14});

	return pre.get().x + post.get().x;
}

