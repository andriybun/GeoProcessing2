#include "tableT.h"

// tableT subclass:
tableT::tableT()
{
	sized = false;
}

tableT::tableT(size_t sz)
{
	setNumCols(sz);
}

tableT::~tableT()
{

}

void tableT::setNumCols(size_t n)
{
	ASSERT_INT(!sized, OTHER_ERROR);
	numCols = n;
	sized = true;
}

void tableT::insert(const int key, const std::vector<float> & val)
{
	ASSERT_INT(val.size() == numCols, OTHER_ERROR);
	data.insert(std::pair<int, std::vector<float>>(key, val));
}

void tableT::inc(const int key, const std::vector<float> & val)
{
	ASSERT_INT(val.size() == numCols, OTHER_ERROR);
	std::vector<float> tmp;
	tmp = data[key];
	for (size_t idx = 0; idx < numCols; idx++)
	{
		tmp[idx] += val[idx];
	}
	data.erase(key);
	data.insert(std::pair<int, std::vector<float>>(key, tmp));
}

void tableT::inc(const int key, const size_t idx, const float val)
{
	ASSERT_INT(idx < numCols + 1, OTHER_ERROR);
	std::vector<float> tmp = data[key];
	if (tmp.size() == 0)
	{
		tmp.resize(numCols);
	}
	tmp[idx-1] += val;
	data.erase(key);
	data.insert(std::pair<int, std::vector<float>>(key, tmp));
}

tableT::dataT::iterator tableT::find(const std::vector<float> & val)
{
	dataT::iterator it = data.begin();
	while (it != data.end())
	{
		if (std::equal(val.begin(), val.end(), it->second.begin())) return it;
		it++;
	}
	return it;
}

bool tableT::exists(const std::vector<float> & val)
{
	return find(val) != data.end();
}

size_t tableT::size()
{
	return data.size();
}
