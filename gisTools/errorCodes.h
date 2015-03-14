#pragma once

enum errorT
{
INCORRECT_INPUT_PARAMS				= 10,
INPUT_RASTER_DOES_NOT_EXIST			= 11,
WRONG_EXTENT						= 12,
FILE_NOT_OPEN						= 13,
FILE_ALREADY_OPEN					= 14,
FLOAT_TO_RASTER_CONVERSION_ERROR	= 15,
RASTER_TO_FLOAT_CONVERSION_ERROR	= 16,
ARRAY_INDEX_OUT_OF_BOUNDS			= 17,
MEMORY_ALREADY_ALLOCATED			= 18,
WRONG_CSV_FILE						= 19,
WRONG_PROPERTIES_OF_RASTER			= 20,
ATTEMPT_TO_REINITIALIZE_RASTER		= 21,

OTHER_ERROR							= 99
};