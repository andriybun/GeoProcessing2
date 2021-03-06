#pragma once

#include <cstdio>
#include <fstream>
#include <string>
//#include <boost/shared_ptr.hpp>

#include "assertInt.h"
#include "raster.h"
#include "SmartArray.h"

//const int MAX_READ_BUFFER_ELEMENTS	= 40 * 1024 * 1024;

class raster;

struct rasterBufT
{
	SmartArray<float> buf;
	float noDataValue;
	int nEl;
};

class BigFile
{
protected:
	bool isOpen;
	int numCells;
	int numCellsProcessed;
	float noDataValue;

	template<class fStreamT>
	void openBase(const raster &r, fStreamT* file, std::ios_base::openmode mode);
public:
	BigFile(void) {};
	virtual ~BigFile(void) = 0;
	virtual void open(const raster &r) = 0;
	void printProgress();
};

class BigFileIn : public BigFile
{
	std::ifstream file;
public:
	BigFileIn(void);
	BigFileIn(const raster &readRaster);
	~BigFileIn(void);
	void open(const raster &readRaster);
	int read(rasterBufT &rBuf);
	float read(int pos);
};

class BigFileOut : public BigFile
{
	std::ofstream file;
public:
	BigFileOut(void);
	BigFileOut(const raster &writeRaster);
	~BigFileOut(void);
	void open(const raster &writeRaster);
	void write(rasterBufT &rBuf);
};